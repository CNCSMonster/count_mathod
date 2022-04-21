

#include "ndc.h"


//����ţ�ٲ�ֵ����ʽ

//���ݵ��еõ�ţ�ٲ�ֵ����ʽ
Ndc ndc_get(Posp points,int n){
    //
    Ndc out;
    if(n<=0){
        printf("�����������\n");
        return out;
    }
    for(int i=0;i<n;i++){
        out.points[i]=points[i];
    }
    out.n=n;
    double st=points[0].y;
    out.mult=mult_get(&st,1);
    double ssst[2];
    ssst[0]=-points[0].x;
    ssst[1]=1;
    Mult co=mult_get(ssst,2);



    for(int i=1;i<out.n;i++){
        
        //�������i����ʱ��
        //�¼������Ϊ����Yi - Fi-1(Xi) )(x- Xi + 1)(x - Xi-1 )...(x-X0)
        //����Fi-1Ϊ����i��ǰ��ţ�ٲ�ֵ����ʽ������Fi-1(Xi)Ϊ����Xi������ֵ
        double x=out.points[i].x;
        double y=out.points[i].y;
        
        double before=mult_get_value(out.mult,x);

        
        Mult add=mult_num_mult(co,(y-before)/mult_get_value(co,x));

        //��������
        out.mult=mult_add(out.mult,add);

        //ˢ��co
        double coe[2];
        coe[0]=-x;
        coe[1]=1;
        co=mult_mult(co,mult_get(coe,2));

    }
    out.co=co;
    return out;
}

//��ţ�ٲ�ֵ����ʽ����


//������ʽ���һϵ�е㣬�õ��µĶ���ʽ
Ndc ndc_insert(Ndc ndc,Posp adds,int numOfAdds){
    
    //�ж��Ƿ񳬹�����
    if(ndc.n+numOfAdds>MULT_MAX_N){
        printf("�����ɲ�����Ŀ����,�뵽mult.h���޸�");
        return ndc; //��������Ķ���ʽ�ĸ���
    }

    for(int i=0;i<numOfAdds;i++){
        ndc.points[i+ndc.n]=adds[i];
    }

    ndc.n+=numOfAdds;

    Mult co=ndc.co;

    for(int i=ndc.n-numOfAdds;i<ndc.n;i++){
        
        //�������i����ʱ��
        //�¼������Ϊ����Yi - Fi-1(Xi) )(x- Xi + 1)(x - Xi-1 )...(x-X0)
        //����Fi-1Ϊ����i��ǰ��ţ�ٲ�ֵ����ʽ������Fi-1(Xi)Ϊ����Xi������ֵ
        double x=ndc.points[i].x;
        double y=ndc.points[i].y;
        
        double before=mult_get_value(ndc.mult,x);

        Mult add=mult_num_mult(co,(y-before)/mult_get_value(co,x));

        //��������
        ndc.mult=mult_add(ndc.mult,add);

        //ˢ��co
        double coe[2];
        coe[0]=-x;
        coe[1]=1;
        co=mult_mult(co,mult_get(coe,2));

    }
    ndc.co=co;
    return ndc;
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

