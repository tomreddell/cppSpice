#include "spice_ephemeris.hpp"

#include <vector>
#include <cstdio>

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

Spice::EphemerisState Spice::CalcEphemerisState(const EphemerisInputs& Inputs, double EpochTime)
{
    std::vector<SpiceDouble> Buffer(6);
    SpiceDouble LightTimeSeconds = 0.0;

    // Update ephemeris at the given epoch time using spice
    spkezr_c(Inputs.Object.data(), 
             EpochTime, 
             Inputs.Frame.data(), 
             Inputs.Aberration.data(),
             Inputs.Reference.data(),
             Buffer.data(), 
             &LightTimeSeconds);

    // Calculation failure
    if (failed_c() == true)             
    {
        return EphemerisState{.CalculationSuccess = false};
    }

    // Return in a more modern format
    return EphemerisState{
        .PosX = Buffer[0], 
        .PosY = Buffer[1], 
        .PosZ = Buffer[2],
        .VelX = Buffer[3], 
        .VelY = Buffer[4], 
        .VelZ = Buffer[5],
        .LightTime = LightTimeSeconds,
        .CalculationSuccess = true
    }; 
}