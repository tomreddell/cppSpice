#pragma once

#include <vector>
#include <map>
#include <string>

namespace Spice
{    
    /* 
     * Stores an ephemeris time interval 
     * endpoints are given in seconds relative to the reference epoch
     */
    struct TimeInterval
    {
         
        double Start = 0.0;

        // Interval stop time (s)
        double Stop = 0.0;
    };

    /* 
     * Stores the metadata of a spice object
     */
    struct ObjectMetadata
    {
        // Spice Kernel from which this object was loaded
        std::string Kernel;

        // Unique spice object integer ID
        int ID = std::numeric_limits<int>::min();

        // List of time intervals        
        std::vector<TimeInterval> Intervals;

        // Get the metadata as a pretty formatted string
        std::string PrettyString(void) const noexcept;        
    };

    /* 
    * Scoped loading, unloading of Spice Kernels
    * 
    * Also stores the metadata in a more accesible format than the default c interface
    */
    class KernelSet
    {
    public:    
        // Default Constructor
        KernelSet(void) noexcept;
        
        // Unload all when the kernel set goes out of scope
        ~KernelSet(void) noexcept;
        
        // Disable Copy Constructor
        KernelSet(const KernelSet& Other) = delete;

        // Loads a spice ephemeris kernel (.bsp)
        bool LoadEphemeris(const std::string& Kernel) noexcept;

        // Loads a non .bsp spice kernel
        bool LoadAuxillary(const std::string& Kernel) noexcept;

        // Get a reference to the contained metadata
        const std::map<int, ObjectMetadata>& GetMetadata(void) const noexcept {return mMeta;}

        // Unloads all stored kernels
        void UnloadAll(void) noexcept;

        // Returns true if one or more errors have been thrown
        bool HasFailed(void) const noexcept {return (mErrorLog.size() > 0);}

        // Gets a list of all thrown errors
        const std::vector<std::string>& GetErrorLog(void) const noexcept {return mErrorLog;}

        // Clears the error log and resets the spice error state
        void UnsetErrorFlag(void) noexcept;
        
    private:
        // A list of all kernel files loaded
        std::vector<std::string> mKernels;

        // All object metadata
        std::map<int, ObjectMetadata> mMeta;       

        // List of thrown errors
        std::vector<std::string> mErrorLog;        

        // Global flag indicating spice error reporting status   
        static bool sNoAbortFlagSet;
    };
}