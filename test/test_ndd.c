#include "../all.h"







int main(){




    do{
        printf("��������ţ�ٵ����Ķ���ʽ�͵���ʽ����ߴ�:");
        int max;
        scanf("%d",&max);
        double coe[max+1];
        for(int i=0;i<max+1;i++){
            printf("%d����ϵ��Ϊ",i);
            scanf("%lf",&coe[i]);
        }
        Func func=func_get(coe,max+1);
        char x='x';
        printf("ʹ��ţ�ٵ������󷽳�");
        func_show(func,x);
        printf("=0 �Ľ�\n");
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
        double v=ndd_count(func,st,w1,w2,&ifok);
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