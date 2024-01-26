#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>  // Include for rand function
using namespace std;

string blue = "\u001b[34m";
string reset = "\u001b[0m";
string bold = "\u001b[1m";

#define NUMEROS     100
#define COLUNAS     10
#define DELAY       1000000 //1 segundo
#define MODO_AUTO   false

void clearScreen() {
    cout << "\033[2J\033[1;1H" << flush;
}

int geraNumero(){
    return rand() % NUMEROS + 1;
}

void geraChave(int chave[]){
    int i = 0, j = 0, aux = 0;
    bool repetido = false;
    while(i < NUMEROS){
        aux = geraNumero();
        for(j = 0; j < i; j++){
            if(aux == chave[j]){
                repetido = true;
                break;
            }
        }
        if(!repetido){
            chave[i] = aux;
            i++;
        }
        repetido = false;
    }
}

void mainmenu() {
    cout << blue << bold << "E S C O L H A    A    O P Ç Â O: \n" << reset
         << blue << "--------------------------\n" 
         << "1 - Sorteio Automático\n"
         << "2 - Sorteio Manual\n"
         << "3 - Gerar Cartões\n"
         << "4 - Sair\n"
         << "--------------------------\n"
         << bold << "O P Ç Ã O: "
         << reset;
}

int main() {
    int bingotype;
    int quantity;

    do {
        clearScreen();
        mainmenu();
        cin >> bingotype;
        
        if (bingotype == 1) {
            clearScreen(); 
            cout << "You selected 'Automatic Draw'" << endl;
            cout << "Enter the quantity of numbers for the draw (75, 90, 100): ";
            cin >> quantity;

            if ((quantity == 75) || (quantity == 90) || (quantity == 100)) {
                cout << "You entered one of the allowed numbers." << endl;
            } else {
                cout << "Invalid input. The number must be 75, 90, or 100." << endl;
            }
        } else if (bingotype == 2) {
            cout << "You selected 'Manual Draw'" << endl;
        } else if (bingotype == 3) {
            cout << "You selected 'Generate Cards'" << endl;
        } else if (bingotype == 4) {
            cout << "Exiting..." << endl;
            return 0;
        } else {
            cout << "Invalid Answer, try again or press '4' to quit" << endl;
            break;
        }

    } while (true);


    do {
        cout << "\033[2J\033[1;1H"; // Clear the screen
        int chave[NUMEROS];
        geraChave(chave);

        // Display numbers sequentially with a 1-second pause
        for(int i = 0; i < NUMEROS; i++){
            cout << chave[i];
            usleep(DELAY);
            cout << "\t" << flush; 
            if((i + 1) % COLUNAS == 0){
                cout << endl;
            }
        }
        cout << endl;
        cout << "Do you want to generate another bingo sequence? (1 for yes, 0 for no): ";
        cin >> bingotype;
    } while (bingotype == 1);

    return 0;
}
