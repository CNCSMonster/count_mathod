#include "mult.h"

//��������ʽ

/*���������ϵ������õ�һ������ʽ
�����n��ʾ�������Чϵ��������Ҳ��ʾ�����ϵ����Ӧ����ߴ���+1
�ٸ����ӣ�Ҫ���1+3*x^2������Ҫ��������ϵ����0,1,2����ϵ����
�������double����Ϊ[1,0,3],nΪ3
*/
Mult mult_get(double* val,int n){
    Mult out;
    memset(out.val,0,sizeof(out.val));
    for(int i=0;i<n;i++){
        out.val[i]=val[i];
    }
    out.max=n;
    //ȷ������ʽ�������
    for(int i=out.max-1;i>0;i--){
        if(out.val[i]<MULT_NEAR_ZERO){
            out.max=i;
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
    for(int i=out.max-1;i>0;i--){
        if(out.val[i]<MULT_NEAR_ZERO){
            out.max=i;
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
        out.val[i]=a.val[i]+b.val[i];
    }
    //ȷ������ʽ�������
    for(int i=out.max-1;i>0;i--){
        if(out.val[i]<MULT_NEAR_ZERO){
            out.max=i;
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
    for(int i=out.max-1;i>0;i--){
        if(out.val[i]<MULT_NEAR_ZERO){
            out.max=i;
            break;
        }
    }
    return out;
}

//�ݲ�ʵ��
Mult mult_divi(Mult a,Mult b){
    
}



//��ȡ����ʽ��Ϣ


//���㴫���Ա���x��Ķ���ʽʽֵ
double mult_get_value(double x){

}

//��ӡ����ʽ
void mult_show(Mult mult,char x){

}









