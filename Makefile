CXXFILES = main.cc #and also the one(s) that define(s) the sorting algorithms
TARGET = main
RAPL_LIBRARY = RAPL-Library/libCPUScaler.a

all: $(TARGET) .gitignore

$(TARGET): $(CXXFILES) $(RAPL_LIBRARY)
	g++ $(CXXFILES) -L./RAPL-Library -lCPUScaler main.hh -o $@

.gitignore: $(CXXFILES)
	cat </dev/null >$@
	for t in $(TARGET); do echo $$t >>$@; done

clean:
	rm -f $(TARGET)
