//牛顿插值多项式
//Mndc.h
#ifndef _NDC_H_ //如果没有引入头文件ndc.h
    #define _NDC_H_ //那就引入头文件ndc.h

#include "pos.h"
#include "mult.h"

typedef struct myndc{
    Mult mult;
    Posp points;
    int n;
}Ndc,*Ndcp;

//创建牛顿插值多项式

//根据点列得到牛顿插值多项式
Ndc ndc_get(Posp points,int n);

//对牛顿插值多项式操作
Ndc ndc_insert(Ndc ndc,Posp adds,int numOfAdds);


//获得牛顿插值多项式信息

//打印多项式
void ndc_show(Ndc ndc,char x);

//根据输入的自变量获取多项式值
double ndc_get_value(Ndc ndc,double x);








#endif


