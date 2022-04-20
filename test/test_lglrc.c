#include "..\all.h"

int main(){
    int max_num=10;
    Pos points[max_num];
    points[0]=pos_get(1,2);
    points[1]=pos_get(0,0);
    points[2]=pos_get(2,0);
    // points[3]=pos_get();
    // points[4]=pos_get();
    // points[5]=pos_get();
    // points[6]=pos_get();
    // points[7]=pos_get();
    Lglrc lglrc=lglrc_get(points,3);
    char x='x';
    lglrc_show(lglrc,x);

    getchar();
    return 0;
}