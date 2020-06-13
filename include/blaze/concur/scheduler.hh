#pragma once

#include <vector>
#include "blaze/concur/thread.hh"

namespace blaze
{
  namespace concur
  {
    class Scheduler
    {
    private:
      std::vector<Thread *> _all_threads;
      int _current_thread_idx;

    public:
      
    };

    Scheduler& scheduler();
  } // namespace concur
} // namespace blaze
