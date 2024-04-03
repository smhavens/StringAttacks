CC	= MALLOC_CHECK_=0 gcc
CFLAGS	= -Wall -fno-stack-protector
LDFLAGS	= 
OBJFILES	= weak_coding.o
TARGET	= StringAttacks
# export MALLOC_CHECK_=0


all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
