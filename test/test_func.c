#include "../all.h"

int main(){
    //���Զ���ʽ�ļӼ���
    //ϵ������
    double coe[3];
    int n=3;
    coe[0]=0;
    coe[1]=1;
    coe[2]=0;
    Func a=func_get(coe,n);
    coe[0]=1;
    coe[1]=3;
    coe[2]=1;
    Func b=func_get(coe,n);

    

    char x='x';
    printf("a=");
    func_show(a,x);
    printf("\nb=");
    func_show(b,x);


    printf("\n���Զ���ʽ���������㣺\n");
    printf("\n\na+b=");
    func_show(func_add(a,b),x);
    printf("\n\na-b=");
    func_show(func_minus(a,b),x);
    printf("\n\na*b=");
    func_show(func_mult(a,b),x);

    double c=2;
    printf("\n\n���Զ���ʽ������:\n%.2Lf*a=",c);
    func_show(func_num_mult(a,c),x);

    printf("\n���Զ���ʽ��:\n");
    printf("����ʽb=");
    func_show(b,x);
    printf("�ĵ���Ϊ��");
    func_show(func_dao(b),x);


    


    //���Զ���ʽ��ֵ
    printf("\n����ʽ");
    func_show(a,x);
    printf("��x=3��ʱ���ֵΪ:%.2Lf",func_get_value(a,3));
    printf("\n����ʽ");


    getch();
    return 0;
}