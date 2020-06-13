#pragma once

#include <string>

namespace blaze
{
  namespace operation
  {
    /**
     * @brief Base class for all Operation.
     * 
     * An Operation is the base of all work done by blaze. It represents individual
     * operations to be performed by the engine. An operation must have an id, name
     * and a set of children that this operation depends upon.
     * 
     */
    class BaseOperation
    {
    public:
      virtual std::string ToString() = 0;
    };
  } // namespace operation
} // namespace blaze