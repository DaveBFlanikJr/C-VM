SRC_FILES = ./src/main.c
# a list of compiler flags that will be passed to the compiler when compiling C source code.
#-Wall enables all warning messages.
#-Wextra enables additional warning messages.
#-g enables the generation of debugging information.
#-std=c11 sets the compiler to C11 mode.
CC_FLAGS = -Wall -Wextra -g -std=c11
CC = clang
all:
		${CC} ${SRC_FILES} ${CC_FLAGS} -o mac
