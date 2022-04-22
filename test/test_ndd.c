#include "../all.h"

int main(){
    double coe[5]={12,3,53,66,2};
    Func func=func_get(coe,5);
    char x='x';
    printf("使用牛顿迭代法求方程");
    func_show(func,x);
    printf("=0 的解\n");
    double w1=0.0001;
    double w2=0.00000001;
    do{
         printf("函数值限差为：导数值限差为：迭代初值为:\n")
   
    }while(1);
    return 0;
}