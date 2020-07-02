#include "spice_error.hpp"

#include <vector>

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

// Current maximum length of an error message according to spice
// documentation
constexpr size_t MaxErrorLength = 1840;

std::string Spice::GetErrorAndReset(void) noexcept
{
    if (failed_c() == false)    
    {
        return "";
    }

    std::vector<char> Message(MaxErrorLength, 0);
    getmsg_c("LONG", static_cast<int>(Message.size()), Message.data());
    reset_c();
    return std::string(Message.data());
}