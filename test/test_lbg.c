#include "../all.h"

double f_yuan(double x);

//����wΪ����,a,bΪ��������aӦ��С��b
double lbg_count(double a,double b,double w);

//ʵ�����η��ĵ���
double tui(double xs,double h,double a,double b);


int main(){
    do{
        printf("��������ֵķ�Χ��");
        double a,b;
        printf("(aӦ��С��b)a,b=");
        scanf("%lf,%lf",&a,&b);
        printf("��������ֵľ���");
        double w;
        scanf("%lf",&w);
        double c=lbg_count(a,b,w);
        printf("\n���ֽ��Ϊ��%.6Lf\n",c);
        printf("����e�˳�������������");
        char ord=getch();
        if(ord=='e'){
            break;
        }else{
            system("cls");
        }
    }while(1);
    return 0;
}


double f_yuan(double x){
    // return x;
    return pow(x,2)+pow(x,3);
}

//����wΪ����,a,bΪ��������aӦ��С��b
double lbg_count(double a,double b,double w){
    double h=(b-a)/2;
    int n=3;
    double jieguo[170][170];
    jieguo[0][0]=h/4*(f_yuan(a)+2*f_yuan(a+h)+f_yuan(b));
    printf("\nt��������:\n");
    printf("%.6f\n",jieguo[0][0]);
    for(int i=1;i<170;i++){
        jieguo[i][0]=tui(jieguo[i-1][0],h,a,b);
        printf("%.2Lf\t",jieguo[i][0]);
        h/=2;
        for(int j=1;j<=i;j++){
            double term=pow(4,j);
            jieguo[i][j]=term/(term-1)*jieguo[i][j-1]-1/(term-1)*jieguo[i-1][j-1];
            printf("%.2Lf\t",jieguo[i][j]);
        }
        printf("\n");
        //�ж��Ƿ����㾫��
        if(fabs(jieguo[i][i]-jieguo[i-1][i-1])<w){
            return jieguo[i][i];
        }
    }
    return 0;
}

double tui(double xs,double h,double a,double b){
    double th=h/2;
    double out=xs/2;
    for(int i=0;a+th+i*h<b;i++){
        out+=th*f_yuan(a+th+h*i);
    }
    return out;
}


