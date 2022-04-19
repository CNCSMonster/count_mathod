#include "mult.h"

//创建多项式

/*根据输入的系数数组得到一个多项式
输入的n表示输入的有效系数个数，也表示输入的系数对应的最高次数+1
举个例子，要获得1+3*x^2，则需要输入三个系数，0,1,2次项系数，
则输入的double数组为[1,0,3],n为3
*/
Mult mult_get(double* val,int n){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    for(int i=0;i<n;i++){
        out.val[i]=val[i];
    }
    out.max=n;
    //确定多项式的最高项
    for(int i=out.max-1;i>0;i--){
        if(out.val[i]<MULT_NEAR_ZERO){
            out.max=i;
            break;
        }
    }
    return out;
}


//创建一个相当于0的空白多项式
Mult mult_zero(void){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.val[0]=0;
    out.max=1;

    return out;
}

//创建一个相当于1的空白多项式
Mult mult_one(void){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.val[0]=1;
    out.max=1;
    return out;
}



//多项式操作

//多项式加法
Mult mult_add(Mult a,Mult b){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.max=a.max>b.max?a.max:b.max;
    for(int i=0;i<out.max;i++){
        out.val[i]=a.val[i]+b.val[i];
    }
    //确定多项式的最高项
    for(int i=out.max-1;i>0;i--){
        if(out.val[i]<MULT_NEAR_ZERO){
            out.max=i;
            break;
        }
    }
    return out;
}

//多项式减法
Mult mult_minus(Mult a,Mult b){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.max=a.max>b.max?a.max:b.max;
    for(int i=0;i<out.max;i++){
        out.val[i]=a.val[i]+b.val[i];
    }
    //确定多项式的最高项
    for(int i=out.max-1;i>0;i--){
        if(out.val[i]<MULT_NEAR_ZERO){
            out.max=i;
            break;
        }
    }
    return out;
}

//多项式乘法
Mult mult_mult(Mult a,Mult b){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.max=a.max+b.max-1;
    for(int i=0;i<a.max;i++){
        for(int j=0;j<b.max;j++){
            out.val[i+j]+=a.val[i]*b.val[j];
        }
    }
    //确定多项式的最高项
    for(int i=out.max-1;i>0;i--){
        if(out.val[i]<MULT_NEAR_ZERO){
            out.max=i;
            break;
        }
    }
    return out;
}

//暂不实现
Mult mult_divi(Mult a,Mult b){
    
}



//获取多项式信息


//计算传入自变量x后的多项式式值
double mult_get_value(double x){

}

//打印多项式
void mult_show(Mult mult,char x){

}









