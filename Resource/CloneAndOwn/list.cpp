// RH 03-2011
// Usage of List-Container (clear, insert, delete-selected etc.)
// For Details see f.e. http://www.cplusplus.com/reference/stl

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

// Usage of "list" is sometimes tricky and requires some unexpected (!?)
// parentheses. So have a look at the example below:

// Class just for demo purpose
// gets a char in the constructor and gives it back by a method

class Demo {
  public: Demo(const char in);
  public: char get();  

  private: char mychar;
  static const int DEMO_NUMBER = 42;
};
Demo::Demo(char in) {this->mychar=in;}
char Demo::get() { return(this->mychar); }

//*******************************************************
int main(int argc, char *argv[])
{
    char tmpChar = 0;
    Demo* tmpDemo=0;
        
// Declare list and Iterator with same type
    list<Demo*> mylist;                 // Liste
    list<Demo*>::iterator j;            // Iterator vorwärts
    list<Demo*>::reverse_iterator rj;   // Iterator rückwärts
    list<Demo*>::iterator p;            // Iterator zum Löschen
    
// Make List empty    
    mylist.clear();

// Insert 10 characters from A to I as examples
    for (int i = 1; i < 10; i++) {
        tmpChar = i+'A'-1;
        tmpDemo = new Demo(tmpChar);
        mylist.push_back(tmpDemo);
    }

// Insert element at the beginning of the list 
        tmpChar = '<';
        tmpDemo = new Demo(tmpChar);  
        mylist.push_front(tmpDemo); 

// Insert element at the end of the list 
        tmpChar = '>';
        tmpDemo = new Demo(tmpChar);  
        mylist.push_back(tmpDemo);  

// Output of elements (forwards)
   cout << "Vorwaerts:   ";
   for(j=mylist.begin(); j != mylist.end(); j++) { 
        cout << (*j)->get() << " ";   
   };
   cout << "  Die Liste hat jetzt " << mylist.size() << " Elemente!" << endl;
   
// Output backwards
   cout << "Rueckwaerts: ";
   for(rj=mylist.rbegin(); rj != mylist.rend(); rj++) { cout << (*rj)->get() << " ";   }; 
   cout << "  Die Liste hat jetzt " << mylist.size() << " Elemente!" << endl;
    
// Delete element no. i (!!! It starts with No. 1!!!!)
   int Nr = 5;
   advance(p=mylist.begin(), Nr -1); // zeigt jetzt auf das Nr-te Element
   mylist.erase (p);

   cout << "ohne 5. El. :";
   for(j=mylist.begin(); j != mylist.end(); j++) { cout << (*j)->get() << " ";   }; 
   cout << "  Die Liste hat jetzt " << mylist.size() << " Elemente!" << endl;

// Delete an element by its content (i.e. in our case the pointer)
   cout << "ohne El. " << tmpDemo->get() <<":";   // Pointer still pointing to '>'
   mylist.remove (tmpDemo); 

   for(j=mylist.begin(); j != mylist.end(); j++) { cout << (*j)->get() << " ";   }; 
   cout << "  Die Liste hat jetzt " << mylist.size() << " Elemente!" << endl;

// Output once more

   cout << "Endergebnis: ";
   for(j=mylist.begin(); j != mylist.end(); j++) { cout << (*j)->get() << " ";   }; 
   cout << "  Die Liste hat jetzt " << mylist.size() << " Elemente!" << endl;

// Wait for any key   
   char c;
   cin >> c;
}
