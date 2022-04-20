//mult.h
#ifndef _MULT_H_ //���û������ͷ�ļ�mult.h
    #define _MULT_H_ //�Ǿ�����ͷ�ļ�mult.h

#include <mem.h>
#include <math.h>


//����ʽ�������
#define MULT_MAX_N 100

//�����0�ٽ�С��
//Ҳ����˵���һ��ϵ��С�������ʱ��������Ϊ����0
#define MULT_NEAR_ZERO 10E-8

typedef struct mymult{
    //����ʽϵ��
    double val[MULT_MAX_N];
    //����ʽ����������
    int max;
}Mult,*Multp;

//��������ʽ

/*���������ϵ������õ�һ������ʽ
�����n��ʾ�������Чϵ��������Ҳ��ʾ�����ϵ����Ӧ����ߴ���+1
�ٸ����ӣ�Ҫ���1+3*x^2������Ҫ��������ϵ����0,1,2����ϵ����
�������double����Ϊ[1,0,3],nΪ3
*/
Mult mult_get(double val[],int n);


//����һ���൱��0�Ŀհ׶���ʽ
Mult mult_zero(void);

//����һ���൱��1�Ŀհ׶���ʽ
Mult mult_one(void);



//����ʽ����

//����ʽ�ӷ�
Mult mult_add(Mult a,Mult b);

//����ʽ����
Mult mult_minus(Mult a,Mult b);

//����ʽ�˷�
Mult mult_mult(Mult a,Mult b);

//����ʽ����
Mult mult_divi(Mult a,Mult b);

//����ʽ������,mult����coe(coefficient)
Mult mult_num_mult(Mult mult,double coe);



//��ȡ����ʽ��Ϣ


//���㴫���Ա���x��Ķ���ʽʽֵ
double mult_get_value(Mult mult,double x);

//��ӡ����ʽ,�����xΪ�Ա�������
void mult_show(Mult mult,char x);







#endif