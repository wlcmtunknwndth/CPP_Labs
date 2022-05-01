#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(10) << "Moscow" << setw(20) << setfill('.') << 12000000 << endl;
    return 0;
}