CFLAGS = -fPIC -g -Wall

CFILES = CPUScaler_noJNI.c arch_spec.c msr.c front-page.c
OFILES = $(CFILES:.c=.o)
HFILES = $(CFILES:.c=.h)

TARGET = hello

all: $(CFILES) $(OFILES) $(HFILES)
	g++ $(CFLAGS) -o $(TARGET) $(CFILES) -lm

clean:
	rm -f *.o $(TARGET)
