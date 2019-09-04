CXX      = g++
CXX_FILE = $(wildcard *.cpp)
TARGET   = $(patsubst %.cpp,%,$(CXX_FILE))
CXXFLAGS = -g -std=c++11 -Wall -Werror -pedantic-errors -fmessage-length=0
# -g means to include debug info into the executable
# -O3 will improve the speed vs -g
# -std=c++11 lets us use the c++ 11 standard, there are newer standards
# -Wall will treat out code very strictly - anything slightly off will let us know, always put -Wall
# -Werror turns all warnings into errors
# -pedantic-errors helps to catch bugs at compile times

all: # Build targets (including clean)
	$(CXX) $(CXXFLAGS) $(CXX_FILE) -o $(TARGET) 
	# BUILD INSTRUCTION MUST COME AFTER A TAB CHARACTER
clean: # Does a remove with a -f (force) of the target exe
	rm -f $(TARGET) $(TARGET).exe
