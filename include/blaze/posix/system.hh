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
    class System
    {
    public:
      int GetCpus();
    };
  } // namespace posix
} // namespace blaze