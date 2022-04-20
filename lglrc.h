//lglrc.h
#ifndef _LGLRC_H_ //如果没有引入头文件lglrc.h
    #define _LGLRC_H_ //那就引入头文件lglrc.h

#include <mem.h>
#include <math.h>

#include "pos.h"
#include "mult.h"


//用来记录可以认为等于0的临界值
#define LGLR_NEAR_ZERO 10E-10

//定义一个常量记录拉格朗日最大项数
#define LGLR_MAX_N 100




//拉格朗日插值多项式结构体
typedef struct mylglrc{
    //多项式组合
    Mult mults[LGLR_MAX_N];
    //之前插入的点的数组
    Pos points[LGLR_MAX_N];
    //之前插入的点的数量
    int n;
}Lglrc,*Lglrcp;


//获得拉格朗日插值多项式

//通过输入的点的数组得到一个拉格朗日插值多项式
Lglrc lglrc_get(Posp points,int n);



//拉格朗日插值多项式操作


//往拉格朗日插值多项式中多插一系列点获得新的拉格朗日多项式
Lglrc lglrc_insert(Lglrc lglrc,Posp adds,int numOfAdds);


//获取拉格朗日多项式信息

//打印拉格朗日多项式
void lglrc_show(Lglrc lglrc,char x);



//根据自变量x的值，获得拉格朗日多项式的函数值
double lglrc_getvalue(Lglrc lglrc,double x);






#endif