# CppSpice
Unofficial C++ wrapper around JPL's NAIF's SPICE. This project is based upon the unofficial C OpenSpace/Spice github distribution of Spice. Implemented in C++20

Compared to the raw C interface, CppSpice uses standard C++ types and a more modern interface.

#### JPL NAIF Spice
https://naif.jpl.nasa.gov/naif/

#### OpenSpace/Spice
https://github.com/OpenSpace/Spice

## Building as a Library
CppSpice can be built as a static or shared library , or added as a sub-directory using cmake.

## Getting Started

```c++
// main.cpp

// In order to run this example, you will need to download
// a leap seconds kernel, and ephemeris kernel from the naif database
// and modify the paths in the Kernal.Load method call to point to these
// data files
//
// A leap seconds Kernel which was accurate as of July 2020 can be found here:
// https://naif.jpl.nasa.gov/pub/naif/generic_kernels/lsk/
// use naif0012.tls on Unix or naif0012.tls.pc on Windows
//
// An ephemeris containing major bodies and suitable for running the below
// code can be found here:
// https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/planets/
// use de430.bsp

#include "spice_label_map.hpp"
#include "spice_kernel_set.hpp"
#include "spice_time.hpp"
#include "spice_ephemeris.hpp"  
#include "spice_error.hpp"

using namespace Spice;    

int main()
{
    // Create a class which keeps track of loaded kernels    
    // kernels will be unloaded once this instance goes out of scope
    KernelSet Kernels{};
    Kernels.LoadAuxillary("path/to/naif0012.tls"); // Load naif0012.tls
    Kernels.LoadEphemeris("path/to/de430.bsp");    // Load de430.bsp
    
    // Display any thrown errors and exit
    if (Kernels.HasFailed() == true)
    {
        for (const auto& Message : Kernels.GetErrorLog())
        {
            puts(Message.data());
            return 1;
        }
    }

    // Display contents
    for (const auto& Meta : Kernels.GetMetadata())        
    {
        puts(Meta.second.PrettyString().c_str());
    }

    // Define some "constant" inputs to an ephemeris calculation
    EphemerisInputs Inputs = EphemerisInputs{
        .Object = GetObjectString(ObjectID::MOON),
        .Frame = GetFrameString(FrameID::J2000),
        .Reference = GetObjectString(ObjectID::EARTH),
        .Aberration = GetAbCorrectionString(AbCorrectionID::NONE)
    };

    // Convert a date to an epoch time
    // Refer to the Spice str2et_c documentation for a description of
    // valid string inputs
    double EpochTime = Date2Epoch("2024 June 10, 13:00:00 PST");

    // Calculate the ephemeris of the moon, relative to the centre of the earth in the J2000
    // reference frame
    EphemerisState LunarState = CalcEphemerisState(Inputs, EpochTime);
    
    // Catch any errors from a failed calculation
    if (LunarState.CalculationSuccess == false)
    {
        puts(GetErrorAndReset().c_str());
        return 1;
    }

    printf("Lunar Position (km) = (%g, %g, %g)\n", 
        LunarState.PosX, 
        LunarState.PosY,
        LunarState.PosZ);

    printf("Lunar Velocity (km/s) = (%g, %g, %g)\n",
        LunarState.VelX,
        LunarState.VelY,
        LunarState.VelZ
    );        

    printf("Light Second Delay = %g\n", LunarState.LightTime);
        
    return 0;
}
```

## API Implemented
Currently only a subset of the Spice API is implemented.
