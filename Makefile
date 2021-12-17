all:
	g++ rubixcube_serial.cpp -o rubixcube_serial
	g++ rubixcube_HDAstar.cpp -o rubixcube_HDAstar -fopenmp -ltbb
	g++ rubixcube_parallel.cpp -o rubixcube_parallel -fopenmp

clean:
	rm rubixcube_serial rubixcube_parallel rubixcube_HDAstar
