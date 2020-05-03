CXXFILES = main.cc #and also the one(s) that define(s) the sorting algorithms
CXXFLAGS = -std=c++11
TARGET = main

all: $(TARGET) .gitignore

$(TARGET): $(CXXFILES)
	g++ $(CXXFILES) $(CXXFLAGS) -L./RAPL-Library -lCPUScaler main.hh -o $@

.gitignore: $(CXXFILES)
	cat </dev/null >$@
	for t in $(TARGET); do echo $$t >>$@; done

clean:
	rm -f $(TARGET)
