#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
    float finaltemp;
    char switcher;
    cout << "\n" << "Nazhmite 1 dlya perevoda iz shkali Celsiya v Fahrenheita, Nazhmite 2 dlya perevoda iz Fahrenheita v shkalu Celsiya: ";
    getch();
    switcher=getch();
    switch(switcher)
    {
        case '1': 
            float TempFahr;
            cout << "\n" << "Vvedite temperaturu v Gradusah Celsiya: ";
            cin >> TempFahr;
            finaltemp=TempFahr*(9/5)+32;
            cout << "\n" << "Temperatura v gradusah Fahrenheita: " << finaltemp << endl;
            break;
        case '2':
            float TempCelsium;
            cout << "\n" << "VVedite temperaturu v gradusah Fahrenheita: ";
            cin >> TempCelsium;
            finaltemp=(TempCelsium-32)*5/9;
            cout << "\n" << "Temperatura v gradusah Celsiya: " << finaltemp << endl;
            break;
        default:
            cout << "\n" << "Net takogo varianta";
            cout << "\n" << "Povtorit'?(y/n) ";
            char yorn;
            getch();
            yorn=getch();
            switch(yorn)
            {
                case 'y':
                    main();
                    break;
                case 'n':
                    break;
                default:
                    cout << "Try once again, an unexpected result"; 
            }
