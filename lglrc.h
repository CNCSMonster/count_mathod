//lglrc.h
#ifndef _LGLRC_H_ //���û������ͷ�ļ�lglrc.h
    #define _LGLRC_H_ //�Ǿ�����ͷ�ļ�lglrc.h

#include <mem.h>
#include <math.h>

#include "pos.h"
#include "mult.h"


//������¼������Ϊ����0���ٽ�ֵ
#define LGLR_NEAR_ZERO 10E-10

//����һ��������¼���������������
#define LGLR_MAX_N 100




//�������ղ�ֵ����ʽ�ṹ��
typedef struct mylglrc{
    //����ʽ���
    Mult mults[LGLR_MAX_N];
    //֮ǰ����ĵ������
    Pos points[LGLR_MAX_N];
    //֮ǰ����ĵ������
    int n;
}Lglrc,*Lglrcp;


//����������ղ�ֵ����ʽ

//ͨ������ĵ������õ�һ���������ղ�ֵ����ʽ
Lglrc lglrc_get(Posp points,int n);



//�������ղ�ֵ����ʽ����


//���������ղ�ֵ����ʽ�ж��һϵ�е����µ��������ն���ʽ
Lglrc lglrc_insert(Lglrc lglrc,Posp adds,int numOfAdds);


//��ȡ�������ն���ʽ��Ϣ

//��ӡ�������ն���ʽ
void lglrc_show(Lglrc lglrc,char x);



//�����Ա���x��ֵ������������ն���ʽ�ĺ���ֵ
double lglrc_getvalue(Lglrc lglrc,double x);






#endif