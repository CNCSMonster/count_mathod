

#include "ndc.h"


//创建牛顿插值多项式

//根据点列得到牛顿插值多项式
Ndc ndc_get(Posp points,int n){
    //
    Ndc out;
    out.mult=mult_zero();
    for(int i=0;i<n;i++){
        out.points[i]=points[i];
    }
    out.n=n;

    Mult a=mult_one();  //用来记录中间部分
    for(int i=0;i<out.n;i++){
        double tt[2];
        tt[0]=1-points[i].x;
        tt[1]=1;
        Mult term=mult_get(tt,2);
        term=mult_num_mult(term,points[i].y-mult_get_value(out.mult,points[i].x));
        term=mult_mult(term,a);
        //更新a
        tt[0]=-points[i].x;
        tt[1]=1;
        a=mult_mult(a,mult_get(tt,2));
        //更新out.mult
        out.mult=mult_add(out.mult,term);
    }
    return out;
}

//对牛顿插值多项式操作


//往多项式里插一系列点，得到新的多项式
Ndc ndc_insert(Ndc ndc,Posp adds,int numOfAdds){
    
    //判断是否超过限制
    if(ndc.n+numOfAdds>MULT_MAX_N){
        printf("超过可插项数目限制,请到mult.h中修改");
    }
    
    

    Mult a=mult_one();  //用来记录中间部分
    for(int i=0;i<ndc.n;i++){

    }



    for(int i=ndc.n;i<out.n;i++){
        //在多项式记录的点中补充后面的点
        ndc.points[i]=adds[i-ndc.n];
        double tt[2];
        tt[0]=1-points[i].x;
        tt[1]=1;
        Mult term=mult_get(tt,2);
        term=mult_num_mult(term,points[i].y-mult_get_value(out.mult,points[i].x));
        term=mult_mult(term,a);
        //更新a
        tt[0]=-points[i].x;
        tt[1]=1;
        a=mult_mult(a,mult_get(tt,2));
        //更新out.mult
        out.mult=mult_add(out.mult,term);
    }
    ndc.n+=numOfAdds;

    return out;

}


//获得牛顿插值多项式信息

//打印多项式
void ndc_show(Ndc ndc,char x){

    mult_show(ndc.mult,x);
}

//根据输入的自变量获取多项式值
double ndc_get_value(Ndc ndc,double x){
    return mult_get_value(ndc.mult,x);
}

