#include "../all.h"

//����������Ա���x��ֵ����ԭ������ֵ
double f_yuan(double x);

//����������Ա���x��ֵ��ԭ����������ֵ
double f_dao(double x);

double ndd_count_b(double st,double w1,double w2,int* ifok);


int main(){
    do{
        double w1=0.0001;
        double w2=0.00000001;
        printf("\n���������ֵ��");
        double st;
        scanf("%lf",&st);
        printf("\n���뺯���޲�w1��");
        scanf("%lf",&w1);
        printf("\n���뵼���޲�w2��");
        scanf("%lf",&w2);
        printf("\n����ֵ�޲�Ϊ��%.10f����ֵ�޲�Ϊ��%.10f������ֵΪ:%.3f\n",w1,w2,st);
        int ifok;
        double v=ndd_count_b(st,w1,w2,&ifok);
        if(ifok==0){
            printf("\n����ʧ��\n");
            
        }else{
            printf("\n����ɹ�\n");
            printf("�����%.4Lf",v);
            printf("����e�˳�,�����������������");
            char choice=getch();
            if(choice=='e'){
                break;
            }
        }
    }while(1);
    getch();
    return 0;
}

//����������Ա���x��ֵ����ԭ������ֵ
double f_yuan(double x){
    return sin(x)*pow(x,3)-log(x+1)/log(10)+pow(x,2)-x;
}

//����������Ա���x��ֵ��ԭ����������ֵ
double f_dao(double x){
    return sin(x)*3*pow(x,2)+cos(x)*pow(x,3)-1.0/(x+1)/log(10)+2*x-1;
}

double ndd_count_b(double st,double w1,double w2,int* ifok){
    do{
        if(fabs(f_dao(st))<w2){
            //ţ�ٵ�������ʧ��
            *ifok=0;
            break;
        }
        if(fabs(f_yuan(st))<w1){
            //ţ�ٵ�������ɹ�
            *ifok=1;
            break;
        }
        st=st-f_yuan(st)/f_dao(st);
    }while(1);
    return st;
}

