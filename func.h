//func.h
#ifndef _FUNC_H_ //如果没有引入头文件func.h
    #define _FUNC_H_ //那就引入头文件func.h

#include "mult.h"

//用来定义函数式子

typedef Mult Func;


//获得函数式子

//根据输入的变量获得函数式子
Func func_get(double* coe,int n);

//根据输入的字符串信息读取出一个函数,其中x为指定的变量名
Func func_read(char* str,char x);

//函数式子的操作

//函数多项式相加
Func func_add(Func a,Func b);

//函数多项式相减
Func func_minus(Func a,Func b);

//函数多项式相乘
Func func_mult(Func a,Func b);

//函数多项式相除
Func func_divi(Func a,Func b);

//函数多项式数乘
Func func_num_mult(Func a,double x);

//函数多项式求导
Func func_dao(Func a);

//获得函数式子信息

//打印函数式子
void func_show(Func a,char x);

//根据输入的自变脸的值，计算函数值
double func_get_value(Func a,double x);



#endif