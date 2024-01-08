# Makefile for Assignment 7 for 55613 C programming
#
# Li Yihai 23345919
# V 7.0
# 27-Nov-2023

# Compiler Collections
CC := gcc

# Flags
CFLAGS  := -Wall -Wextra
LDFLAGS := 
THREAD_FLAGS := -pthread

# Source files
SRCS 	:= matrix.c
OBJS 	:= $(SRCS:.c=.o)

# Executable targets
EXECS	 := assignment7a\
		 assignment7b

EXECS_PTHREAD := assignment7c

all: $(EXECS) $(EXECS_PTHREAD)

# Rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Generic rule for building executables
$(EXECS): %: %.c  $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Specific rule for assignment7c with pthread
$(EXECS_PTHREAD): %: %.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(THREAD_FLAGS)


.PHONY: all clean

clean:
	rm -f $(EXECS) $(EXECS:=.o) $(EXECS_PTHREAD) $(EXECS_PTHREAD:=.o) $(OBJS)

