//ţ�ٵ�����ʵ��
//ndd.h
#ifndef _NDD_H_ //���û������ͷ�ļ�ndd.h
    #define _NDD_H_ //�Ǿ�����ͷ�ļ�ndd.h

#include "func.h"


//ͨ������ĺ���func,�ͳ�ʼֵst,�Լ���������w1���͵��������w2��ʹ��ţ�ٵ�������func=0���̵Ľ�
double ndd_count(Func func,double st,double w1,double w2,int* ifok);

//���func��x���ĺ���ֵ
double ndd_yuan(Func func ,double x);

//���func������x���ĺ���ֵ
double ndd_dao(Func func,double x);









#endif