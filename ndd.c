#include "ndd.h"

//ͨ������ĺ���func,�ͳ�ʼֵst,�Ժ����������w1���͵��������w2��ʹ��ţ�ٵ�������func=0���̵Ľ�
//ͨ��ifok����¼�Ƿ�ɹ�
double ndd_count(Func func,double st,double w1,double w2,int* ifok){
    do{
        if(fabs(ndd_dao(func,st))<w1){
            *ifok=0;
            break;
        }
        if(fabs(ndd_yuan(func,st)<w1)){
            *ifok=1;
            break;
        }
        st=st-ndd_yuan(func,st)/ndd_dao(func,st);
    }while(1);
    return st;
}

//���func��x���ĺ���ֵ
double ndd_yuan(Func func ,double x){

}

//���func������x���ĺ���ֵ
double ndd_dao(Func func,double x){

}







