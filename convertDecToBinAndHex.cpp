#include <iostream>

using namespace std;

void convertToBits(int nr) {
    int mask = 1 << (sizeof(int)*8-1);
    cout << "The binary representation of the number " << nr << ": ";
    for(register unsigned int i = 1; i <= sizeof(int)*8; i++) {
        cout << (((nr & mask) == 0) ? "0" : "1");
        nr <<= 1;
        if(i%8 == 0) cout << " ";
    }
    cout << endl;
}

int main(void) {
    int nr;
    cout << "Insert a decimal number to be converted: ";
    cin >> nr;

    convertToBits(nr);
    cout << endl << "The hex representation of the number " << nr << ": " << hex << nr << endl;

    return 0;
}
