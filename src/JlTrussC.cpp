#define TRUSSC_SHOW_CONSOLE 1
#include "TrussC.h"

#include "JlTrussC.h"

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


    // //  NOTE: This line comment is left for future usage
    //   define_julia_module_trussc_generated(mod);
}
