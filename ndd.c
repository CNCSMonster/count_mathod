#include "ndd.h"

//通过输入的函数func,和初始值st,以函数果误差限w1，和导数误差限w2，使用牛顿迭代法求func=0方程的解
//通过ifok来记录是否成功
double ndd_count(Func func,double st,double w1,double w2,int* ifok){
    do{
        if(fabs(ndd_dao(func,st))<w1){
            *ifok=0;
            break;
        }
        if(fabs(ndd_yuan(func,st)<w1)){
            *ifok=1;
            break;
        }
        st=st-ndd_yuan(func,st)/ndd_dao(func,st);
    }while(1);
    return st;
}

//获得func在x处的函数值
double ndd_yuan(Func func ,double x){

}

//获得func导数在x处的函数值
double ndd_dao(Func func,double x){

}







