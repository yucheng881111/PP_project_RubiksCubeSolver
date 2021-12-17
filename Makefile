TARGET := PPrubix_concurrent
CPP := PPrubix_concurrent.cpp

CXX := g++
CFLAGS := -fopenmp
CFLAGS2 := -ltbb
THREAD := -pthread

all: $(CPP)
	$(CXX) $(CPP) -o $(TARGET) $(CFLAGS) $(CFLAGS2)

clean:
	rm $(TARGET)
