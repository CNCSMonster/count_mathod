//牛顿插值多项式
//MMndc.h
#ifndef _Mndc_H_ //如果没有引入头文件Mndc.h
    #define _Mndc_H_ //那就引入头文件Mndc.h

#include "pos.h"
#include "mult.h"

typedef struct myMndc{
    Mult mult;
    Posp points;
    int n;
}Mndc,*Mndcp;

//创建牛顿插值多项式

//根据点列得到牛顿插值多项式
Mndc Mndc_get(Posp points,int n);

//对牛顿插值多项式操作
Mndc Mndc_insert(Mndc Mndc,Posp adds,int numOfAdds);


//获得牛顿插值多项式信息

//打印多项式
void Mndc_show(Mndc Mndc,char x);

//根据输入的自变量获取多项式值
double Mndc_get_value(Mndc Mndc,double x);








#endif


