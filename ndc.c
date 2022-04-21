

#include "ndc.h"


//����ţ�ٲ�ֵ����ʽ

//���ݵ��еõ�ţ�ٲ�ֵ����ʽ
Ndc ndc_get(Posp points,int n){
    //
    Ndc out;
    out.mult=mult_zero();
    for(int i=0;i<n;i++){
        out.points[i]=points[i];
    }
    out.n=n;

    Mult a=mult_one();  //������¼�м䲿��
    for(int i=0;i<out.n;i++){
        double tt[2];
        tt[0]=1-points[i].x;
        tt[1]=1;
        Mult term=mult_get(tt,2);
        term=mult_num_mult(term,points[i].y-mult_get_value(out.mult,points[i].x));
        term=mult_mult(term,a);
        //����a
        tt[0]=-points[i].x;
        tt[1]=1;
        a=mult_mult(a,mult_get(tt,2));
        //����out.mult
        out.mult=mult_add(out.mult,term);
    }
    return out;
}

//��ţ�ٲ�ֵ����ʽ����


//������ʽ���һϵ�е㣬�õ��µĶ���ʽ
Ndc ndc_insert(Ndc ndc,Posp adds,int numOfAdds){
    
    //�ж��Ƿ񳬹�����
    if(ndc.n+numOfAdds>MULT_MAX_N){
        printf("�����ɲ�����Ŀ����,�뵽mult.h���޸�");
    }
    
    

    Mult a=mult_one();  //������¼�м䲿��
    for(int i=0;i<ndc.n;i++){

    }



    for(int i=ndc.n;i<out.n;i++){
        //�ڶ���ʽ��¼�ĵ��в������ĵ�
        ndc.points[i]=adds[i-ndc.n];
        double tt[2];
        tt[0]=1-points[i].x;
        tt[1]=1;
        Mult term=mult_get(tt,2);
        term=mult_num_mult(term,points[i].y-mult_get_value(out.mult,points[i].x));
        term=mult_mult(term,a);
        //����a
        tt[0]=-points[i].x;
        tt[1]=1;
        a=mult_mult(a,mult_get(tt,2));
        //����out.mult
        out.mult=mult_add(out.mult,term);
    }
    ndc.n+=numOfAdds;

    return out;

}


//���ţ�ٲ�ֵ����ʽ��Ϣ

//��ӡ����ʽ
void ndc_show(Ndc ndc,char x){

    mult_show(ndc.mult,x);
}

//����������Ա�����ȡ����ʽֵ
double ndc_get_value(Ndc ndc,double x){
    return mult_get_value(ndc.mult,x);
}

