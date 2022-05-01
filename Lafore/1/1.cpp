#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
// zadanie 4. Pervaya glava. Past 3 are easy enough. See no point in wastin time but idk
int main()
{
    cout << "\n";
    cout << setw(10) << "\t whip it like its nascar\n" << setw(10) << "\t i can see the time past\n" << setw(10) << "\t feel like im in a high school\n" << setw(10) << "\t fuck me in a gym class\n";
    cout << "wanna continue?(y/n):";
    getch();
    int YorN=getch();
    if( YorN=='y' )
    {    
        cout << "\nthe song is lil peep gym class";
        exit(0);
    }
    if( YorN=='n')
        cout << "\nour tastes differ(";
    else
    {
        cout << "\nhold up, you used wrong symbol";
        main(); // recursia
        // cout << "try once again i didnt get it";
    }
    return 0;  
}