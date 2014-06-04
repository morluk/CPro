//@(#) Stampfer.cpp

#include "Stampfer.h"

void Stampfer::stampfe(int dauer) {
	//TODO: eventl Ausgabe ueber UI, dann Referenz auf Controller noetig
	for (int i= 0; i<dauer; i++) {
		cout << "# ";
		cout.flush();
		usleep(100000);
	}
}

Stampfer::Stampfer() {

}

