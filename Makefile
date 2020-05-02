CXXFILES = main.cpp #and also the one(s) that define(s) the sorting algorithms
TARGET = main

all: $(TARGET)

$(TARGET): $(CXXFIELS)
	g++ $(CXXFILES) -L./RAPL-Library -lCPUScaler -o $@

clean:
	rm -f $(TARGET)
