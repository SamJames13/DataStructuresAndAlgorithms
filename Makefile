# CXX Make variable for compiler

# compiles the program into an executable named 'citydfs'
# compile by typing 'make'
# run the executable by typing './citydfs'
# remove previously compiled files by typing 'make clean'
# to ensure you are using your latest code when compiling

CXX=g++
# Make variable for compiler options
# -std=c++11  C/C++ variant to use, e.g. C++ 2011
# -Wall       show verbose warning messages
# -g3         include information for symbolic debugger e.g. gdb 
CXXFLAGS=-std=c++11 -Wall -g3 -c

# object files
OBJS = connectedcities.o driver.o

# Program name
PROGRAM = citydfs

# Rules format:
# target : dependency1 dependency2 ... dependencyN
#     Command to make target, uses default rules if not specified

# First target is the one executed if you just type make
# make target specifies a specific target
# $^ is an example of a special variable.  It substitutes all dependencies
$(PROGRAM) : $(OBJS)
	$(CXX) -o $(PROGRAM) $^

driver.o : driver.cpp
	$(CXX) $(CXXFLAGS) driver.cpp

connectedcities.o : connectedcities.cpp connectedcities.h
	$(CXX) $(CXXFLAGS) connectedcities.cpp

# clean all *.o files and executables
clean:
	rm -f *.o $(PROGRAM)

# clean all *.o files
cleano:
	rm -f *.o

