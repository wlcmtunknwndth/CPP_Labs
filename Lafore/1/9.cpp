#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main()
{
    float chisl1; 
    float chisl2; 
    float znam1; 
    float znam2;
    
    cout << "vvedite pervuyu drob': \n";
    cin >> chisl1;
    int a=chisl1;
    while(a % 10 != 0)
    {
        a/=10;
        cout<< '-'; 
    }
    cout << "\n";
    cin >> znam1;
    cout << "\n";

    cout << "vvedite vtoryuy drob': \n";
    cin >> chisl2;
    int b=chisl2;
    while(b % 10 != 0)
    {
        b/=10;
        cout<< '-'; 
    }
    cout << "\n";
    cin >> znam2;
    cout << "\n";

    float sum;
    sum=(chisl1*znam2+chisl2*znam1)/(znam1* znam2);
    cout << "the sum of your drobeyi: " << sum;
}