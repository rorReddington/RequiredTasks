CC=gcc # указываем компилятор
LDFLAGS= # флаги линковщика
CFLAGS=-c -std=c99 # флаги компилятора
SOURCES= main.c vector.c contacts.c # список исходников
OBJECTS=$(SOURCES:.c=.o)
TARGET=main  # имя бинарника

all: $(TARGET)

$(TARGET): $(OBJECTS)
$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
$(CC) $(CFLAGS) $<

include $(wildcard   *.d)

clean:
rm *.o *.d $(TARGET)
