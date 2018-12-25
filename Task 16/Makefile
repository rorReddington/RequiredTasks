CC=g++ # компилятор
LDFLAGS= # флаги линковщика
CFLAGS=-c -std=c++11 # флаги компилятора
SOURCES= main.cpp complex.cpp # список исходников
OBJECTS=$(SOURCES:.cpp=.o)
TARGET= main # имя бинарника

all: $(TARGET)
    
$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp 
	$(CC) $(CFLAGS) $< 

include $(wildcard   *.d)

clean:
	rm *.o *.d $(TARGET)