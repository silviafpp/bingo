#include <iostream>
#include <iomanip>
using namespace std;

string red = "\u001b[31m";
string blue = "\u001b[34m";
string reset = "\u001b[0m";
string bold = "\u001b[1m";

void clearScreen() {
cout << "\033[2J\033[1;1H" << flush;
}

void mainmenu() {
    cout << blue << bold << "E S C O L H A    A    O P Ç Â O: \n" << reset
         << blue << "--------------------------\n" 
         << "1 - Sorteio Manual\n"
         << "2 - Sorteio Automático\n"
         << "3 - Gerar Cartões\n"
         << "4 - Sair\n"
         << "--------------------------\n"
         << bold << "O P Ç Ã O: "
         << reset;
}

int main() {
    int bingotype, quantity;
    do {
        clearScreen();
        mainmenu();
        cin >> bingotype;
        
        if (bingotype == 1) {
            clearScreen(); // Clearing the screen before displaying the next message
            cout << "You selected 'Sorteio Manual'" << endl;
            cout << "Escolha a quantidade de números para o sorteio (75, 90, 100): ";
            cin >> quantity;
            // You can add validation here to ensure quantity is one of the given options
            cout << "Quantity set to: " << quantity << endl;
        } else if (bingotype == 2) {
            cout << "You selected 'Sorteio Automático'" << endl;
        } else if (bingotype == 3) {
            cout << "You selected 'Gerar Cartões'" << endl;
        } else if (bingotype == 4) {
            cout << "Exiting..." << endl;
            return 0;
        } else {
            cout << "Invalid Answer, try again or press '4' to quit" << endl;
        }
    } while (true);
}
