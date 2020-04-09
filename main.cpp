#include <iostream>
#include <fstream>

#include "automaton.h"

using namespace std;

 int main() {

    char filename[20] = {"Int1-3-1.txt"} ;

    automaton A ;

    getfile(filename,A) ;

    display(A,7,3);

    cout << endl << endl << endl ;

    return 0 ;

}

