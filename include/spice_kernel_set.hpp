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
        // Interval start time (s)    
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
        std::string_view Kernel;

        // Unique spice object integer ID
        int ID = std::numeric_limits<int>::min();

        // List of time intervals        
        std::vector<TimeInterval> Intervals;

        // Get the metadata as a pretty formatted string
        std::string PrettyString(void) const;        
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
        KernelSet();
        
        // Unload all when the kernel set goes out of scope
        ~KernelSet();
        
        // Disable Copy Constructor
        KernelSet(const KernelSet& Other) = delete;

        // Loads a spice kernel
        bool Load(const std::string& Kernel);

        // Get a reference to the contained metadata
        const std::map<int, ObjectMetadata>& GetMetadata(void) const {return mMeta;}
        
    private:
        // A list of all kernel files loaded
        std::vector<std::string_view> mKernels;

        // All object metadata
        std::map<int, ObjectMetadata> mMeta;
    };
}