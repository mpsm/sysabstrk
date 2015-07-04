SRCS= task-posix.c queue-posix.c test.c
OBJS= $(patsubst %.c,%.o,$(SRCS))

CC= gcc
LD= gcc

CFLAGS= -O0 -g
LDFLAGS= -lpthread -lrt

TARGET= system-test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean all
