SRCS= task.c queue.c time.c smphr.c mutex.c
INCS= system.h system-config.h task.h queue.h time.h smphr.h mutex.h

EXAMPLESDIR= examples
EXMPLS= simple semaphore queues
EXBINS= $(patsubst %,$(EXAMPLESDIR)/%,$(EXMPLS))

SYSTEM?= posix
SRCS+= system-$(SYSTEM).c

SRCDIR= src/$(SYSTEM)
OBJDIR= objs
INCDIR= include/system

INCLUDES= $(patsubst %.h,$(INCDIR)/%.h,$(INCS))
OBJS= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

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

$(INCDIR)/%.h: $(SRCDIR)/../%.h | $(INCDIR)
	cp $< $@

$(OBJDIR) $(INCDIR):
	mkdir -p $@

distclean: clean
	rm -rf $(INCDIR) $(OBJDIR)

clean:
	rm -f $(TARGET) $(OBJS) $(EXBINS)

.PHONY: clean all
