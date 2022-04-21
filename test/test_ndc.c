#include "..\all.h"

int main(){

    printf("测试牛顿插值法\n");

    int max_num=10;
    Pos points[max_num];
    points[0]=pos_get(2,4);
    points[1]=pos_get(0,0);
    points[2]=pos_get(4,0);
    // points[3]=pos_get();
    // points[4]=pos_get();
    // points[5]=pos_get();
    // points[6]=pos_get();
    // points[7]=pos_get();
    Ndc ndc=ndc_get(points,2);
    char x='x';
    ndc_show(ndc,x);

    printf("\n新加入一个点(4,0)后\n");
    ndc=ndc_insert(ndc,&points[2],1);
    ndc_show(ndc,x);


    getch();

    return 1;
}