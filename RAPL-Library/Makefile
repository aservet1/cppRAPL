CFLAGS = -fPIC -g -c -Wall

CFILES = CPUScaler_noJNI.c arch_spec_noJNI.c msr_noJNI.c
OFILES = $(CFILES:.c=.o)

LIB = libCPUScaler.a
TARGET = $(LIB) $(OFILES)

all: library .gitignore

common:
	gcc $(CFLAGS) $(CFILES)

library: common
	ar -rc $(LIB) $(OFILES)
	ranlib $(LIB)

.gitignore: $(CXXFILES)
	cat </dev/null >@
	for t in $(TARGET); do echo $$t >>@; done


clean:
	rm -f $(OFILES) $(LIB)
