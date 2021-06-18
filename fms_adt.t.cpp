// fms_adt.t.cpp - test adt
#include <cassert>
#include <cstring>
#include <iostream>
#include <typeinfo>
#include "fms_adt.h"

using namespace fms::adt;

int test_arg()
{
	{
		arg a;
		assert(nullptr == a.name);
		assert(nullptr == a.help);
		assert(nullptr == a.init);
		arg a2(a);
		assert(nullptr == a2.name);
		assert(nullptr == a2.help);
		assert(nullptr == a2.init);
		a = a2;
	}
	{
		arg a{typeid(int), "i", "is an int"};
		assert(0 == strcmp("int", type_name(a.type).c_str()));
		assert(0 == strcmp("i", a.name));
		assert(0 == strcmp("is an int", a.help));
		assert(nullptr == a.init);
		arg a2{a};
		assert(0 == strcmp("int", type_name(a2.type).c_str()));
		assert(0 == strcmp("i", a2.name));
		assert(0 == strcmp("is an int", a2.help));
		assert(nullptr == a2.init);
		a = a2;
		assert(0 == strcmp("int", type_name(a.type).c_str()));
	}

	return 0;
}
int test_arg_ = test_arg();

int test_function()
{
	{
		function f;
		assert(nullptr == f.name);
		assert(nullptr == f.help);
		assert(nullptr == f.desc);
		function f2{f};
		assert(nullptr == f2.name);
		assert(nullptr == f2.help);
		assert(nullptr == f2.desc);
		f = f2;
	}
	{
		function f(typeid(double), "cos", "cosine");
		assert(0 == strcmp("double", type_name(f.type).c_str()));
		assert(0 == strcmp("cos", f.name));
		assert(0 == strcmp("cosine", f.help));
		assert(nullptr == f.desc);
		assert(0 == f.args.size());
		auto f2 = f;
		f.documentation("docs");
		assert(0 == strcmp("docs", f.desc));
		f.arguments({arg(typeid(double), "x", "is arg")});
		assert(1 == f.args.size());
		const auto& a0 = f.args[0];
		assert(a0.type == typeid(double));
		assert(0 == strcmp("x", a0.name));
		assert(0 == strcmp("is arg", a0.help));
		assert(nullptr == a0.init);
	}

	return 0;
}
int test_function_ = test_function();

int test_adt()
{
	{
		adt adt_cos(
			function(typeid(double), "cos", "cosine")
			.arguments({arg(typeid(double), "x", "is arg")})
			.documentation("docs")
		);

		const auto& cos = adt::map["cos"];
		assert(0 == strcmp("double", cos.type_name().c_str()));
		assert(0 == strcmp("cos", cos.name));
		assert(0 == strcmp("cosine", cos.help));
		assert(0 == strcmp("docs", cos.desc));
		assert(0 == strcmp("docs", cos.documentation()));

		assert(1 == cos.args.size());
		const auto& a0 = cos.args[0];
		assert(a0.type == typeid(double));
		assert(0 == strcmp("x", a0.name));
		assert(0 == strcmp("is arg", a0.help));
		assert(nullptr == a0.init);
	}
	
	return 0;
}
int test_adt_ = test_adt();

int main()
{
	return 0;
}
