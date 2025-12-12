CC = gcc
CFLAGS = -O2
TARGET = vm_fault

all: $(TARGET)

$(TARGET): vm_fault.c
	$(CC) $(CFLAGS) -o $(TARGET) vm_fault.c

clean:
	rm -f $(TARGET)