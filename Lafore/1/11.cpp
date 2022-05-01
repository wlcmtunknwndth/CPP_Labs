#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setiosflags(ios::left) << setw(10) << "Name" << setw(10) << "Surname" << setw(15) << "Adress" << setw(15) << "City" << endl;
    cout << setfill('.') << setw(60) << "" << endl;
    cout << setiosflags(ios::left) << setfill(' ') << setw(10) << "Petrov" << setw(10) << "Vasilii" << setw(15) << "Klenovaya, 16" << setw(15) << "Saint-Petersburg" << endl;
    cout << setiosflags(ios::left) << setfill(' ') << setw(10) << "Ivanov" << setw(10) << "Sergei" << setw(15) << "Osinovaya, 3" << setw(15) << "Nahodka" << endl;
    cout << setiosflags(ios::left) << setfill(' ') << setw(10) << "Sidorov" << setw(10) << "Ivan" << setw(15) << "Berezovaya, 21" << setw(15) << "Kaliningrad" << endl;
    return 0;
}