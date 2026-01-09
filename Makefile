CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Icode/include

TARGET = app
SRCS = main.cpp $(wildcard code/src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# makes .exe file
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# compilation settings
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# runs the .exe file
run: $(TARGET)
	./$(TARGET)

# clean build files
clean:
	rm -f $(OBJS) $(TARGET)