//ţ�ٲ�ֵ����ʽ
//MMndc.h
#ifndef _Mndc_H_ //���û������ͷ�ļ�Mndc.h
    #define _Mndc_H_ //�Ǿ�����ͷ�ļ�Mndc.h

#include "pos.h"
#include "mult.h"

typedef struct myMndc{
    Mult mult;
    Posp points;
    int n;
}Mndc,*Mndcp;

//����ţ�ٲ�ֵ����ʽ

//���ݵ��еõ�ţ�ٲ�ֵ����ʽ
Mndc Mndc_get(Posp points,int n);

//��ţ�ٲ�ֵ����ʽ����
Mndc Mndc_insert(Mndc Mndc,Posp adds,int numOfAdds);


//���ţ�ٲ�ֵ����ʽ��Ϣ

//��ӡ����ʽ
void Mndc_show(Mndc Mndc,char x);

//����������Ա�����ȡ����ʽֵ
double Mndc_get_value(Mndc Mndc,double x);








#endif


