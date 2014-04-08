// Main.cpp 
// Programm zum Testen der Methodenaufrufe des Rezeptbuchs aus dem SWE Praktikum im WS 2013 
// Ralf Hahn,  04.10.2013

#include "Rezeptbuch.h"

#include <iostream>
using namespace std;
#include <iomanip>

int main() {

    int i = 0;

    // das Rezeptbuch anlegen
    Rezeptbuch* MyRezeptbuch = new Rezeptbuch;


    // Rezeptliste ausgeben
    cout << "*********************************************" << endl;
    cout << "Es gibt " << MyRezeptbuch->getAnzahlRezepte() << " Cocktails" << endl;

    for (i = 0; i < MyRezeptbuch->getAnzahlRezepte(); i++) {
        Rezept* r = MyRezeptbuch->getRezept(i);
        cout << i << ". " << r->getName() << endl;
    }
    cout << "*********************************************" << endl;

    // Rezeptschritte abfragen

    for (i = 0; i < MyRezeptbuch->getAnzahlRezepte(); i++) // f�r jedes Rezept...
    {
        cout << endl << endl;
        // Cocktailname als �berschrift
        Rezept* r = MyRezeptbuch->getRezept(i);
        cout << "**** " << r->getName() << " ****" << endl;

        for (int j = 0; j < r->getAnzahlRezeptschritte(); j++) // f�r jeden Rezeptschritt...
        {
            Rezeptschritt* rs = r->getRezeptSchritt(j);
            float Menge = rs->getMenge();
            string Zutat = rs->getZutat();

            cout << j << ". " << ": " << setw(15) << Zutat << "\t" << Menge << endl;
        }
    }

    // Rezept loeschen
    cout << "*********************************************" << endl;
    cout << "Teste das Loeschen von Rezepten!" << endl;
    cout << "Es gibt " << MyRezeptbuch->getAnzahlRezepte() << " Cocktails" << endl;
    MyRezeptbuch->deleteRezept(2);
    cout << "Jetzt gibt es ein Rezept weniger, naemlich: " <<
            MyRezeptbuch->getAnzahlRezepte() << " Cocktails" << endl;


    //char c;
    //cin >> c;

    delete MyRezeptbuch;

    return 1;
}
