all: serial hdastar hdastartm hdapt para

serial:
	g++ rubixcube_serial.cpp -o rubixcube_serial
hdastar:
	g++ rubixcube_HDAstar.cpp -o rubixcube_HDAstar -fopenmp -ltbb
hdastartm:
	g++ rubixcube_HDAstar_measure.cpp -o rubixcube_HDAstar_measure -fopenmp -ltbb
hdapt:
	g++ rubixcube_HDAstar_pthread.cpp -o rubixcube_HDAstar_pthread -fopenmp -ltbb
para:
	g++ rubixcube_parallel.cpp -o rubixcube_parallel -fopenmp

clean:
	rm -f rubixcube_serial rubixcube_parallel rubixcube_HDAstar rubixcube_HDAstar_measure
