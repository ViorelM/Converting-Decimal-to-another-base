#include <iostream>
#include <math.h>

using namespace std;

unsigned short L;

unsigned short lungime(char c[]) {
    register unsigned short i = 0;
    while(c[++i] != 0) ;
    return i;
}

int kToZecimal(char n[], short bazaInitiala) {
    register short i = 0;
    int s = 0;
	
	L = lungime(n);

    while(n[i] != 0) {
        if(n[i] <= '9')
            s = s + ((int)n[i] - 48) * pow(bazaInitiala, L - 1 - i);
        else
            s = s+((int)n[i] - 87) * pow(bazaInitiala, L - 1 - i);
        i++;
    }
    return s;
}

inline double abs(double n) {
    if(n<0) return n*(-1);
    else
    return n;
}

void ZecimalToK(register int nr, int bazaFinala) {
        const string numerele("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");//pina in baza 36
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


    getwchar();
    /*folosesc 2 de astea pentru ca la prima se umple asa zisul Buffer cu
    textul returnat la ecran(in caz ca te intreaba)*/

    getwchar();//functie ce face parte din iostream.h
    //am inlocuit _getch() cu astea pentru ca sa poti compila programul si pe alte sisteme de operare

    return 0;
}
