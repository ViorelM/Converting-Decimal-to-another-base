#include <iostream>
#include <math.h>

using namespace std;

int kToZecimal(char n[], short bazaInitiala) {
    register short i = 0;
    unsigned short length = 0;
    int s = 0;

    while (n[++length] != (char) NULL); //calculating string length
    
    while (n[i] != (char) NULL) {
        if (n[i] <= '9') {
            s += ((int) n[i] - 48) * pow(bazaInitiala, length - 1 - i);
        } else {
            s += ((int) n[i] - 87) * pow(bazaInitiala, length - 1 - i);
        }
        i++;
    }
    return s;
}

inline double abs(double n) {
    if (n < 0) {
        return n * (-1);
    } else {
        return n;
    }
}

void ZecimalToK(register int nr, int bazaFinala) {
    const string numerele("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"); //pana in baza 36
    bool is_neg = nr < 0;
    string rezultatul;

    for (; nr; nr /= bazaFinala)
        rezultatul.insert(rezultatul.begin(), numerele[abs(nr % bazaFinala)]);

    if (is_neg)
        rezultatul.insert(rezultatul.begin(), '-');

    cout << rezultatul << endl; //afisarea rezultatului final
}

inline void Conversie(char nr[], int bazaInitiala, int bazaFinala) {
    ZecimalToK(kToZecimal(nr, bazaInitiala), bazaFinala);
}

int main(void) {
    char Numarul[100];
    cin >> Numarul;
    Conversie(Numarul, 10, 2);
    //Conversie(Numarul, [baza in care e numarul initial], [baza in care tre transformat])
    return 0;
}
