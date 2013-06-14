// embindings.cpp
#include <emscripten/bind.h>
#include "quick_example.h"

using namespace emscripten;

int getX(const myStruct& s) { return s.x; }
void setX(myStruct& s, int newX) { s.x = newX; }

EMSCRIPTEN_BINDINGS(my_module) {
	function("lerp", &lerp);

	//value_struct<myStruct>("myStruct")
	//    .field("x", &myStruct::x)
	//    .field("y", &myStruct::y)
	//    ;

	class_<myStruct>("myStruct")
		.constructor<>()
		.function("getX", &getX)
		.function("setX", &setX)
		.property("x", &getX, &setX)
		;

	function("getStruct", &getStruct);

	class_<MyClass>("MyClass")
		.constructor<int, std::string>()
		.function("incrementX", &MyClass::incrementX)
		.property("x", &MyClass::getX, &MyClass::setX)
		.class_function("getStringFromInstance", &MyClass::getStringFromInstance)
		;
}