CXXFILES = main.cpp #and also the one(s) that define(s) the sorting algorithms
TARGET = main

all: $(CXXFILES)

$(TARGET): $(CXXFIELS)
	g++ $(CXXFILES) -L./RAPL-Library -lCPUScaler -o $@
	echo $(TARGET) >> .gitignore

clean:
	rm -f $(TARGET)
