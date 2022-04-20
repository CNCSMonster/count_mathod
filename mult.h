//mult.h
#ifndef _MULT_H_ //如果没有引入头文件mult.h
    #define _MULT_H_ //那就引入头文件mult.h

#include <mem.h>
#include <math.h>


//多项式最高项数
#define MULT_MAX_N 100

//定义近0临界小量
//也就是说如果一个系数小于这个量时，可以认为等于0
#define MULT_NEAR_ZERO 10E-8

typedef struct mymult{
    //多项式系数
    double val[MULT_MAX_N];
    //多项式的最高项次数
    int max;
}Mult,*Multp;

//创建多项式

/*根据输入的系数数组得到一个多项式
输入的n表示输入的有效系数个数，也表示输入的系数对应的最高次数+1
举个例子，要获得1+3*x^2，则需要输入三个系数，0,1,2次项系数，
则输入的double数组为[1,0,3],n为3
*/
Mult mult_get(double val[],int n);


//创建一个相当于0的空白多项式
Mult mult_zero(void);

//创建一个相当于1的空白多项式
Mult mult_one(void);



//多项式操作

//多项式加法
Mult mult_add(Mult a,Mult b);

//多项式减法
Mult mult_minus(Mult a,Mult b);

//多项式乘法
Mult mult_mult(Mult a,Mult b);

//多项式除法
Mult mult_divi(Mult a,Mult b);

//多项式的数乘,mult乘以coe(coefficient)
Mult mult_num_mult(Mult mult,double coe);



//获取多项式信息


//计算传入自变量x后的多项式式值
double mult_get_value(Mult mult,double x);

//打印多项式,传入的x为自变量符号
void mult_show(Mult mult,char x);







#endif