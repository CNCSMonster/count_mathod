//pos.h
#ifndef _POS_H_ //���û������ͷ�ļ�pos.h
    #define _POS_H_ //�Ǿ�����ͷ�ļ�pos.h


typedef struct mypos{
    double x;
    double y;
}Pos,*Posp;


Pos pos_get(double x,double y);





#endif