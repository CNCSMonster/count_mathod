#include "../all.h"

int main(){
    double coe[5]={1,2,1};
    Func func=func_get(coe,3);
    char x='x';
    printf("ʹ��ţ�ٵ������󷽳�");
    func_show(func,x);
    printf("=0 �Ľ�\n");
    double w1=0.0001;
    double w2=0.00000001;
    do{
        printf("���������ֵ��");
        double st;
        scanf("%lf",&st);
        printf("����ֵ�޲�Ϊ��%.10f����ֵ�޲�Ϊ��%.10f������ֵΪ:%.3f\n",w1,w2,st);
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