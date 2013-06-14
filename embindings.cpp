// embindings.cpp
#include <emscripten/bind.h>
#include "quick_example.h"

using namespace emscripten;

int get_x(const myStruct& s) { return s.x; }

EMSCRIPTEN_BINDINGS(my_module) {
	function("lerp", &lerp);

	//value_struct<myStruct>("myStruct")
	//    .field("x", &myStruct::x)
	//    .field("y", &myStruct::y)
	//    ;

	class_<myStruct>("myStruct")
		.constructor<>()
		.function("get_x", &get_x);
		;

	function("getStruct", &getStruct);

	class_<MyClass>("MyClass")
		.constructor<int, std::string>()
		.function("incrementX", &MyClass::incrementX)
		.property("x", &MyClass::getX, &MyClass::setX)
		.class_function("getStringFromInstance", &MyClass::getStringFromInstance)
		;
}