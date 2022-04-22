#include "mult.h"

//��������ʽ

/*���������ϵ������õ�һ������ʽ
�����n��ʾ�������Чϵ��������Ҳ��ʾ�����ϵ����Ӧ����ߴ���+1
�ٸ����ӣ�Ҫ���1+3*x^2������Ҫ��������ϵ����0,1,2����ϵ����
�������double����Ϊ[1,0,3],nΪ3
*/
Mult mult_get(double val[],int n){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    for(int i=0;i<n;i++){
        out.val[i]=val[i];
    }
    out.max=n;
    //ȷ������ʽ�������
    for(int i=out.max-1;i>=0;i--){
        if(i==0){
            out.max=1;
            break;
        }
        if(fabs(out.val[i])>=MULT_NEAR_ZERO){
            out.max=i+1;
            break;
        }
    }
    return out;
}


//����һ���൱��0�Ŀհ׶���ʽ
Mult mult_zero(void){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.val[0]=0;
    out.max=1;

    return out;
}

//����һ���൱��1�Ŀհ׶���ʽ
Mult mult_one(void){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.val[0]=1;
    out.max=1;
    return out;
}



//����ʽ����

//����ʽ�ӷ�
Mult mult_add(Mult a,Mult b){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.max=a.max>b.max?a.max:b.max;
    for(int i=0;i<out.max;i++){
        out.val[i]=a.val[i]+b.val[i];
    }
    //ȷ������ʽ�������
    for(int i=out.max-1;i>=0;i--){
        if(i==0){
            out.max=1;
            break;
        }
        if(fabs(out.val[i])>=MULT_NEAR_ZERO){
            out.max=i+1;
            break;
        }
    }
    return out;
}

//����ʽ����
Mult mult_minus(Mult a,Mult b){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.max=a.max>b.max?a.max:b.max;
    for(int i=0;i<out.max;i++){
        out.val[i]=a.val[i]-b.val[i];
    }
    //ȷ������ʽ�������
    for(int i=out.max-1;i>=0;i--){
        if(i==0){
            out.max=1;
            break;
        }
        if(fabs(out.val[i])>=MULT_NEAR_ZERO){
            out.max=i+1;
            break;
        }
    }
    return out;
}

//����ʽ�˷�
Mult mult_mult(Mult a,Mult b){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.max=a.max+b.max-1;
    for(int i=0;i<a.max;i++){
        for(int j=0;j<b.max;j++){
            out.val[i+j]+=a.val[i]*b.val[j];
        }
    }
    //ȷ������ʽ�������
    for(int i=out.max-1;i>=0;i--){
        if(i==0){
            out.max=1;
            break;
        }
        if(fabs(out.val[i])>=MULT_NEAR_ZERO){
            out.max=i+1;
            break;
        }
    }
    return out;
}

//�ݲ�ʵ��
Mult mult_divi(Mult a,Mult b){
    Mult out;
    return out;
}

//����ʽ������,mult����coe(coefficient)
Mult mult_num_mult(Mult mult,double coe){
    for(int i=0;i<mult.max;i++){
        mult.val[i]*=coe;
    }
     //ȷ������ʽ�������
    for(int i=mult.max-1;i>=0;i--){
        if(i==0){
            mult.max=1;
            break;
        }
        if(fabs(mult.val[i])>=MULT_NEAR_ZERO){
            mult.max=i+1;
            break;
        }
    }
    return mult;
}


//����ʽ��,��ö���ʽ�ĵ���
Mult mult_dao(Mult mult){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    out.max=mult.max-1;
    for(int i=1;i<mult.max;i++){
        out.val[i-1]=mult.val[i]*i;
    }
    return out;
}



//��ȡ����ʽ��Ϣ


//���㴫���Ա���x��Ķ���ʽʽֵ
double mult_get_value(Mult mult,double x){
    double out=0;
    for(int i=0;i<mult.max;i++){
        double coe=pow(x,i);
        out+= coe*mult.val[i];
    }
    return out;
}

//��ӡ����ʽ��ϵ����ӡʱ����2λС��
void mult_show(Mult mult,char x){

    //�������������ʽΪ0����ʽʱ
    if(mult.max==1){
        printf("%.2Lf",mult.val[0]);
        return;
    }

    //firstΪ1��ʾ������ǵ�һ����Ч��
    int first=1;    
    for(int i=0;i<mult.max;i++){
        if(i==0&&fabs(mult.val[i])>=MULT_NEAR_ZERO){
            printf("%.2Lf",mult.val[i]);
            first=0;
        }else{
            if(fabs(mult.val[i])>=MULT_NEAR_ZERO){
                if(mult.val[i]>0&&first!=1){
                    printf("+%.2Lf",mult.val[i]);
                    printf("%c^%d",x,i);
                }else{
                    printf("%.2Lf",mult.val[i]);
                    printf("%c^%d",x,i);
                    if(first==1){
                        first=0;
                    }
                }
            }
        }
    }
}











