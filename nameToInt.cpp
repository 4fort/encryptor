#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main() {
    srand(time(0));

    string name;
    string encrypted;
    static int *key = new int[name.length()];
    string keyChar;
    string decrypted;

    cout << "Enter your name: ";
    getline(cin, name);
    system("cls");

    cout << "\t\t\t\t\t***** ORIGINAL INPUT *****\n\n";
    cout << "Decimal : ";
    for(char x: name) {
        cout << (int) x << "\t";
    }
    cout << "\nCharacter : " << name << "\n\n\n"; // print inputed name

    // ENCRYPTION HAPPENS
    for(int x = 0; x < name.length(); x++) {
        key[x] = rand() % 99; // random numbers
        encrypted = encrypted + (char)((int) name[x] + key[x]);
    }

    // PRINTING CODES
    cout << "\t\t\t\t\t***** ENCRYPTED INPUT *****\n\n";
    cout << "Decimal : ";
    for(char x: encrypted) {
        cout << (int)x << "\t";
    }
    cout << "\nCharacter : " << encrypted << "\n\n\n"; // print encrypted name
    
    
    cout << "\t\t\t\t\t***** GENERATED KEY *****\n\n";
    cout << "Decimal : ";
    for(int x = 0; x < name.length(); x++) {
        cout << key[x] << "\t";
        keyChar = keyChar + (char)key[x];
    }
    cout << "\nCharacter : " << keyChar << "\n\n\n"; // print generated key character name

    // DECRYPTION HAPPENS
    cout << "\t\t\t\t\t***** DECRYPTED INPUT *****\n\n";
    cout << "Decimal : ";
    for(int x = 0; x < name.length(); x++) {
        decrypted = decrypted + (char)((int) encrypted[x] - key[x]);
        cout << (int)decrypted[x] << "\t";
    }
    cout << "\nCharacter : " << decrypted; // print decrypted name
}