#include "blaze/posix/thread.hh"

namespace blaze
{
  namespace posix
  {
    PThread::PThread(std::function<void ()> fn)
      :thread_(fn)
    {}

    PThread::~PThread()
    {
      if (thread_.joinable())
        thread_.join();
    }

    void PThread::SetAffinity(int cpu)
    {
      
    }


  }
}