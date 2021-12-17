


#include <iostream>
#include <string>
using namespace std;



string Cezar(string Slowo, int Przesuniecie = 0) {
    char alfabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    if (Przesuniecie == 0) {
        cout << "Przesuniecie: ";
        cin >> Przesuniecie;
    }

    string o = "";

    int a;
    if (Przesuniecie > 25 || Przesuniecie < 0) {
        return "Przesuniecie niepoprawne";
    }
    for (char& b : Slowo) {
        a = int(b) + Przesuniecie;
        b = a % ('z' + 1);
        if (b > 'a' - 1) {
            o += b;
        }
        else {
            o += b + 'a';
        }
    }
    return o;
}

string Przestawienie(string Slowo) {

    char o;
    for (int x = 0; x < Slowo.length(); x += 2) {
        o = Slowo[x + 1];
        Slowo[x + 1] = Slowo[x];
        if (o) {
            Slowo[x] = o;
        }
    }
    return Slowo;
}

void Deszyfracja(string Slowo) {
    for (int i = 1; i < 26; i++) {
        cout << "Przesuniecie- " << i << " Slowo- " << Cezar(Slowo, i) << endl;
    }
}

string Oba(string Slowo) {
    return Cezar(Przestawienie(Slowo));
}

int main() {
    string Slowo;
    char option;

    cout << "Slowo: ";
    getline(cin, Slowo);

    cout << "Co chcesz zrobic? 1 - Szyfr Cezara, 2 - Szyfr Przestawieniowy, 3 - Deszyfracja, 4 - Oba" << endl;


    cin >> option;

    switch (option)
    {
    case '1':
        cout << Cezar(Slowo) << endl;
        break;

    case '2':
        cout << Przestawienie(Slowo) << endl;
        break;

    case '3':
        Deszyfracja(Slowo);
        break;

    case '4':
        cout << Oba(Slowo) << endl;
        break;

 

    default:

        cout << "Niepoprawna cyfra" << endl;
        break;
    }
}