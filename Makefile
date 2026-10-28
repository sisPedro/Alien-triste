CXX      ?= g++
CXXFLAGS ?= -std=c++17 -O2
LIBS     := sdl2 SDL2_image SDL2_mixer SDL2_ttf
CXXFLAGS += $(shell pkg-config --cflags $(LIBS))
LDLIBS   += $(shell pkg-config --libs $(LIBS))

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=build/%.o)
BIN  := alien

$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

build/%.o: %.cpp $(wildcard *.h) | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

run: $(BIN)
	./$(BIN)

clean:
	rm -rf build $(BIN)

.PHONY: run clean
