CC = g++

CFLAGS = -g -Wall -lm

TARGET = nsysconv

all : $(TARGET)

$(TARGET) : nsysconv.o convertor.o 
	$(CC) $(CFLAGS) -o $(TARGET) nsysconv.o convertor.o 
	$(RM) *.o
nsysconv.o : src/nsysconv.cpp src/convertor.h
	$(CC) $(CFLAGS) -c src/nsysconv.cpp

convertor.o : src/convertor.cpp src/convertor.h
	$(CC) $(CFLAGS) -c src/convertor.cpp
clean : 
	$(RM) $(TARGET) *.o *~