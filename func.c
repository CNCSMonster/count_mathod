#include "func.h"


//��ú���ʽ��

//��������ı�����ú���ʽ��
Func func_get(double* coe,int n){
    return mult_get(coe,n);
}

//����������ַ�����Ϣ��ȡ��һ������,����xΪָ���ı�����
Func func_read(char* str,char x){
    
}

//����ʽ�ӵĲ���

//��������ʽ���
Func func_add(Func a,Func b){
    return mult_add(a,b);
}

//��������ʽ���
Func func_minus(Func a,Func b){
    return mult_minus(a,b);
}

//��������ʽ���
Func func_mult(Func a,Func b){
    return mult_mult(a,b);
}

//��������ʽ���
Func func_divi(Func a,Func b){
    return mult_divi(a,b);
}

//��������ʽ����
Func func_num_mult(Func a,double x){
    return mult_num_mult(a,x);
}

//��������ʽ��
Func func_dao(Func a){
    return mult_dao(a);
}

//��ú���ʽ����Ϣ

//��ӡ����ʽ��
void func_show(Func a,char x){
    mult_show(a,x);
}

//����������Ա�����ֵ�����㺯��ֵ
double func_get_value(Func a,double x){
    return mult_get_value(a,x);
}





