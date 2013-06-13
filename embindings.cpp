// embindings.cpp
#include <emscripten/bind.h>
#include "quick_example.cpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
}