#include "graphics.h"
#include <stdlib.h>
#include <time.h>
int main(){
    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");

    srand(time(NULL));
    for(int i=0; i < 100; i++)
        line(rand()%1024,rand()%800,rand()%1024,rand()%800);
    getch();
    closegraph();
    }

