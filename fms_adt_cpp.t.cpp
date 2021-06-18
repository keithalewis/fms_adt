// fms_adt_cpp.t.cpp - test C++ generation
#include <cassert>
#include <sstream>
#include "fms_adt_cpp.h"

using namespace fms::adt;

int test_adt_cpp()
{
	{
		function f(typeid(double), "rand", "random");
		std::ostringstream oss;
		oss << f;
		assert(oss.str() == "double rand();");
	}
	{
		function f(typeid(double), "foo", "is foo");
		f.arguments({
				arg(typeid(int), "i", "is int")
				});
		std::ostringstream oss;
		oss << f;
		assert(oss.str() == "double foo(int i);");
	}
	{
		function f(typeid(double), "foo", "is foo");
		f.arguments({
				arg(typeid(int), "i", "is int"),
				arg(typeid(float), "f", "is float"),
				});
		std::ostringstream oss;
		oss << f;
		assert(oss.str() == "double foo(int i, float f);");
	}

	return 0;
}
int test_adt_cpp_ = test_adt_cpp();
