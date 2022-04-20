
#include "all.h"




int main(void){
    int max_num=10;
    Pos points[max_num];
    points[0]=pos_get(1,2);
    // points[1]=pos_get();
    // points[2]=pos_get();
    // points[3]=pos_get();
    // points[4]=pos_get();
    // points[5]=pos_get();
    // points[6]=pos_get();
    // points[7]=pos_get();
    Lglrc lglrc=lglrc_get(points,1);
    char x='x';
    lglrc_show(lglrc,x);
    getch();
    return 0;
}