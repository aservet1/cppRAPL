CXXFILES = main.cc #and also the one(s) that define(s) the sorting algorithms
TARGET = main

all: $(TARGET) .gitignore

$(TARGET): $(CXXFILES)
	g++ $(CXXFILES) -L./RAPL-Library -lCPUScaler -o $@

.gitignore: $(CXXFILES)
	cat </dev/null >$@
	for t in $(TARGET); do echo $$t >>$@; done

clean:
	rm -f $(TARGET)
