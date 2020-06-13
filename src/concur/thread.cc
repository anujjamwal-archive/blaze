#include <cstdint>
#include <iostream>
#include <memory>
#include "blaze/concur/thread.hh"

namespace blaze
{
  namespace concur
  {
    // Value should be setup by scheduler
    extern thread_local ThreadContext ctx_before_thread_;
    thread_local ThreadContext *current_ctx = &ctx_before_thread_;

    ThreadContext::ThreadContext(int stack_size) : ucontext_(std::make_unique<ucontext_t>()),
                                                   stack_(std::make_unique<char[]>(stack_size)),
                                                   stack_size_(stack_size)
    {
    }

    void ThreadContext::s_main(int lo, int hi)
    {
      uintptr_t q = uint64_t(uint32_t(lo)) | uint64_t(hi) << 32;
      reinterpret_cast<Thread *>(q)->main();
    }

    void ThreadContext::init(Thread *thread)
    {
      auto main = reinterpret_cast<void (*)()>(&ThreadContext::s_main);
      auto q = uint64_t(reinterpret_cast<uintptr_t>(thread));
      auto r = getcontext(this->ucontext_.get());
      //Todo: Check the return value of r
      this->ucontext_->uc_link = nullptr;
      this->ucontext_->uc_stack.ss_sp = this->stack_.get();
      this->ucontext_->uc_stack.ss_size = this->stack_size_;

      makecontext(this->ucontext_.get(), main, 2, int(q), int(q >> 32));
    }

    void ThreadContext::initial_switch_in()
    {
      auto prev = std::exchange(current_ctx, this);

      if (setjmp(prev->jmpbuf_) == 0)
      {
        setcontext(this->ucontext_.get());
      }
    }

    void ThreadContext::final_switch_out()
    {
      current_ctx = &ctx_before_thread_;

      longjmp(current_ctx->jmpbuf_, 1);
    }

    Thread::Thread(std::function<void()> func, ThreadAttributes &attrs) : context_(std::make_unique<ThreadContext>(attrs.stack_size)),
                                                                          func_(func)
    {
      this->context_->init(this);
    }

    void Thread::main()
    {
      #ifdef __x86_64__
        asm(".cfi_undefined rip");
      #endif

      try
      {
      this->func_();
      } catch (...)
      {
        std::cerr << "Failed " << std::endl;
      }

      this->context_->final_switch_out();
    }

    void Thread::Start()
    {
      this->context_->initial_switch_in();
    }
  } // namespace concur
} // namespace blaze