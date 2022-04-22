#include "..\all.h"



int main(){
    //测试多项式的加减乘
    //系数数组
    double coe[3];
    int n=3;
    coe[0]=0;
    coe[1]=1;
    coe[2]=0;
    Mult a=mult_get(coe,n);
    coe[0]=1;
    coe[1]=3;
    coe[2]=1;
    Mult b=mult_get(coe,n);

    

    char x='x';
    printf("a=");
    mult_show(a,x);
    printf("\nb=");
    mult_show(b,x);


    printf("\n测试多项式的四则运算：\n");
    printf("\n\na+b=");
    mult_show(mult_add(a,b),x);
    printf("\n\na-b=");
    mult_show(mult_minus(a,b),x);
    printf("\n\na*b=");
    mult_show(mult_mult(a,b),x);

    double c=2;
    printf("\n\n测试多项式的数乘:\n%.2Lf*a=",c);
    mult_show(mult_num_mult(a,c),x);

    printf("\n测试多项式求导:\n");
    printf("多项式b=");
    mult_show(b,x);
    printf("的导数为：");
    mult_show(mult_dao(b),x);


    printf("\n0多项式为:");
    mult_show(mult_zero(),x);
    printf("\n1多项式为:");
    mult_show(mult_one(),x);


    //测试多项式求值
    printf("\n多项式");
    mult_show(a,x);
    printf("在x=3的时候的值为:%.2Lf",mult_get_value(a,3));
    printf("\n多项式");





    getch();
    return 0;
}
