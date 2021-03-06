//@(#) UserInterface.cpp

#include "UserInterface.h"

void UserInterface::update() {
    if (cocktailProController->activeType
            == cocktailProController->DOSIERSTATION) {
        cout << "Delta: " << this->waage->getDeltaGewicht() << " g" << endl;
    } else {
        cout << "Gesamtgewicht: " << this->waage->getAbsolutGewicht() << " g"
                << endl;
    }
}

void UserInterface::setWaage(Waage* waage) {
    this->waage = waage;
}

UserInterface::UserInterface() {
    cout << "******************************" << endl;
    cout << "*     CocktailPro v1.0       *" << endl;
    cout << "*                            *" << endl;
    cout << "*     by Hilberg/Koehler     *" << endl;
    cout << "******************************" << endl;
    this->waage = 0;

    cout << "Waehlen Sie einen Modus" << endl;
    cout << "1: Normale Geschwindigkeit" << endl;
    cout << "2: Turbo Modus" << endl;
    cout << "Auswahl: ";
    char auswahl;
    int intAuswahl;
    do {
        do {
            cin >> auswahl;
        } while (!isdigit(auswahl));

        intAuswahl = auswahl - 48;
    } while (intAuswahl < 1 || intAuswahl > 2);
    
    if (intAuswahl == 1) {
        turbo = false;
    } else {
        turbo = true;
    }
    
    this->cocktailProController = new CocktailProController(this);

        this->showMenu();
}

void UserInterface::showMenu() {
    char auswahl;
    string mischbareRezepte =
            this->cocktailProController->mischbareRezepteToString();
    vector<string> einzelneRezepte;
    stringstream rezepteStream;
    rezepteStream << mischbareRezepte;
    string tempRezept;
    while (!rezepteStream.eof()) {
        getline(rezepteStream, tempRezept, ';');
        if (tempRezept != "") {
            einzelneRezepte.push_back(tempRezept);
        }
    }
    while (true) {
        cout << "\n";
        cout << "===CocktailPro v1.0===\n";
        cout << "   ===Hauptmenu===\n";
        cout << "\n";
        cout << "Es stehen " << einzelneRezepte.size()
                << " Cocktails zur Verfuegung.\n";
        cout << "\n";
        for (unsigned int i = 0; i < einzelneRezepte.size(); i++) {
            cout << i + 1 << ": " << einzelneRezepte[i] << "\n";
        }
        cout << "Bitte Auswahl treffen['0' zum Verlassen]:\n";
        do {
            cin >> auswahl;
            cin.ignore(1000, '\n');
        } while (!isdigit(auswahl));

        switch (auswahl) {
            case '0':
                exit(0);
            default:
                unsigned int w = auswahl - 48;
                if (w > 0 && w <= einzelneRezepte.size()) {
                    cout << endl << einzelneRezepte[w - 1] << " wird zubereitet."
                            << endl << endl;
                    this->cocktailProController->mischeRezept(w - 1);
                } else {
                    cout << "Ungueltige Eingabe!\n";
                }
        }
    }

}

UserInterface::~UserInterface() {

}

CocktailProController* UserInterface::getCocktailProController() {
    return this->cocktailProController;
}