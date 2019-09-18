/* CXX Flags

-g or -O3 //
-g saves debug info in the executable
-std=c++11 //c++library we're using
-Wall //warn user about everything that could cause problems
-Werror //turn all warnings into error
-pedantic-errors //give more warnings
-fmessage-length=0 //formats error messages to fit on one line
-o //output
-f //forcefully

all:
[tab character]$(CXX) $(CXXFLAGS) $(CXX_FILE) -o $(TARGET)

clean:
[tab character]$rm -f $(TARGET) $(TARGET).exe

*/
