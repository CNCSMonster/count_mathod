#include "func.h"


//获得函数式子

//根据输入的变量获得函数式子
Func func_get(double* coe,int n){
    return mult_get(coe,n);
}

//根据输入的字符串信息读取出一个函数,其中x为指定的变量名
Func func_read(char* str,char x){
    
}

//函数式子的操作

//函数多项式相加
Func func_add(Func a,Func b){
    return mult_add(a,b);
}

//函数多项式相减
Func func_minus(Func a,Func b){
    return mult_minus(a,b);
}

//函数多项式相乘
Func func_mult(Func a,Func b){
    return mult_mult(a,b);
}

//函数多项式相除
Func func_divi(Func a,Func b){
    return mult_divi(a,b);
}

//函数多项式数乘
Func func_num_mult(Func a,double x){
    return mult_num_mult(a,x);
}

//函数多项式求导
Func func_dao(Func a){
    return mult_dao(a);
}

//获得函数式子信息

//打印函数式子
void func_show(Func a,char x){
    mult_show(a,x);
}

//根据输入的自变脸的值，计算函数值
double func_get_value(Func a,double x){
    return mult_get_value(a,x);
}





