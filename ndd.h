//牛顿迭代法实现
//ndd.h
#ifndef _NDD_H_ //如果没有引入头文件ndd.h
    #define _NDD_H_ //那就引入头文件ndd.h

#include "func.h"


//通过输入的函数func,和初始值st,以及结果误差限w1，和导数误差限w2，使用牛顿迭代法求func=0方程的解
double ndd_count(Func func,double st,double w1,double w2,int* ifok);

//获得func在x处的函数值
double ndd_yuan(Func func ,double x);

//获得func导数在x处的函数值
double ndd_dao(Func func,double x);









#endif