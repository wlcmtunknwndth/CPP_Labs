#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    cout << "Vvedite chislo desyatichnih funtov: " << (char)156;
    float decfunts;
    cin >> decfunts;

    cout << "\n" << static_cast<char>(156);

    int oldfunts=decfunts; //1
    cout << oldfunts << '.';
    
    float var=decfunts; 
    var-=oldfunts;
    float oldschilling=var*20; //2
    cout << oldschilling;
    
    return 0;
}