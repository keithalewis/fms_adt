cmake_minimum_required(VERSION 3.15)

project(fms_adt
	VERSION 0.1
	DESCRIPTION "Abstract Data Type"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} INTERFACE)

include(CTest)
enable_testing()

add_executable(fms_adt.t)
target_sources(fms_adt.t
	PRIVATE
	fms_adt.t.cpp
	fms_adt_cpp.t.cpp
)

add_test(NAME fms_adt.t COMMAND fms_adt.t)
