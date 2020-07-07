#pragma once

#include <string>

namespace Spice
{
    /*
     * Converts a date string to seconds in the current epoch
     */
    double Date2Epoch(const std::string& Date);

    /* Converts an epoch time to a TDB date */
    std::string Epoch2TDB(double EpochTime);
}