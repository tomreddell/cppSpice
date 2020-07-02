#pragma once

#include <string>

namespace Spice
{
    /* 
    * Gets the error thrown by Spice as a string,
    * resets the internal error state
    */
    std::string GetErrorAndReset(void) noexcept;
}