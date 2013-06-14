// embindings.cpp
#include <emscripten/bind.h>
#include "quick_example.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(my_module) {
	function("lerp", &lerp);

	//value_struct<myStruct>("myStruct")
	//    .field("x", &myStruct::x)
	//    .field("y", &myStruct::y)
	//    ;

	class_<myStruct>("myStruct")
		.constructor<>()
		;

	function("getStruct", &getStruct);

	class_<MyClass>("MyClass")
		.constructor<int, std::string>()
		.function("incrementX", &MyClass::incrementX)
		.property("x", &MyClass::getX, &MyClass::setX)
		.class_function("getStringFromInstance", &MyClass::getStringFromInstance)
		;
}