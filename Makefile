CXXFILES = main.cc #and also the one(s) that define(s) the sorting algorithms
HHFILES = SortingAlgorithms/*.hh *.hh
CXXFLAGS = -std=c++11
TARGET = main
RAPL_LIBRARY = RAPL-Library/libCPUScaler.a

all: $(TARGET) .gitignore

$(TARGET): $(CXXFILES) $(HHFILES)
	g++ -g $(CXXFILES) $(CXXFLAGS) -L./RAPL-Library -lCPUScaler -o $@

.gitignore: $(CXXFILES)
	cat </dev/null >$@
	for t in $(TARGET); do echo $$t >>$@; done

clean:
	rm -f $(TARGET)
