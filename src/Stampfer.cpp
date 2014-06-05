//@(#) Stampfer.cpp

#include "Stampfer.h"

void Stampfer::stampfe(int dauer) {
	for (int i= 0; i<dauer; i++) {
		cout << "# ";
		cout.flush();
		usleep(100000);
	}
}

Stampfer::Stampfer() {

}

