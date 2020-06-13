#include "blaze/concur/scheduler.hh"

namespace blaze
{
  namespace concur
  {
    thread_local Scheduler scheduler_;
    thread_local ThreadContext ctx_before_thread_{0};

    Scheduler& scheduler()
    {
      return scheduler_;
    }
  }
}
