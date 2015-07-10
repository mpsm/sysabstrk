SRCS= task.c queue.c system.c time.c
INCS= system.h system-config.h task.h queue.h time.h
OBJS= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

EXAMPLESDIR= examples
EXMPLS= simple
EXBINS= $(patsubst %,$(EXAMPLESDIR)/%,$(EXMPLS))

SYSTEM?= posix

SRCDIR= src/$(SYSTEM)
OBJDIR= objs

INCDIR= include/system
INCLUDES= $(patsubst %.h,$(INCDIR)/%.h,$(INCS))

CC= gcc
LD= gcc
AR= ar

CFLAGS= -O0 -g
CFLAGS+= -Wall -Werror
CFLAGS+= -I $(INCDIR)/../
LDFLAGS= -lpthread -lrt

TARGET= $(OBJDIR)/libsystem.a

all: $(TARGET) $(EXBINS)

$(EXAMPLESDIR)/%: $(EXAMPLESDIR)/%.c $(TARGET) $(INCLUDES)
	$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -L $(OBJDIR) -lsystem $(LDFLAGS)

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
