#include "lglrc.h"


//获得拉格朗日插值多项式

//通过输入的点的数组得到一个拉格朗日插值多项式
Lglrc lglrc_get(Posp points,int n){
    //进行边界判断
    if(n>=LGLR_MAX_N){
        printf("输入的点的个数超过限制，请进入lglrc.h文件中修改");
    }
    Lglrc out;
    out.n=n;
    for(int i=0;i<out.n;i++){
        out.points[i]=points[i];
    }
    for(int i=0;i<out.n;i++){
        double a=out.points[i].y;
        Mult add=mult_one();
        for(int j=0;j<out.n;j++){
            if(i==j){
                continue;
            }
            a/=(out.points[i].x-out.points[j].x);
            double coe_t[2];
            coe_t[0]=-out.points[j].x;
            coe_t[1]=1;
            Mult term=mult_get(coe_t,2);
            add=mult_mult(add,term);
        }
        out.mults[i]=mult_num_mult(add,a);
    }
    return out;
}



//拉格朗日插值多项式操作


//往拉格朗日插值多项式中多插一系列点获得新的拉格朗日多项式
Lglrc lglrc_insert(Lglrc lglrc,Posp adds,int numOfAdds){
    if(lglrc.n+numOfAdds>LGLR_MAX_N){
        printf("输入的点的个数超过限制，请进入lglrc.h文件中修改");
    }
    //增加新的点列
    //以及为更新旧的项准备的参数
    Mult times=mult_one();
    for(int i=0;i<numOfAdds;i++){
        lglrc.points[lglrc.n+i]=adds[i];
        double ta[2];
        ta[0]=-adds[i].x;
        ta[1]=1;
        Mult term=mult_get(ta,2);
        times=mult_mult(times,term);
    }
    //修改旧的项
    for(int i=0;i<lglrc.n;i++){
        Mult term=mult_num_mult(times,1.0/mult_get_value(times,lglrc.points[i].x));
        lglrc.mults[i]=mult_mult(lglrc.mults[i],term);
    }
    //增加新的项
    for(int i=lglrc.n;i<lglrc.n+numOfAdds;i++){
        double a=lglrc.points[i].y;
        Mult add=mult_one();
        for(int j=0;j<lglrc.n+numOfAdds;j++){
            if(i==j){
                continue;
            }
            a/=(lglrc.points[i].x-lglrc.points[j].x);
            double coe_t[2];
            coe_t[0]=-lglrc.points[j].x;
            coe_t[1]=1;
            Mult term=mult_get(coe_t,2);
            add=mult_mult(add,term);
        }
        lglrc.mults[i]=mult_num_mult(add,a);
    }
    //更新长度
    lglrc.n+=numOfAdds;
    return lglrc;
}


//获取拉格朗日多项式信息

//打印拉格朗日多项式
void lglrc_show(Lglrc lglrc,char x){
    Mult show=mult_zero();
    for(int i=0;i<lglrc.n;i++){
        show=mult_add(show,lglrc.mults[i]);
    }
    mult_show(show,x);
}

//根据自变量x的值，获得拉格朗日多项式的函数值
double lglrc_getvalue(Lglrc lglrc,double x){
    double out=0;
    for(int i=0;i<lglrc.n;i++){
        out+=mult_get_value(lglrc.mults[i],x);
    }
    return out;
}