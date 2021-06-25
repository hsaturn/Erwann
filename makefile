LIBS=-lSDL2 -lSDL2_image
OPTS=-O0 -g -std=c++17 -Wall -MMD
GXX=g++ $(OPTS) -Iinclude

BUILD_DIR=build
BINARY=erwann

all: build $(BINARY)

-include $(BUILD_DIR)/*.d

SRCE=$(wildcard src/*.cpp) main.cpp
OBJS=$(addprefix $(BUILD_DIR)/,$(SRCE:.cpp=.o))

$(BINARY): $(OBJS)
	@echo "Linking $@"
	$(GXX) $(OBJS) -o $@ $(LIBS)

.PHONY: build
build: $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/src

vars:
	echo "OBJS=$(OBJS)"

clean:
	-rm -f $(BUILD_DIR)/*.d
	-rm -f $(OBJS)
	-rm -f $(BINARY)
	-find . -name "core" -delete

$(BUILD_DIR)/%.o: %.cpp
	@echo "  Compiling $<"
	@$(GXX) -c $< -o $@
