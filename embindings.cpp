// embindings.cpp
#include <emscripten/bind.h>
#include "quick_example.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
    value_struct<myStruct>("myStruct")
        .field("x", &myStruct::x)
        .field("y", &myStruct::y)
        ;
}