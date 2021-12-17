TARGET := PPrubix
CPP := PPrubix.cpp

CXX := g++
CFLAGS := -fopenmp
CFLAGS2 := -ltbb
THREAD := -pthread

all: $(CPP)
	$(CXX) $(CPP) -o $(TARGET) $(CFLAGS)

clean:
	rm $(TARGET)
