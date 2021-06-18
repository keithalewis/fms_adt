// fms_adt.h - Abstract Data Types
#pragma once
#ifdef __GNUC__
#include <cxxabi.h>
#endif
#include <functional>
#include <initializer_list>
#include <map>
#include <typeinfo>
#include <vector>

namespace fms::adt {

#ifdef __GNUC__
	struct demangle {
		char* buf;
		size_t len;
		int status;
		demangle(const std::type_info& type, size_t len = 1024)
			: buf((char*)malloc(len))
		{
			abi::__cxa_demangle(type.name(), buf, &len, &status);
			//assert(0 == status);
		}
		demangle(const demangle&) = delete;
		demangle& operator=(const demangle&) = delete;
		~demangle()
		{
			free(buf);
		}
		operator const char*() const
		{
			return buf;
		}
	};
#endif // __GNUC__

	inline std::string type_name(const std::type_info& type)
	{
#ifdef __GNUC__
		return std::string(demangle(type));
#else
		return std::string(type.name());
#endif // __GNUC__
	}

	// single function argument
	struct arg {
		std::reference_wrapper<const std::type_info> type;
		const char* name;
		const char* help;
		const char* init;
		arg()
			: type(typeid(nullptr)), name(nullptr), help(nullptr), init(nullptr)
		{ }
		arg(const std::type_info& type, const char* name, const char* help, const char* init = nullptr)
			: type(type), name(name), help(help), init(init)
		{ }

		std::string type_name() const
		{
			return fms::adt::type_name(type);
		}
	};

	struct function {
		std::reference_wrapper<const std::type_info> type;
		const char* name;
		const char* help; // short help
		const char* desc; // detailed documentation
		std::vector<arg> args;

		function()
			: type(typeid(nullptr)), name(nullptr), help(nullptr), desc(nullptr)
		{ }
		function(const std::type_info& type, const char* name, const char* help, const char* desc = nullptr)
			: type(type), name(name), help(help), desc(desc)
		{ }

		std::string type_name() const
		{
			return fms::adt::type_name(type);
		}

		function& arguments(const std::vector<arg>& args)
		{
			this->args = args;

			return *this;
		}

		function& documentation(const char* desc)
		{
			this->desc = desc;

			return *this;
		}
		const char* documentation() const
		{
			return desc;
		}
	};

	struct adt {
		static inline std::map<std::string, function> map;
		adt(const function& f)
		{
			map[f.name] = f;
		}
	};

} // namespace fms
