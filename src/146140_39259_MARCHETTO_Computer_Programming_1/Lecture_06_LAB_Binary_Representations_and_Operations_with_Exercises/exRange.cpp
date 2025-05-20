using namespace std;
#include <iostream>

int main(){
    cout << "unsigned int: " << sizeof(unsigned int) << endl;
    unsigned int a;
    a = 0b00000000'00000000'00000000'00000000; cout << " - Mininum: " << a << endl;
    a = 0b11111111'11111111'11111111'11111111; cout << " - Maxinum: " << a << endl;

    cout << "int: " << sizeof(int) << endl;
    int b;
    b = 0b10000000'00000000'00000000'00000000; cout << " - Mininum: " << b << endl;
    b = 0b01111111'11111111'11111111'11111111; cout << " - Maxinum: " << b << endl;

    cout << "unsigned short: " << sizeof(unsigned short) << endl;
    unsigned short c;
    c = 0b00000000'00000000; cout << " - Mininum: " << c << endl;
    c = 0b11111111'11111111; cout << " - Maxinum: " << c << endl;

    cout << "short: " << sizeof(short) << endl;
    short d;
    d = 0b10000000'00000000; cout << " - Mininum: " << d << endl;
    d = 0b01111111'11111111; cout << " - Maxinum: " << d << endl;

    cout << "unsigned long: " << sizeof(unsigned long) << endl;
    unsigned long e;
    e = 0b00000000'00000000'00000000'00000000; cout << " - Mininum: " << e << endl;
    e = 0b11111111'11111111'11111111'11111111; cout << " - Maxinum: " << e << endl;
    
    cout << "long: " << sizeof(long) << endl;
    long f;
    f = 0b10000000'00000000'00000000'00000000; cout << " - Mininum: " << f << endl;
    f = 0b01111111'11111111'11111111'11111111; cout << " - Maxinum: " << f << endl;

    return 0;
}