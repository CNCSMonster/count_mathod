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
    //����ʽ

    //֮ǰ����ĵ�

}Lglrc,*Lglrcp;


//����������ղ�ֵ����ʽ

//ͨ������ĵ������õ�һ���������ղ�ֵ����ʽ
Lglrc lglrc_get(Posp points,int n);



//�������ղ�ֵ����ʽ����


//���������ղ�ֵ����ʽ�ж��һ����


//��ȡ�������ն���ʽ��Ϣ






#endif