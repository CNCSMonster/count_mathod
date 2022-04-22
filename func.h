//func.h
#ifndef _FUNC_H_ //���û������ͷ�ļ�func.h
    #define _FUNC_H_ //�Ǿ�����ͷ�ļ�func.h

#include "mult.h"

//�������庯��ʽ��

typedef Mult Func;


//��ú���ʽ��

//��������ı�����ú���ʽ��
Func func_get(double* coe,int n);

//����������ַ�����Ϣ��ȡ��һ������,����xΪָ���ı�����
Func func_read(char* str,char x);

//����ʽ�ӵĲ���

//��������ʽ���
Func func_add(Func a,Func b);

//��������ʽ���
Func func_minus(Func a,Func b);

//��������ʽ���
Func func_mult(Func a,Func b);

//��������ʽ���
Func func_divi(Func a,Func b);

//��������ʽ����
Func func_num_mult(Func a,double x);

//��������ʽ��
Func func_dao(Func a);

//��ú���ʽ����Ϣ

//��ӡ����ʽ��
void func_show(Func a,char x);

//����������Ա�����ֵ�����㺯��ֵ
double func_get_value(Func a,double x);



#endif