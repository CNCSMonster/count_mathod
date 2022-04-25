#include "../all.h"







int main(){




    do{
        printf("输入用来牛顿迭代的多项式型迭代式的最高次:");
        int max;
        scanf("%d",&max);
        double coe[max+1];
        for(int i=0;i<max+1;i++){
            printf("%d次项系数为",i);
            scanf("%lf",&coe[i]);
        }
        Func func=func_get(coe,max+1);
        char x='x';
        printf("使用牛顿迭代法求方程");
        func_show(func,x);
        printf("=0 的解\n");
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
        double v=ndd_count(func,st,w1,w2,&ifok);
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