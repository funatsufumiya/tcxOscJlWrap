#define TRUSSC_SHOW_CONSOLE 1
#include "TrussC.h"
#include "tcxOsc.h"

#include "tcxOscJl.h"

#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"

// // NOTE: This line comment is left for future usage
// #include "trussc_generated.h"

using namespace std;
using namespace tc;


namespace jlcxx
{
//   template<> struct IsMirroredType<FpsSettings> : std::false_type { };
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{

    // // NOTE: this comment is left for reference.

    //   mod.method("greet", &greet);
    //   mod.method("runTrusscTestApp", [](){ runTrusscTestApp(); });

    //   mod.add_type<Vec2>("Vec2")
    //     .constructor<>()
    //     .constructor<float, float>()
    //     .constructor<const Vec2&>()
    //     .method("x", [](Vec2& v){ return v.x; })

    //   mod.add_enum<PrimitiveMode>("PrimitiveMode",
    //         std::vector<const char*>({
    //             "Triangles",
    //         }),
    //         std::vector<int>({
    //             (int)PrimitiveMode::Triangles,
    //         })
    //     );

    // // End of references.

    mod.add_type<OscMessage>("OscMessage")
        .constructor<>()
        .constructor<const OscMessage&>()
        .constructor<const std::string&>()
        .method("setAddress", &OscMessage::setAddress)
        .method("getAddress", &OscMessage::getAddress)
        .method("addInt", &OscMessage::addInt)
        .method("addFloat", &OscMessage::addFloat)
        .method("addString", &OscMessage::addString)
        .method("addBlob", &OscMessage::addBlob)
        .method("addBool", &OscMessage::addBool)
        .method("getArgCount", &OscMessage::getArgCount)
        .method("getTypeTags", &OscMessage::getTypeTags)
        .method("getArgAsInt", &OscMessage::getArgAsInt)
        .method("getArgAsFloat", &OscMessage::getArgAsFloat)
        .method("getArgAsString", &OscMessage::getArgAsString)
        .method("getArgAsBlob", &OscMessage::getArgAsBlob)
        .method("getArgAsBool", &OscMessage::getArgAsBool)
        .method("toBytes", &OscMessage::toBytes)
        .method("toString", &OscMessage::toString)
        .method("clear", &OscMessage::clear)
        ;

    mod.add_type<OscBundle>("OscBundle")
        .constructor<>()
        .constructor<const OscBundle&>()
        ;

    mod.add_type<OscSender>("OscSender")
        .constructor<>()
        ;

    mod.add_type<OscReceiver>("OscReceiver")
        .constructor<>()
        ;

    // //  NOTE: This line comment is left for future usage
    //   define_julia_module_trussc_generated(mod);
}
