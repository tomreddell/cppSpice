#pragma once

#include <string>

namespace Spice
{
    /* 
     * Outputs of Spice spkezr_c calculation
     */
    struct EphemerisState
    {
        // Relative X Position (km)
        double PosX = 0.0;

        // Relative Y Position (km)
        double PosY = 0.0;

        // Relative Z Position (km)
        double PosZ = 0.0;

        // Relative X Velocity (km/s)
        double VelX = 0.0;

        // Relative Y Velocity (km/s)
        double VelY = 0.0;

        // Relative Z Velocity (km/s)
        double VelZ = 0.0;

        // Time taken for light to travel between source object and reference (s)        
        double LightTime = 0.0;

        // Calculation completed successfully (true/false)
        bool CalculationSuccess = false;        
    };

    /* 
     * Input fields to a spice ephemeris calculation
     */
    struct EphemerisInputs
    {
        // Target object    
        std::string Object = "INVALID";

        // Reference epoch        
        std::string Frame = "J2000";

        // Reference (viewing) object         
        std::string Reference = "INVALID";

        // Aberration Correction Model
        std::string Aberration = "NONE";
    };

    /*
     * Functional interface to the Spice Ephemeris calculation routine
     */
    EphemerisState CalcEphemerisState(const EphemerisInputs& Inputs, double EpochTime);
}