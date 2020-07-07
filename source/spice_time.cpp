#include "spice_time.hpp"

// Load spice headers in platform independent way
extern "C"
{
    #if defined(__linux__)
        #include "linux/SpiceZpl.h"    
    #elif defined(__CYGWIN__)
        #include "cygwin/SpiceZpl.h"    
    #elif defined(_MSC_VER)
        #include "msvc/SpiceZpl.h"
    #elif defined(__APPLE__)
        #include "mac/SpiceZpl.h"
    #endif

    #include "SpiceZdf.h"   
    #include "SpiceErr.h"
    #include "SpiceEK.h"
    #include "SpiceFrm.h"
    #include "SpiceCel.h"
    #include "SpiceCK.h"
    #include "SpiceSPK.h"
    #include "SpiceGF.h"
    #include "SpiceOccult.h"
    #include "SpiceZpr.h"
    #include "SpiceZim.h"
}

double Spice::Date2Epoch(const std::string& Date)
{
    SpiceDouble EpochTime = 0.0;     
    str2et_c(Date.data(), &EpochTime);
    return EpochTime;
}

std::string Spice::Epoch2TDB(double EpochTime)
{
    constexpr SpiceInt TIMESTRING_LENGTH = 51;    

    SpiceChar TimeChar[TIMESTRING_LENGTH];
    timout_c(EpochTime,
        "YYYY MON DD HR:MN:SC.### (TDB) ::TDB",
        TIMESTRING_LENGTH,
        TimeChar);
    
    return std::string(TimeChar);
}