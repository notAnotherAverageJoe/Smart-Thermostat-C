# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Target executable name
TARGET = thermostat

# Source files
SRCS = main.c heating.c cooling.c thermostat.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
