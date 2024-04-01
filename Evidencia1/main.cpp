#include <iostream>
#include "scanner.h"

using namespace std;

int main() {
    reader mcode = reader("mcode1.txt");
    Scanner t1 = Scanner("transmission1.txt");
    Scanner t2 = Scanner("transmission2.txt");
    

    cout << endl;

    cout << "Finding longest common substring between transmission 1 and 2..." << endl;
    t1.longestCommonSubstring({t1.getString(), t2.getString()});
    cout << endl;

    cout << "Checking if transmission 1 is malicious..." << endl;
    bool isMalicious = t1.isMalicious(mcode);
    isMalicious ? cout << "Transmission 1 is malicious" : cout << "Transmission 1 is not malicious";
    
    cout << "\n\n";

    cout << "Checking if transmission 2 is malicious..." << endl;
    isMalicious = t2.isMalicious(mcode);
    isMalicious ? cout << "Transmission 2 is malicious" : cout << "Transmission 2 is not malicious";
    
    return 0;
}
