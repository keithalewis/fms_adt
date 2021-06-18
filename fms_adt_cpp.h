// fms_adt_cpp.h - C++ prototypes
#pragma once
#include <iostream>
//#include <fmt/format.h>
#include "fms_adt.h"

// C declaration
std::ostream& operator<<(std::ostream& os, const fms::adt::function& f)
{
	os << f.type_name() << " " << f.name << "(";
	
	for (size_t i = 0; i < f.args.size(); ++i) {
		if (i > 0) {
			os << ", ";
		}
		os << f.args[i].type_name() << " " << f.args[i].name;
	}

	os << ");";

	return os;
}
