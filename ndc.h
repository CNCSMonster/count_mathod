//ţ�ٲ�ֵ����ʽ
//Mndc.h
#ifndef _NDC_H_ //���û������ͷ�ļ�ndc.h
    #define _NDC_H_ //�Ǿ�����ͷ�ļ�ndc.h

#include "pos.h"
#include "mult.h"

typedef struct myndc{
    Mult mult;
    Posp points;
    int n;
}Ndc,*Ndcp;

//����ţ�ٲ�ֵ����ʽ

//���ݵ��еõ�ţ�ٲ�ֵ����ʽ
Ndc ndc_get(Posp points,int n);

//��ţ�ٲ�ֵ����ʽ����
Ndc ndc_insert(Ndc ndc,Posp adds,int numOfAdds);


//���ţ�ٲ�ֵ����ʽ��Ϣ

//��ӡ����ʽ
void ndc_show(Ndc ndc,char x);

//����������Ա�����ȡ����ʽֵ
double ndc_get_value(Ndc ndc,double x);








#endif


