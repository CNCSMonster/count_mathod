#include "lglrc.h"


//����������ղ�ֵ����ʽ

//ͨ������ĵ������õ�һ���������ղ�ֵ����ʽ
Lglrc lglrc_get(Posp points,int n){
    //���б߽��ж�
    if(n>=LGLR_MAX_N){
        printf("����ĵ�ĸ����������ƣ������lglrc.h�ļ����޸�");
    }
    Lglrc out;
    out.n=n;
    for(int i=0;i<out.n;i++){
        out.points[i]=points[i];
    }
    for(int i=0;i<out.n;i++){
        double a=out.points[i].y;
        Mult add=mult_one();
        for(int j=0;j<out.n;j++){
            if(i==j){
                continue;
            }
            a/=(out.points[i].x-out.points[j].x);
            double coe_t[2];
            coe_t[0]=-out.points[j].x;
            coe_t[1]=1;
            Mult term=mult_get(coe_t,2);
            add=mult_mult(add,term);
        }
        out.mults[i]=mult_num_mult(add,a);
    }
    return out;
}



//�������ղ�ֵ����ʽ����


//���������ղ�ֵ����ʽ�ж��һϵ�е����µ��������ն���ʽ
Lglrc lglrc_insert(Lglrc lglrc,Posp adds,int numOfAdds){
    if(lglrc.n+numOfAdds>LGLR_MAX_N){
        printf("����ĵ�ĸ����������ƣ������lglrc.h�ļ����޸�");
    }
    //�����µĵ���
    //�Լ�Ϊ���¾ɵ���׼���Ĳ���
    Mult times=mult_one();
    for(int i=0;i<numOfAdds;i++){
        lglrc.points[lglrc.n+i]=adds[i];
        double ta[2];
        ta[0]=-adds[i].x;
        ta[1]=1;
        Mult term=mult_get(ta,2);
        times=mult_mult(times,term);
    }
    //�޸ľɵ���
    for(int i=0;i<lglrc.n;i++){
        Mult term=mult_num_mult(times,1.0/mult_get_value(times,lglrc.points[i].x));
        lglrc.mults[i]=mult_mult(lglrc.mults[i],term);
    }
    //�����µ���
    for(int i=lglrc.n;i<lglrc.n+numOfAdds;i++){
        double a=lglrc.points[i].y;
        Mult add=mult_one();
        for(int j=0;j<lglrc.n+numOfAdds;j++){
            if(i==j){
                continue;
            }
            a/=(lglrc.points[i].x-lglrc.points[j].x);
            double coe_t[2];
            coe_t[0]=-lglrc.points[j].x;
            coe_t[1]=1;
            Mult term=mult_get(coe_t,2);
            add=mult_mult(add,term);
        }
        lglrc.mults[i]=mult_num_mult(add,a);
    }
    //���³���
    lglrc.n+=numOfAdds;
    return lglrc;
}


//��ȡ�������ն���ʽ��Ϣ

//��ӡ�������ն���ʽ
void lglrc_show(Lglrc lglrc,char x){
    Mult show=mult_zero();
    for(int i=0;i<lglrc.n;i++){
        show=mult_add(show,lglrc.mults[i]);
    }
    mult_show(show,x);
}

//�����Ա���x��ֵ������������ն���ʽ�ĺ���ֵ
double lglrc_getvalue(Lglrc lglrc,double x){
    double out=0;
    for(int i=0;i<lglrc.n;i++){
        out+=mult_get_value(lglrc.mults[i],x);
    }
    return out;
}