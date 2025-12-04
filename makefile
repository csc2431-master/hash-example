# Flags

CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -g

TARGET := map

SRCS := main.cpp product.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o:	%cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:	all clean

clean:
	rm -f $(TARGET) $(OBJS)