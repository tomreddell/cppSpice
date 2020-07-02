#pragma once

#include <string>

namespace Spice
{
    /* 
    * Gets the error thrown by Spice as a string, clears
    * resets the internal error state
    */
    std::string GetErrorAndReset(void) noexcept;
}