INCS= system.h base.h task.h queue.h smphr.h mutex.h

EXAMPLESDIR= examples
EXMPLS= simple semaphore queues
EXBINS= $(patsubst %,$(EXAMPLESDIR)/%,$(EXMPLS))

SYSTEM?= posix

SRCDIR= src
OBJDIR= objs
INCDIR= include/system

SRCS= $(wildcard $(SRCDIR)/$(SYSTEM)-*.c)
INCLUDES= $(patsubst %.h,$(INCDIR)/%.h,$(INCS))
OBJS= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

CC= gcc
LD= gcc
AR= ar

CFLAGS= -O0 -g
CFLAGS+= -Wall -Werror
CFLAGS+= -I $(INCDIR)/../ -I $(SRCDIR)
LDFLAGS= -lpthread -lrt

TARGET= $(OBJDIR)/libsystem.a

all: $(TARGET) $(EXBINS)

$(EXAMPLESDIR)/%: $(EXAMPLESDIR)/%.c $(TARGET) $(INCLUDES)
	$(CC) $< -o $@ $(CFLAGS) -lsystem $(LDFLAGS) -L $(OBJDIR)

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES) | $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(INCDIR)/%.h: $(SRCDIR)/%.h | $(INCDIR)
	cp $< $@

$(OBJDIR) $(INCDIR):
	mkdir -p $@

distclean: clean
	rm -rf $(INCDIR) $(OBJDIR)

clean:
	rm -f $(TARGET) $(OBJS) $(EXBINS)

.PHONY: clean all
