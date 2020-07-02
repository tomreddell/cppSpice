#include "spice_kernel_set.hpp"
#include "spice_time.hpp"
#include "spice_error.hpp"

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

// Weird archaic C magic
constexpr size_t MAX_OBJECTS = 1024;
constexpr size_t MAX_WINDOW_SIZE = 2000;

SPICEINT_CELL (SpiceIDs, MAX_OBJECTS);
SPICEDOUBLE_CELL (Coverage, MAX_WINDOW_SIZE);

std::string Spice::ObjectMetadata::PrettyString(void) const noexcept
{
    std::string Result = "Spice Object: " + std::to_string(ID) 
        + " Loaded in Kernel " + Kernel + "\n";
    
    Result += "*** Coverage Summary ***\n";
    for (size_t Index = 0; Index < Intervals.size(); ++Index)
    {
        Result += "Interval: " + std::to_string(Index) + "\n";
        Result += "Start: " + Epoch2TDB(Intervals[Index].Start) + "\n";
        Result += "Stop: " + Epoch2TDB(Intervals[Index].Stop) + "\n\n";
    }

    return Result;
}

Spice::KernelSet::KernelSet(void) noexcept
{
    if (sNoAbortFlagSet == false)    
    {
        // Disable abort on error
        SpiceChar ErrorMode[] = "RETURN";
        erract_c("SET", sizeof(ErrorMode), ErrorMode);
        sNoAbortFlagSet = true;
    }
}

bool Spice::KernelSet::LoadEphemeris(const std::string& Kernel) noexcept
{
    // Loads Kernel    
    furnsh_c(Kernel.data());

    if (failed_c() == true)    
    {
        mErrorLog.push_back(GetErrorAndReset());
        return false;
    }

    // Store kernal ID
    mKernels.push_back(Kernel);    

    // Introspect contents
    spkobj_c(Kernel.data(), &SpiceIDs);

    if (failed_c() == true)    
    {
        mErrorLog.push_back(GetErrorAndReset());
        return false;
    }    

    for (SpiceInt Index = 0; Index < card_c(&SpiceIDs); ++Index)
    {
        ObjectMetadata Meta;
        Meta.Kernel = Kernel;

        // Loads the object ID
        Meta.ID = SPICE_CELL_ELEM_I(&SpiceIDs, Index);

        // "Set Cardinality" of coverage, i.e clear it
        scard_c(0, &Coverage);

        // Find coverage window
        spkcov_c(Kernel.data(), Meta.ID, &Coverage);

        // Loop through each interval and get the endpoints in the reference epoch
        for (SpiceInt Interval = 0; Interval < wncard_c(&Coverage); ++Interval)
        {
            SpiceDouble Start, Stop;

            // Get start and stop times of this interval and store                        
            wnfetd_c(&Coverage, Interval, &Start, &Stop);
            Meta.Intervals.emplace_back(TimeInterval {.Start = Start, .Stop = Stop});
        }

        // Store this object metadata
        mMeta.insert(std::make_pair(Meta.ID, std::move(Meta)));
    }  

    if (failed_c() == true)    
    {
        mErrorLog.push_back(GetErrorAndReset());
        return false;
    }        

    return true;
}

bool Spice::KernelSet::LoadAuxillary(const std::string& Kernel) noexcept
{
    // Loads Kernel    
    furnsh_c(Kernel.data());

    if (failed_c() == true)    
    {
        mErrorLog.push_back(GetErrorAndReset());
        return false;
    }      

    return true;
}

Spice::KernelSet::~KernelSet() noexcept
{
    UnsetErrorFlag();
    UnloadAll();

    // Display any error messages which triggered on unloading
    for (const auto& Message : mErrorLog)    
    {
        puts(Message.data());
    }    
}

void Spice::KernelSet::UnloadAll(void) noexcept
{
    for(const auto& Kernel : mKernels)
    {
        unload_c(Kernel.data());

        if (failed_c() == true)    
        {
            mErrorLog.push_back(GetErrorAndReset());
        }      
    }
}

void Spice::KernelSet::UnsetErrorFlag(void) noexcept
{
    mErrorLog.clear();
}

bool Spice::KernelSet::sNoAbortFlagSet = false;