TARGET?=run
BINPATH:= ./main/*.o ./addresslist/*.o ./mystring/*.o
OBJS:= main.o addresslist.o mystring.o
CC:= gcc
CFLAGS:= -o

$(TARGET):$(OBJS)
	$(CC) $(BINPATH) $(CFLAGS) $(TARGET)

vpath %.c addresslist main mystring
#VPATH= ./addresslist/ ./main/ ./mystring/

%.o:%.c
	make -C $*

.PHONY:clean
clean:
	rm -rf $(BINPATH) $(TARGET)

