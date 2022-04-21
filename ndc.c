

#include "ndc.h"


//创建牛顿插值多项式

//根据点列得到牛顿插值多项式
Ndc ndc_get(Posp points,int n){
    //
    Ndc out;
    if(n<=0){
        printf("输入参数错误\n");
        return out;
    }
    for(int i=0;i<n;i++){
        out.points[i]=points[i];
    }
    out.n=n;
    double st=points[0].y;
    out.mult=mult_get(&st,1);
    double ssst[2];
    ssst[0]=-points[0].x;
    ssst[1]=1;
    Mult co=mult_get(ssst,2);



    for(int i=1;i<out.n;i++){
        
        //当加入第i个项时，
        //新加入的项为：（Yi - Fi-1(Xi) )(x- Xi + 1)(x - Xi-1 )...(x-X0)
        //其中Fi-1为加入i点前的牛顿插值多项式函数，Fi-1(Xi)为代入Xi后它的值
        double x=out.points[i].x;
        double y=out.points[i].y;
        
        double before=mult_get_value(out.mult,x);

        
        Mult add=mult_num_mult(co,(y-before)/mult_get_value(co,x));

        //加入新项
        out.mult=mult_add(out.mult,add);

        //刷新co
        double coe[2];
        coe[0]=-x;
        coe[1]=1;
        co=mult_mult(co,mult_get(coe,2));

    }
    out.co=co;
    return out;
}

//对牛顿插值多项式操作


//往多项式里插一系列点，得到新的多项式
Ndc ndc_insert(Ndc ndc,Posp adds,int numOfAdds){
    
    //判断是否超过限制
    if(ndc.n+numOfAdds>MULT_MAX_N){
        printf("超过可插项数目限制,请到mult.h中修改");
        return ndc; //返回输入的多项式的复制
    }

    for(int i=0;i<numOfAdds;i++){
        ndc.points[i+ndc.n]=adds[i];
    }

    ndc.n+=numOfAdds;

    Mult co=ndc.co;

    for(int i=ndc.n-numOfAdds;i<ndc.n;i++){
        
        //当加入第i个项时，
        //新加入的项为：（Yi - Fi-1(Xi) )(x- Xi + 1)(x - Xi-1 )...(x-X0)
        //其中Fi-1为加入i点前的牛顿插值多项式函数，Fi-1(Xi)为代入Xi后它的值
        double x=ndc.points[i].x;
        double y=ndc.points[i].y;
        
        double before=mult_get_value(ndc.mult,x);

        Mult add=mult_num_mult(co,(y-before)/mult_get_value(co,x));

        //加入新项
        ndc.mult=mult_add(ndc.mult,add);

        //刷新co
        double coe[2];
        coe[0]=-x;
        coe[1]=1;
        co=mult_mult(co,mult_get(coe,2));

    }
    ndc.co=co;
    return ndc;
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

