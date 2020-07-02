#include "spice_label_map.hpp"

#include <cstdio>

std::string Spice::GetObjectString(ObjectID ID)
{
    switch (ID)
    {   
        case ObjectID::INTERNATIONAL_SPACE_STATION : return "-125544";     
        case ObjectID::GATEWAY                     : return "-60000";
        case ObjectID::SOLAR_SYSTEM_BARYCENTRE     : return "0";
        case ObjectID::MERCURY_BARYCENTRE          : return "1";
        case ObjectID::VENUS_BARYCENTRE            : return "2";
        case ObjectID::EARTH_BARYCENTRE            : return "3";
        case ObjectID::MARS_BARYCENTRE             : return "4";
        case ObjectID::JUPITER_BARYCENTRE          : return "5";
        case ObjectID::SATURN_BARYCENTRE           : return "6";
        case ObjectID::URANUS_BARYCENTRE           : return "7";
        case ObjectID::NEPTUNE_BARYCENTRE          : return "8";
        case ObjectID::PLUTO_BARYCENTRE            : return "9";
        case ObjectID::SUN                         : return "10";
        case ObjectID::MERCURY                     : return "199";
        case ObjectID::VENUS                       : return "299";
        case ObjectID::MOON                        : return "301";
        case ObjectID::EARTH                       : return "399";
        case ObjectID::PHOBOS                      : return "401";
        case ObjectID::DEIMOS                      : return "402";
        case ObjectID::MARS                        : return "499";
        case ObjectID::IO                          : return "501";
        case ObjectID::EUROPA                      : return "502";
        case ObjectID::GANYMEDE                    : return "503";
        case ObjectID::CALLISTO                    : return "504";
        case ObjectID::AMALTHEA                    : return "505";
        case ObjectID::HIMALIA                     : return "506";
        case ObjectID::ELARA                       : return "507";
        case ObjectID::PASIPHAE                    : return "508";
        case ObjectID::SINOPE                      : return "509";
        case ObjectID::LYSITHEA                    : return "510";
        case ObjectID::CARME                       : return "511";
        case ObjectID::ANANKE                      : return "512";
        case ObjectID::LEDA                        : return "513";
        case ObjectID::THEBE                       : return "514";
        case ObjectID::ADRASTEA                    : return "515";
        case ObjectID::METIS                       : return "516";
        case ObjectID::CALLIRHRHOE                 : return "517";
        case ObjectID::THEMISTO                    : return "518";
        case ObjectID::MAGACLITE                   : return "519";
        case ObjectID::TAYGETE                     : return "520";
        case ObjectID::CHALDENE                    : return "521";
        case ObjectID::HARPALYKE                   : return "522";
        case ObjectID::KALYKE                      : return "523";
        case ObjectID::IOCASTE                     : return "524";
        case ObjectID::ERINOME                     : return "525";
        case ObjectID::ISONOE                      : return "526";
        case ObjectID::PRAXIDIKE                   : return "527";
        case ObjectID::AUTONOE                     : return "528";
        case ObjectID::THYONE                      : return "529";
        case ObjectID::HERMIPPE                    : return "530";
        case ObjectID::AITNE                       : return "531";
        case ObjectID::EURYDOME                    : return "532";
        case ObjectID::EUANTHE                     : return "533";
        case ObjectID::EUPORIE                     : return "534";
        case ObjectID::ORTHOSIE                    : return "535";
        case ObjectID::SPONDE                      : return "536";
        case ObjectID::KALE                        : return "537";
        case ObjectID::PASITHEE                    : return "538";
        case ObjectID::HEGEMONE                    : return "539";
        case ObjectID::MNEME                       : return "540";
        case ObjectID::AOEDE                       : return "541";
        case ObjectID::THELXINOE                   : return "542";
        case ObjectID::ARCHE                       : return "543";
        case ObjectID::KALLICHORE                  : return "544";
        case ObjectID::HELIKE                      : return "545";
        case ObjectID::CARPO                       : return "546";
        case ObjectID::EUKELADE                    : return "547";
        case ObjectID::CYLLENE                     : return "548";
        case ObjectID::KORE                        : return "549";
        case ObjectID::HERSE                       : return "550";
        case ObjectID::JUPITER_MOON_51             : return "551";
        case ObjectID::JUPITER_MOON_52             : return "552";
        case ObjectID::JUPITER_MOON_53             : return "553";
        case ObjectID::JUPITER_MOON_54             : return "554";
        case ObjectID::JUPITER_MOON_55             : return "555";
        case ObjectID::JUPITER_MOON_56             : return "556";
        case ObjectID::JUPITER_MOON_57             : return "557";
        case ObjectID::JUPITER_MOON_58             : return "558";
        case ObjectID::JUPITER_MOON_59             : return "559";
        case ObjectID::JUPITER_MOON_60             : return "560";
        case ObjectID::JUPITER_MOON_61             : return "561";
        case ObjectID::JUPITER_MOON_62             : return "562";
        case ObjectID::JUPITER_MOON_63             : return "563";
        case ObjectID::JUPITER_MOON_64             : return "564";
        case ObjectID::JUPITER_MOON_65             : return "565";
        case ObjectID::JUPITER_MOON_66             : return "566";
        case ObjectID::JUPITER_MOON_67             : return "567";
        case ObjectID::JUPITER_MOON_68             : return "568";
        case ObjectID::JUPITER_MOON_69             : return "569";
        case ObjectID::JUPITER_MOON_70             : return "570";
        case ObjectID::JUPITER_MOON_71             : return "571";
        case ObjectID::JUPITER_MOON_72             : return "572";
        case ObjectID::JUPITER                     : return "599";
        case ObjectID::MIMAS                       : return "601";
        case ObjectID::ENCELADUS                   : return "602";
        case ObjectID::TETHYS                      : return "603";
        case ObjectID::DIONE                       : return "604";
        case ObjectID::RHEA                        : return "605";
        case ObjectID::TITAN                       : return "606";
        case ObjectID::HYPERION                    : return "607";
        case ObjectID::IAPETUS                     : return "608";
        case ObjectID::PHOEBE                      : return "609";
        case ObjectID::JANUS                       : return "610";
        case ObjectID::EPIMETHEUS                  : return "611";
        case ObjectID::HELENE                      : return "612";
        case ObjectID::TELESTO                     : return "613";
        case ObjectID::CALYPSO                     : return "614";
        case ObjectID::ATLAS                       : return "615";
        case ObjectID::PROMETHEUS                  : return "616";
        case ObjectID::PANDORA                     : return "617";
        case ObjectID::PAN                         : return "618";
        case ObjectID::YMIR                        : return "619";
        case ObjectID::PAALIAQ                     : return "620";
        case ObjectID::TARVOS                      : return "621";
        case ObjectID::IJIRAQ                      : return "622";
        case ObjectID::SUTTUNGR                    : return "623";
        case ObjectID::KIVIUQ                      : return "624";
        case ObjectID::MUNDILFARI                  : return "625";
        case ObjectID::ALBIORIX                    : return "626";
        case ObjectID::SKATHI                      : return "627";
        case ObjectID::ERRIAPUS                    : return "628";
        case ObjectID::SIARNAQ                     : return "629";
        case ObjectID::THRYMR                      : return "630";
        case ObjectID::NARVI                       : return "631";
        case ObjectID::AEGIR                       : return "636";
        case ObjectID::BEBHIONN                    : return "637";
        case ObjectID::BERGELMIR                   : return "638";
        case ObjectID::BESTLA                      : return "639";
        case ObjectID::FARBAUTI                    : return "640";
        case ObjectID::FENRIR                      : return "641";
        case ObjectID::FORNJOT                     : return "642";
        case ObjectID::HATI                        : return "643";
        case ObjectID::HYRROKKIN                   : return "644";
        case ObjectID::KARI                        : return "645";
        case ObjectID::LOGE                        : return "646";
        case ObjectID::SKOLL                       : return "647";
        case ObjectID::SURTUR                      : return "648";
        case ObjectID::JARNSAXA                    : return "650";
        case ObjectID::GREIP                       : return "651";
        case ObjectID::TARQEQ                      : return "652";
        case ObjectID::AEGAEON                     : return "653";
        case ObjectID::SATURN                      : return "699";
        case ObjectID::ARIEL                       : return "701";
        case ObjectID::UMBRIEL                     : return "702";
        case ObjectID::TITANIA                     : return "703";
        case ObjectID::OBERON                      : return "704";
        case ObjectID::MIRANDA                     : return "705";
        case ObjectID::CORDELIA                    : return "706";
        case ObjectID::OPHELIA                     : return "707";
        case ObjectID::BIANCA                      : return "708";
        case ObjectID::CRESSIDA                    : return "709";
        case ObjectID::DESDEMONA                   : return "710";
        case ObjectID::JULIET                      : return "711";
        case ObjectID::PORTIA                      : return "712";
        case ObjectID::ROSALIND                    : return "713";
        case ObjectID::BELINDA                     : return "714";
        case ObjectID::PUCK                        : return "715";
        case ObjectID::CALIBAN                     : return "716";
        case ObjectID::SYCORAX                     : return "717";
        case ObjectID::PROSPERO                    : return "718";
        case ObjectID::SETEBOS                     : return "719";
        case ObjectID::STEPHANO                    : return "720";
        case ObjectID::TRINCULO                    : return "721";
        case ObjectID::FRANCISCO                   : return "722";
        case ObjectID::MARGARET                    : return "723";
        case ObjectID::FERDINAND                   : return "724";
        case ObjectID::PERDITA                     : return "725";
        case ObjectID::MAB                         : return "726";
        case ObjectID::CUPID                       : return "727";
        case ObjectID::URANUS                      : return "799";
        case ObjectID::TRITON                      : return "801";
        case ObjectID::NEREID                      : return "802";
        case ObjectID::NAIAD                       : return "803";
        case ObjectID::THALASSA                    : return "804";
        case ObjectID::DESPINA                     : return "805";
        case ObjectID::GALATEA                     : return "806";
        case ObjectID::LARISSA                     : return "807";
        case ObjectID::PROTEUS                     : return "808";
        case ObjectID::HALIMEDE                    : return "809";
        case ObjectID::PSAMATHE                    : return "810";
        case ObjectID::SAO                         : return "811";
        case ObjectID::LAOMEDEIA                   : return "812";
        case ObjectID::NESO                        : return "813";
        case ObjectID::NEPTUNE                     : return "899";
        case ObjectID::CHARON                      : return "901";
        case ObjectID::NIX                         : return "902";
        case ObjectID::HYDRA                       : return "903";
        case ObjectID::KERBEROS                    : return "904";
        case ObjectID::STYX                        : return "905";
        case ObjectID::PLUTO                       : return "999";
        
        case ObjectID::INVALID:
        default:
        {
            printf("(%s):%d: Invalid ObjectID %d\n", __FILE__, __LINE__, static_cast<int>(ID));
            return "INVALID";
        }
    }
}


std::string Spice::GetFrameString(FrameID ID)
{
    switch (ID)    
    {
        case FrameID::J2000 : return "J2000";
        case FrameID::ITRF93 : return "ITRF93";
        case FrameID::EARTH_FIXED : return "EARTH_FIXED";
        case FrameID::B1950 : return "B1950";
        case FrameID::FK4 : return "FK4";
        case FrameID::DE_118 : return "DE-118";
        case FrameID::DE_96 : return "DE-96";
        case FrameID::DE_108 : return "DE-108";
        case FrameID::DE_111 : return "DE-111";
        case FrameID::DE_114 : return "DE-114";
        case FrameID::DE_122 : return "DE-122";
        case FrameID::DE_125 : return "DE-125";
        case FrameID::DE_130 : return "DE-130";
        case FrameID::DE_140 : return "DE-140";
        case FrameID::DE_142 : return "DE-142";
        case FrameID::DE_143 : return "DE-143";
        case FrameID::DE_200 : return "DE-200";
        case FrameID::DE_202 : return "DE-202";
        case FrameID::ECLIPJ2000 : return "ECLIPJ2000";
        case FrameID::ECLIPB1950 : return "ECLIPB1950";
        case FrameID::GALACTIC : return "GALACTIC";
        case FrameID::MARSIAU : return "MARSIAU";
        case FrameID::IAU_ADRASTEA : return "IAU_ADRASTEA";
        case FrameID::IAU_AMALTHEA : return "IAU_AMALTHEA";
        case FrameID::IAU_ANANKE : return "IAU_ANANKE";
        case FrameID::IAU_ARIEL : return "IAU_ARIEL";
        case FrameID::IAU_ATLAS : return "IAU_ATLAS";
        case FrameID::IAU_BELINDA : return "IAU_BELINDA";
        case FrameID::IAU_BENNU : return "IAU_BENNU";
        case FrameID::IAU_BIANCA : return "IAU_BIANCA";
        case FrameID::IAU_BORRELLY : return "IAU_BORRELLY";
        case FrameID::IAU_CALLIRRHOE : return "IAU_CALLIRRHOE";
        case FrameID::IAU_CALLISTO : return "IAU_CALLISTO";
        case FrameID::IAU_CALYPSO : return "IAU_CALYPSO";
        case FrameID::IAU_CARME : return "IAU_CARME";
        case FrameID::IAU_CERES : return "IAU_CERES";
        case FrameID::IAU_CHALDENE : return "IAU_CHALDENE";
        case FrameID::IAU_CHARON : return "IAU_CHARON";
        case FrameID::IAU_CORDELIA : return "IAU_CORDELIA";
        case FrameID::IAU_CRESSIDA : return "IAU_CRESSIDA";
        case FrameID::IAU_DAVIDA : return "IAU_DAVIDA";
        case FrameID::IAU_DEIMOS : return "IAU_DEIMOS";
        case FrameID::IAU_DESDEMONA : return "IAU_DESDEMONA";
        case FrameID::IAU_DESPINA : return "IAU_DESPINA";
        case FrameID::IAU_DIONE : return "IAU_DIONE";
        case FrameID::IAU_EARTH : return "IAU_EARTH";
        case FrameID::IAU_ELARA : return "IAU_ELARA";
        case FrameID::IAU_ENCELADUS : return "IAU_ENCELADUS";
        case FrameID::IAU_EPIMETHEUS : return "IAU_EPIMETHEUS";
        case FrameID::IAU_ERINOME : return "IAU_ERINOME";
        case FrameID::IAU_EROS : return "IAU_EROS";
        case FrameID::IAU_EUROPA : return "IAU_EUROPA";
        case FrameID::IAU_GALATEA : return "IAU_GALATEA";
        case FrameID::IAU_GANYMEDE : return "IAU_GANYMEDE";
        case FrameID::IAU_GASPRA : return "IAU_GASPRA";
        case FrameID::IAU_HARPALYKE : return "IAU_HARPALYKE";
        case FrameID::IAU_HELENE : return "IAU_HELENE";
        case FrameID::IAU_HIMALIA : return "IAU_HIMALIA";
        case FrameID::IAU_HYPERION : return "IAU_HYPERION";
        case FrameID::IAU_IAPETUS : return "IAU_IAPETUS";
        case FrameID::IAU_IDA : return "IAU_IDA";
        case FrameID::IAU_IO : return "IAU_IO";
        case FrameID::IAU_IOCASTE : return "IAU_IOCASTE";
        case FrameID::IAU_ISONOE : return "IAU_ISONOE";
        case FrameID::IAU_ITOKAWA : return "IAU_ITOKAWA";
        case FrameID::IAU_JANUS : return "IAU_JANUS";
        case FrameID::IAU_JULIET : return "IAU_JULIET";
        case FrameID::IAU_JUPITER : return "IAU_JUPITER";
        case FrameID::IAU_KALYKE : return "IAU_KALYKE";
        case FrameID::IAU_LARISSA : return "IAU_LARISSA";
        case FrameID::IAU_LEDA : return "IAU_LEDA";
        case FrameID::IAU_LUTETIA : return "IAU_LUTETIA";
        case FrameID::IAU_LYSITHEA : return "IAU_LYSITHEA";
        case FrameID::IAU_MAGACLITE : return "IAU_MAGACLITE";
        case FrameID::IAU_MARS : return "IAU_MARS";
        case FrameID::IAU_MERCURY : return "IAU_MERCURY";
        case FrameID::IAU_METIS : return "IAU_METIS";
        case FrameID::IAU_MIMAS : return "IAU_MIMAS";
        case FrameID::IAU_MIRANDA : return "IAU_MIRANDA";
        case FrameID::IAU_MOON : return "IAU_MOON";
        case FrameID::IAU_NAIAD : return "IAU_NAIAD";
        case FrameID::IAU_NEPTUNE : return "IAU_NEPTUNE";
        case FrameID::IAU_NEREID : return "IAU_NEREID";
        case FrameID::IAU_OBERON : return "IAU_OBERON";
        case FrameID::IAU_OPHELIA : return "IAU_OPHELIA";
        case FrameID::IAU_PALLAS : return "IAU_PALLAS";
        case FrameID::IAU_PAN : return "IAU_PAN";
        case FrameID::IAU_PANDORA : return "IAU_PANDORA";
        case FrameID::IAU_PASIPHAE : return "IAU_PASIPHAE";
        case FrameID::IAU_PHOBOS : return "IAU_PHOBOS";
        case FrameID::IAU_PHOEBE : return "IAU_PHOEBE";
        case FrameID::IAU_PLUTO : return "IAU_PLUTO";
        case FrameID::IAU_PORTIA : return "IAU_PORTIA";
        case FrameID::IAU_PRAXIDIKE : return "IAU_PRAXIDIKE";
        case FrameID::IAU_PROMETHEUS : return "IAU_PROMETHEUS";
        case FrameID::IAU_PROTEUS : return "IAU_PROTEUS";
        case FrameID::IAU_PUCK : return "IAU_PUCK";
        case FrameID::IAU_RHEA : return "IAU_RHEA";
        case FrameID::IAU_ROSALIND : return "IAU_ROSALIND";
        case FrameID::IAU_SATURN : return "IAU_SATURN";
        case FrameID::IAU_SINOPE : return "IAU_SINOPE";
        case FrameID::IAU_STEINS : return "IAU_STEINS";
        case FrameID::IAU_SUN : return "IAU_SUN";
        case FrameID::IAU_TAYGETE : return "IAU_TAYGETE";
        case FrameID::IAU_TELESTO : return "IAU_TELESTO";
        case FrameID::IAU_TEMPEL_1 : return "IAU_TEMPEL_1";
        case FrameID::IAU_TETHYS : return "IAU_TETHYS";
        case FrameID::IAU_THALASSA : return "IAU_THALASSA";
        case FrameID::IAU_THEBE : return "IAU_THEBE";
        case FrameID::IAU_THEMISTO : return "IAU_THEMISTO";
        case FrameID::IAU_TITAN : return "IAU_TITAN";
        case FrameID::IAU_TITANIA : return "IAU_TITANIA";
        case FrameID::IAU_TRITON : return "IAU_TRITON";
        case FrameID::IAU_UMBRIEL : return "IAU_UMBRIEL";
        case FrameID::IAU_URANUS : return "IAU_URANUS";
        case FrameID::IAU_VENUS : return "IAU_VENUS";
        case FrameID::IAU_VESTA : return "IAU_VESTA";
        case FrameID::INVALID: 
        default:
        {
            printf("(%s):%d: Invalid FrameID %d\n", __FILE__, __LINE__, static_cast<int>(ID));
            return "INVALID";
        }
    }
}

std::string Spice::GetAbCorrectionString(AbCorrectionID ID)
{
    switch (ID)    
    {
        case AbCorrectionID::NONE : return "NONE";
        case AbCorrectionID::LIGHT_TIME : return "LT";
        case AbCorrectionID::LIGHT_TIME_STELLAR : return "LT+S";
        case AbCorrectionID::CONVERGED_NEWTONIAN : return "CN";
        case AbCorrectionID::CONVERGED_NEWTONIAN_STELLAR : return "CN+S";
        case AbCorrectionID::LIGHT_TIME_TRANS : return "XLT";
        case AbCorrectionID::LIGHT_TIME_STELLAR_TRANS : return "XLT+S";
        case AbCorrectionID::CONVERGED_NEWTONIAN_TRANS : return "XCN";
        case AbCorrectionID::CONVERGED_NEWTONIAN_STELLAR_TRANS : return "XCN+S";
        case AbCorrectionID::INVALID :
        default :
        {
            printf("(%s):%d Invalid AbCorrectionID %d\n", __FILE__, __LINE__, static_cast<int>(ID));
            return "INVALID";
        }
    }
}