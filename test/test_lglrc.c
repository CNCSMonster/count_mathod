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
    Lglrc lglrc=lglrc_get(points,2);
    char x='x';
    lglrc_show(lglrc,x);

    printf("\n新加入一个点(2,0)后\n");
    lglrc=lglrc_insert(lglrc,&points[2],1);
    lglrc_show(lglrc,x);






    getchar();
    return 0;
}