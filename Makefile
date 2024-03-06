CC	= gcc
CFLAGS	= -Wall
LDFLAGS	=
OBJFILES	= secure_coding.o
TARGET	= StringAttacks

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
