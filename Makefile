CXXFLAGS = -g -Wall -std=c++20
SRCS = fms_adt.t.cpp fms_adt_cpp.t.cpp
OBJS = $(SRCS:.cpp=.o)

fms_adt.t: $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS)

test:
	./a.out
	
fms_adt.t.o: fms_adt.t.cpp fms_adt.h
fms_adt_cpp.t.o: fms_adt_cpp.t.cpp fms_adt_cpp.h
