#pragma once

#include <cstddef>
#include <functional>
#include <memory>

#include <csetjmp>
#include <ucontext.h>

namespace blaze
{
  namespace concur
  {

    class Thread;

    struct ThreadAttributes
    {
      int stack_size;
    };

    /**
     * @brief This is the thread context.
     * 
     */
    class ThreadContext
    {
    private:
      const std::unique_ptr<ucontext_t> ucontext_;
      std::jmp_buf jmpbuf_;
      std::unique_ptr<char[]> stack_;
      const unsigned int stack_size_;

      /**
       * @brief Initializes the Thread Context to point to the passed thread.
       * 
       * @details This function prepares the thread context to be switched in. The 
       * function takes in the thread and initializes the os context to point to the main
       * method in the thread, prepares the stack and other os specific structures so 
       * that the context switch can happen.
       * 
       * Please note that this method should not be invoked more than once on the object.
       * Multiple invocations will lead to unknown results and cause error.
       * 
       * @param thread 
       */
      void init(Thread* thread);

      /**
       * @brief First context switch for this thread.
       * 
       */
      void initial_switch_in();

      void final_switch_out();

      /**
       * @brief The static function that the context points to.
       * 
       * @param hi High 32bits of the object address
       * @param lo Lower 32bits of the object address
       */
      static void s_main(int hi, int lo);
    public:
      ThreadContext(int stack_size);

      friend class Thread;
    };

    /**
     * @brief concur::Thread are lightweight thread/fiber implemented in Blaze. These are
     * not the same as OS thread. concur::Thread is the unit of concurrency in blaze and
     * are scheduled to run on OS thread. concur::Thread are scheduled co operatively and
     * are not pre emptied unless a blocking operation is initiated or they explicitly 
     * yield control.
     */
    class Thread
    {
    private:
      std::unique_ptr<ThreadContext> context_;
      std::function<void ()> func_;

      /**
       * @brief this is the main function that runs the logic on the os threads.
       * 
       */
      void main();

    public:

      Thread(std::function<void ()> func, ThreadAttributes & attrs);

      void Start();

      friend class ThreadContext;
    };

  }
} // namespace blaze