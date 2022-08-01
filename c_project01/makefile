TARGET ?= run
OBJS := main.o addresslist.o mystring.o
cc := gcc
CFLAGS := -o
BINPATH := ./main/*.o ./addresslist/*.o ./mystring/*.o

vpath %.c addresslist main mystring
#VPATH= ./main/ ./addresslist/ ./mystring/

$(TARGET):$(OBJS)
	$(cc) $(BINPATH) $(CFLAGS) $(TARGET)

%.o:%.c
	make -C $*

.PHONY:clean
clean:
	rm -rf $(BINPATH) $(TARGET)

.PHONY:install
install:
	make
	mkdir executable
	mv run executable

.PHONY:uninstall
uninstall:
	rm -rf executable


