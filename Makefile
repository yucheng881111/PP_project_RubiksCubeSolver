all: serial serialm hdastar hdastarm hdapt para
serial: 
	g++ rubixcube_serial.cpp -o rubixcube_serial
serialm:
	g++ rubixcube_serial_measure.cpp -o rubixcube_serial_measure
hdastar:
	g++ rubixcube_HDAstar.cpp -o rubixcube_HDAstar -fopenmp -ltbb
hdastarm:
	g++ rubixcube_HDAstar_measure.cpp -o rubixcube_HDAstar_measure -fopenmp -ltbb
hdapt:
	g++ rubixcube_HDAstar_pthread.cpp -o rubixcube_HDAstar_pthread -lpthread -ltbb
para:
	g++ rubixcube_parallel.cpp -o rubixcube_parallel -fopenmp

clean:
	rm -f rubixcube_serial rubixcube_parallel rubixcube_HDAstar rubixcube_HDAstar_measure rubixcube_HDAstar_pthread rubixcube_serial_measure
