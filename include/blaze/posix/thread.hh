#pragma once

// c++ standard headers
#include <functional>
#include <memory>
#include <thread>
// C headers
#include <pthread.h>

namespace blaze
{
  /**
   * @brief The namespace provides the glue code for underlying posix code with C++.
   * 
   */
  namespace posix
  {
    class PThread
    {
    private:
      std::thread thread_;

    public:
      PThread(std::function<void()> func);
      ~PThread();

    public:
      /**
       * @brief Set the cpu affinity for the Thread.
       * 
       * @param cpu the cpu id to set the affinity
       */
      void SetAffinity(int cpu);
    };
  } // namespace posix
} // namespace blaze