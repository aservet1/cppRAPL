CFLAGS = -fPIC -g -c -Wall

CFILES = CPUScaler_noJNI.c arch_spec_noJNI.c msr_noJNI.c #front-page.c
OFILES = $(CFILES:.c=.o)
HFILES = $(CFILES:.c=.h)

LIB = libCPUScaler.a
TARGET = $(LIB) $(OFILES)

all: lib_shared_CPUScaler

common:
	gcc $(CFLAGS) $(CFILES)

lib_shared_CPUScaler: common
	ar -rc $(LIB) $(OFILES)
	ranlib $(LIB)

clean:
	rm -f *.o $(TARGET)

#########################################################################################################################################################################
#TARGET = libCPUScaler.so CPUScaler_TimingUtils.o CPUScaler.o arch_spec.o msr.o dvfs.o
#CFLAGS = -fPIC -g -c -Wall
#JAVAHOME=${JAVA_HOME}
#JAVA_INCLUDE = $(JAVAHOME)/include
#JAVA_INCLUDE_LINUX = $(JAVA_INCLUDE)/linux
#
#all: lib_shared_CPUScaler
#
#common:
#	gcc $(CFLAGS) -I $(JAVA_INCLUDE) -I$(JAVA_INCLUDE_LINUX) CPUScaler_TimingUtils.c CPUScaler.c arch_spec.c msr.c dvfs.c
#
#lib_shared_CPUScaler: common
#	gcc -g -Wall -I $(JAVA_INCLUDE) -I $(JAVA_INCLUDE_LINUX) -shared -Wl,-soname,libCPUScaler.so -o libCPUScaler.so CPUScaler_TimingUtils.o CPUScaler.o arch_spec.o msr.o dvfs.o -lc
#
#clean:
#	rm -f lib_share_CPUScaler $(TARGET)
########################################################################################################################################################################
