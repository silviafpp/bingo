#include <iostream>
using namespace std;

// Variables for text formatting
string red = "\u001b[31m";
string blue = "\u001b[34m";
string reset = "\u001b[0m";
string bold = "\u001b[1m";

void mainmenu() {
    int bingotype;
    cout << blue << bold << "E S C O L H A    A    O P Ç Â O: \n" << reset
         << blue << "--------------------------\n" 
         << "1 - Sorteio Manual\n"
         << "2 - Sorteio Automático\n"
         << "3 - Gerar Cartões\n"
         << "4 - Sair\n"
         << "--------------------------\n"
         << bold << "O P Ç Ã O: "
         << reset;
    cin >> bingotype;

    if (bingotype == 1) {
        cout << "You selected 'Sorteio Manual'"<< endl;
    }
}