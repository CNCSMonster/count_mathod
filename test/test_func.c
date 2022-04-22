#include "../all.h"

int main(){
    //测试多项式的加减乘
    //系数数组
    double coe[3];
    int n=3;
    coe[0]=0;
    coe[1]=1;
    coe[2]=0;
    Func a=func_get(coe,n);
    coe[0]=1;
    coe[1]=3;
    coe[2]=1;
    Func b=func_get(coe,n);

    

    char x='x';
    printf("a=");
    func_show(a,x);
    printf("\nb=");
    func_show(b,x);


    printf("\n测试多项式的四则运算：\n");
    printf("\n\na+b=");
    func_show(func_add(a,b),x);
    printf("\n\na-b=");
    func_show(func_minus(a,b),x);
    printf("\n\na*b=");
    func_show(func_mult(a,b),x);

    double c=2;
    printf("\n\n测试多项式的数乘:\n%.2Lf*a=",c);
    func_show(func_num_mult(a,c),x);

    printf("\n测试多项式求导:\n");
    printf("多项式b=");
    func_show(b,x);
    printf("的导数为：");
    func_show(func_dao(b),x);


    


    //测试多项式求值
    printf("\n多项式");
    func_show(a,x);
    printf("在x=3的时候的值为:%.2Lf",func_get_value(a,3));
    printf("\n多项式");


    getch();
    return 0;
}