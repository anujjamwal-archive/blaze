#pragma once

#include <vector>
#include "blaze/operation/base_operation.hh"

namespace blaze
{
  namespace operation
  {
    /**
     * @brief Operation to read the data from one or more files.
     * 
     */
    class FileScanOperation : BaseOperation
    {
    private:
      std::vector<std::string> _paths;
      std::vector<std::string> _field_selection;
    public:
      std::string ToString();
    };
  } // namespace operation
} // namespace blaze