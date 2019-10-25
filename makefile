LIBS=-lSDL2
OPTS=-O0 -g -std=c++17 -Wall -MMD
GXX=g++ $(OPTS)

BUILD_DIR=build
BINARY=erwann

all: $(BINARY)

-include $(BUILD_DIR)/*.d

SRCE=$(wildcard *.cpp)
OBJS=$(addprefix $(BUILD_DIR)/,$(SRCE:.cpp=.o))


$(BINARY): $(OBJS)
	@echo "Linking $@"
	$(GXX) $(OBJS) -o $@ $(LIBS)

.PHONY: build
build: $(BUILD_DIR)
	mkdir -p $*(BUILD_DIR)

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
