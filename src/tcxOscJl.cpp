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

    mod.method("OscMessage_fromBytes", &OscMessage::fromBytes);

    mod.add_type<OscBundle>("OscBundle")
        .constructor<>()
        .constructor<const OscBundle&>()
        .constructor<uint64_t>()
        .method("setTimetag", &OscBundle::setTimetag)
        .method("getTimetag", &OscBundle::getTimetag)
        .method("addMessage", &OscBundle::addMessage)
        .method("addBundle", &OscBundle::addBundle)
        .method("getElementCount", &OscBundle::getElementCount)
        .method("isBundle", &OscBundle::isBundle)
        .method("isMessage", &OscBundle::isMessage)
        .method("getMessageAt", &OscBundle::getMessageAt)
        .method("getBundleAt", &OscBundle::getBundleAt)
        .method("toBytes", &OscBundle::toBytes)
        .method("clear", &OscBundle::clear)
        ;

    mod.method("OscBundle_fromBytes", &OscBundle::fromBytes);
    mod.method("OscBundle_isBundle", &OscBundle::isBundle);

    using OscSenderDestination = OscSender::Destination;
    mod.add_type<OscSenderDestination>("OscSenderDestination")
        .constructor<>()
        .method("host", [](OscSenderDestination& d){ return d.host; })
        .method("host!", [](OscSenderDestination& d, const std::string& h){ return d.host = h; })
        .method("port", [](OscSenderDestination& d){ return d.port; })
        .method("port!", [](OscSenderDestination& d, int p){ return d.port = p; })
        ;

    mod.add_type<OscSender>("OscSender")
        .constructor<>()
        .method("connect", &OscSender::connect)
        .method("disconnect", [](OscSender& o){ o.disconnect(); })
        .method("disconnect", [](OscSender& o, const std::string& h, int p){ o.disconnect(h, p); })
        .method("setup", &OscSender::setup)
        .method("close", &OscSender::close)
        .method("send", [](OscSender& o, const OscMessage& m){ o.send(m); })
        .method("send", [](OscSender& o, const OscBundle& b){ o.send(b); })
        .method("sendTo", [](OscSender& o, const std::string& h, int p, const OscMessage& m){ o.sendTo(h,p,m); })
        .method("sendTo", [](OscSender& o, const std::string& h, int p, const OscBundle& b){ o.sendTo(h,p,b); })
        .method("getConnectedAddresses", &OscSender::getConnectedAddresses)
        .method("isConnected", &OscSender::isConnected)
        ;

    mod.add_type<OscReceiver>("OscReceiver")
        .constructor<>()
        .method("setup", &OscReceiver::setup)
        .method("close", &OscReceiver::close)
        .method("getPort", &OscReceiver::getPort)
        .method("isListening", &OscReceiver::isListening)
        .method("hasNewMessage", &OscReceiver::hasNewMessage)
        .method("getNextMessage", &OscReceiver::getNextMessage)
        .method("setBufferSize", &OscReceiver::setBufferSize)
        .method("getBufferSize", &OscReceiver::getBufferSize)
        ;

    // //  NOTE: This line comment is left for future usage
    //   define_julia_module_trussc_generated(mod);
}
