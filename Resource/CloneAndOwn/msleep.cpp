// Mario Shraiki 2005
// Wait for PC and SUN

#include <ctime>

//selbsterklärend.....
void msleep ( long milliseconds ) {
  clock_t limit;
  clock_t now = clock();
  limit = now + milliseconds * CLOCKS_PER_SEC /1000;
  while ( limit > now )
  now = clock();
}


#include <iostream>
using namespace std;

int main ()
{
	int w=1000;
	cout <<"Jetzt geht's los" << endl;
	msleep(w);
	cout<< w << " Millisekunden spaeter..." << endl;
   return 0;
}
