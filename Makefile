SRCS= task.c queue.c system.c time.c
OBJS= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

EXAMPLESDIR= examples
EXMPLS= simple
EXBINS= $(patsubst %,$(EXAMPLESDIR)/%,$(EXMPLS))

SYSTEM?= posix

SRCDIR= src/$(SYSTEM)
OBJDIR= objs

CC= gcc
LD= gcc
AR= ar

CFLAGS= -O0 -g
CFLAGS+= -Wall -Werror
CFLAGS+= -I src
LDFLAGS= -lpthread -lrt

TARGET= $(OBJDIR)/libsystem.a

all: $(TARGET) $(EXBINS)

$(EXAMPLESDIR)/%: $(EXAMPLESDIR)/%.c $(TARGET)
	$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -L $(OBJDIR) -lsystem

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -f $(TARGET) $(OBJS) $(EXBINS)

.PHONY: clean all
