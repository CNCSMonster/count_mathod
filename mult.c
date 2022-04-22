#include "mult.h"

//创建多项式

/*根据输入的系数数组得到一个多项式
输入的n表示输入的有效系数个数，也表示输入的系数对应的最高次数+1
举个例子，要获得1+3*x^2，则需要输入三个系数，0,1,2次项系数，
则输入的double数组为[1,0,3],n为3
*/
Mult mult_get(double val[],int n){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    for(int i=0;i<n;i++){
        out.val[i]=val[i];
    }
    out.max=n;
    //确定多项式的最高项
    for(int i=out.max-1;i>=0;i--){
        if(i==0){
            out.max=1;
            break;
        }
        if(fabs(out.val[i])>=MULT_NEAR_ZERO){
            out.max=i+1;
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
    for(int i=out.max-1;i>=0;i--){
        if(i==0){
            out.max=1;
            break;
        }
        if(fabs(out.val[i])>=MULT_NEAR_ZERO){
            out.max=i+1;
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
        out.val[i]=a.val[i]-b.val[i];
    }
    //确定多项式的最高项
    for(int i=out.max-1;i>=0;i--){
        if(i==0){
            out.max=1;
            break;
        }
        if(fabs(out.val[i])>=MULT_NEAR_ZERO){
            out.max=i+1;
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
    for(int i=out.max-1;i>=0;i--){
        if(i==0){
            out.max=1;
            break;
        }
        if(fabs(out.val[i])>=MULT_NEAR_ZERO){
            out.max=i+1;
            break;
        }
    }
    return out;
}

//暂不实现
Mult mult_divi(Mult a,Mult b){
    Mult out;
    return out;
}

//多项式的数乘,mult乘以coe(coefficient)
Mult mult_num_mult(Mult mult,double coe){
    for(int i=0;i<mult.max;i++){
        mult.val[i]*=coe;
    }
     //确定多项式的最高项
    for(int i=mult.max-1;i>=0;i--){
        if(i==0){
            mult.max=1;
            break;
        }
        if(fabs(mult.val[i])>=MULT_NEAR_ZERO){
            mult.max=i+1;
            break;
        }
    }
    return mult;
}


//多项式求导,获得多项式的导数
Mult mult_dao(Mult mult){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.max=mult.max-1;
    for(int i=1;i<mult.max;i++){
        out.val[i-1]=mult.val[i]*i;
    }
    return out;
}



//获取多项式信息


//计算传入自变量x后的多项式式值
double mult_get_value(Mult mult,double x){
    double out=0;
    for(int i=0;i<mult.max;i++){
        double coe=pow(x,i);
        out+= coe*mult.val[i];
    }
    return out;
}

//打印多项式，系数打印时保留2位小数
void mult_show(Mult mult,char x){

    //特殊情况，多项式为0多项式时
    if(mult.max==1){
        printf("%.2Lf",mult.val[0]);
        return;
    }

    //first为1表示这个数是第一个有效项
    int first=1;    
    for(int i=0;i<mult.max;i++){
        if(i==0&&fabs(mult.val[i])>=MULT_NEAR_ZERO){
            printf("%.2Lf",mult.val[i]);
            first=0;
        }else{
            if(fabs(mult.val[i])>=MULT_NEAR_ZERO){
                if(mult.val[i]>0&&first!=1){
                    printf("+%.2Lf",mult.val[i]);
                    printf("%c^%d",x,i);
                }else{
                    printf("%.2Lf",mult.val[i]);
                    printf("%c^%d",x,i);
                    if(first==1){
                        first=0;
                    }
                }
            }
        }
    }
}











