#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
    unsigned int a;
    cout << "VVedite chislo, chtobi poluchit' tablitsu umnozhenia do 20: ";
    cin >> a;
    int counter=0;
    int mul;
    while( counter < 200 )
    {
        counter++;
        mul=a*counter;
        cout << setiosflags(ios::left) << setw(10) << mul << " ";
        if(counter%10==0)
        {
        cout << endl;
        }
    }
    return 0;
}