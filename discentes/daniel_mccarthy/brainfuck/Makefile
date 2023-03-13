# Makefile for BrainFuck interpreter

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra

SRCDIR = src
BINDIR = bin

TARGET = brainfuck

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BINDIR)/%.o)

.PHONY: all clean

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BINDIR)/%.o: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR):
	mkdir -p $@

clean:
	rm -rf $(BINDIR)

run: $(BINDIR)/$(TARGET)
	./$< $(PROGRAM)

