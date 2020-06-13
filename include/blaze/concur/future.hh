#pragma once

#include <exception>

namespace blaze
{
  namespace concur
  {
    template<typename T>
    class Future
    {
    public:
      T&& get_value();

      bool has_value();

      std::exception get_error();

      bool has_error();
    };

    template<typename T>
    class Promise
    {
    public:
      void set_value(T&& value);

      T&& get_value();

      bool has_value();

      std::exception get_error();

      bool has_error();
    };
  }
}
