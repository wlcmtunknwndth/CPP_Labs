#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Enter num of funts: ";
    float funt; 
    cin >> funt;
    
    cout << "\n" << "Enter num of schilligs: ";
    float schilling;
    cin >> schilling;

    cout << "\n" << "Enter num of pens: ";
    float pens;
    cin >> pens;
    
    schilling/=20;
    pens/=20*12;
    funt+=schilling+pens;
    int funtsym=156;
    cout << (char)funtsym << funt;
    return 0;
}