CXXFLAGS=-I./include -std=c++11
CFLAGS=-I./include -std=c99
LFLAGS=-lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -framework OpenGL

UNAME=$(shell uname)
ifeq ($(UNAME), Darwin)
	CXX=clang++
	CC=clang
else
	CXX=g++
	CC=gcc
endif

SRC_DIR=src
BUILD_DIR=build
OBJ_DIR=$(BUILD_DIR)/obj

RES_DIR=resources

CXX_OBJS=$(subst .cpp,.o,$(subst $(SRC_DIR),$(OBJ_DIR),\
		 $(wildcard $(SRC_DIR)/*.cpp)))
C_OBJS=$(subst .c,.o,$(subst $(SRC_DIR),$(OBJ_DIR),$(wildcard $(SRC_DIR)/*.c)))
OBJS=$(CXX_OBJS) $(C_OBJS)

DEP=$(subst .o,.d,$(OBJS))

BIN=app

all: $(BIN)

run: all
	$(BUILD_DIR)/$(BIN)

$(BIN): prepare $(BUILD_DIR)/$(BIN)

$(BUILD_DIR)/$(BIN): $(OBJS)
	$(CXX) $(LFLAGS) $(DFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(DFLAGS) -MMD -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(DFLAGS) -MMD -c $< -o $@

prepare:
	@mkdir -p $(OBJ_DIR)
	@cd $(BUILD_DIR); ln -sf ../assets $(RES_DIR);


debug: DFLAGS=-g -DDEBUG
debug: clean all
ifeq ($(UNAME), Darwin)
	dsymutil $(BUILD_DIR)/$(BIN)
endif

.PHONY: clean

clean:
	@rm -rf $(DEP) $(OBJS) $(BUILD_DIR)/$(BIN) $(BUILD_DIR)/$(BIN).dSYM $(BUILD_DIR)/$(RES_DIR)

-include $(DEP)
