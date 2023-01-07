SHELL := /bin/bash

PROJECT_NAME	=c_stack
TEST_NAME		=Test
O_DIR 			= obj
TEST_DIR		= Tests

LIB_SRC_DIR		= source
LIB_INC_DIR		= include
LIB_O_DIR		= $(O_DIR)/$(LIB_SRC_DIR)

TEST_SRC_DIR	= $(TEST_DIR)
TEST_INC_DIR	= $(LIB_INC_DIR)
TEST_O_DIR		= $(O_DIR)/$(TEST_SRC_DIR)

BUILD_DIR		= ../build
UNAME_S 		:= $(shell uname -s)
TEST_SRC		= $(TEST_DIR)/${PROJECT_NAME}_test.c
Flags 			= -std=c11 -Werror -Wall -Wextra $(Debug)
gcc 			= gcc $(Flags)
LIB_SOURCES		= $(shell find $(LIB_SRC_DIR) -name '*.c')
TEST_SOURCES	= $(shell find $(TEST_SRC_DIR) -name '*.c')
REPORT_FILES	= $(shell find . -name '*.gcno') $(shell find . -name '*.gcda')
LIB_OBJ 		= $(patsubst %.c,$(O_DIR)/%.o, $(LIB_SOURCES))
TEST_OBJ 		= $(patsubst %.c,$(O_DIR)/%.o, $(TEST_SOURCES))
OBJ				= $(LIB_SOURCES)
OBJ				+=  $(TEST_OBJ)
# DEBUG_SOURCE= main.c
DEBUG_SOURCE= $(TEST_SRC)

ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck
	OPEN_CMD = xdg-open
	ADD_LIB = -lm -lrt -lpthread
endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
	ADD_LIB =
endif

$(LIB_O_DIR)/%.o: $(LIB_SRC_DIR)/%.c
	$(gcc) -I${LIB_INC_DIR} $< -c -o $@

$(TEST_O_DIR)/%.o: $(TEST_SRC_DIR)/%.c 
	$(gcc) -I${LIB_INC_DIR} -I${TEST_INC_DIR} $< -c -o $@

all: clear $(PROJECT_NAME).a
clear:
	clear
clean:
	rm -rf *.out $(shell find ./obj -name '*.o')
	rm -rf *.a
obj: $(OBJ)
debug:
	$(eval Debug = -g)
	@echo Debug build
clang:
	clang-format --style=Google -n *.c *.h ./*/*.c ./*/*.h
clang-replace:
	clang-format --style=Google -i *.c *.h ./*/*.c ./*/*.h
$(BUILD_DIR)/$(PROJECT_NAME).a: $(LIB_OBJ)
	ar rcs $@ $^
$(PROJECT_NAME).a: $(BUILD_DIR)/$(PROJECT_NAME).a

$(BUILD_DIR)/$(TEST_NAME).a: $(TEST_OBJ)
	ar rcs $@ $^
$(TEST_NAME).a: $(BUILD_DIR)/$(TEST_NAME).a

test: set_test $(PROJECT_NAME)

main: set_main $(PROJECT_NAME)

set_main:
	$(eval DEBUG_SOURCE = main.c)
	$(eval TEST_CHECK_F = )

set_test:
	$(eval DEBUG_SOURCE = $(TEST_SRC))


$(PROJECT_NAME): $(BUILD_DIR)/$(PROJECT_NAME).a $(BUILD_DIR)/$(TEST_NAME).a
	$(gcc) $(DEBUG_SOURCE) -I${LIB_INC_DIR} -I${TEST_INC_DIR} -o $@ ${TEST_CHECK_F} $^

.PHONY: clear clean obj debug clang clang-replace $(BUILD_DIR)/$(PROJECT_NAME).a $(PROJECT_NAME).a test main $(PROJECT_NAME) all