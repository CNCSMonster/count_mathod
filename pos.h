//pos.h
#ifndef _POS_H_ //如果没有引入头文件pos.h
    #define _POS_H_ //那就引入头文件pos.h


typedef struct mypos{
    double x;
    double y;
}Pos,*Posp;


Pos pos_get(double x,double y);





#endif