#include "..\all.h"



int main(){
    //���Զ���ʽ�ļӼ���
    //ϵ������
    double coe[3];
    int n=3;
    coe[0]=1;
    coe[1]=1;
    coe[2]=0;
    Mult a=mult_get(coe,n);
    coe[0]=0;
    coe[1]=1;
    coe[2]=2;
    Mult b=mult_get(coe,n);

    

    char x='x';
    printf("a=");
    mult_show(a,x);
    printf("\nb=");
    mult_show(b,x);


    printf("\n���Զ���ʽ���������㣺\n");
    printf("\n\na+b=");
    mult_show(mult_add(a,b),x);
    printf("\n\na-b=");
    mult_show(mult_minus(a,b),x);
    printf("\n\na*b=");
    mult_show(mult_mult(a,b),x);

    double c=2;
    printf("\n\n���Զ���ʽ������:\n%.2Lf*a=",c);
    mult_show(mult_num_mult(a,c),x);


    printf("\n0����ʽΪ:");
    mult_show(mult_zero(),x);
    printf("\n1����ʽΪ:");
    mult_show(mult_one(),x);

    getch();
    return 0;
    return 0;
}
