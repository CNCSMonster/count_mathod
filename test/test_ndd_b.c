#include "../all.h"

//根据输入的自变量x的值返回原函数的值
double f_yuan(double x);

//根据输入的自变量x的值求原函数导数的值
double f_dao(double x);

double ndd_count_b(double st,double w1,double w2,int* ifok);


int main(){
    do{
        double w1=0.0001;
        double w2=0.00000001;
        printf("\n输入迭代初值：");
        double st;
        scanf("%lf",&st);
        printf("\n输入函数限差w1：");
        scanf("%lf",&w1);
        printf("\n输入导数限差w2：");
        scanf("%lf",&w2);
        printf("\n函数值限差为：%.10f导数值限差为：%.10f迭代初值为:%.3f\n",w1,w2,st);
        int ifok;
        double v=ndd_count_b(st,w1,w2,&ifok);
        if(ifok==0){
            printf("\n计算失败\n");
            
        }else{
            printf("\n计算成功\n");
            printf("结果：%.4Lf",v);
            printf("输入e退出,输入其他任意键继续");
            char choice=getch();
            if(choice=='e'){
                break;
            }
        }
    }while(1);
    getch();
    return 0;
}

//根据输入的自变量x的值返回原函数的值
double f_yuan(double x){
    return sin(x)*pow(x,3)-log(x+1)/log(10)+pow(x,2)-x;
}

//根据输入的自变量x的值求原函数导数的值
double f_dao(double x){
    return sin(x)*3*pow(x,2)+cos(x)*pow(x,3)-1.0/(x+1)/log(10)+2*x-1;
}

double ndd_count_b(double st,double w1,double w2,int* ifok){
    do{
        if(fabs(f_dao(st))<w2){
            //牛顿迭代计算失败
            *ifok=0;
            break;
        }
        if(fabs(f_yuan(st))<w1){
            //牛顿迭代计算成功
            *ifok=1;
            break;
        }
        st=st-f_yuan(st)/f_dao(st);
    }while(1);
    return st;
}

