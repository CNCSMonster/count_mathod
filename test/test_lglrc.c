#include "..\all.h"

int main(){
    do{
        int n;
        printf("\n�����ֵ�ĵ�ĸ���Ϊ��");
        scanf("%d",&n);
        Pos points[n];
        printf("��x,y����ʽ����%d����Ϊ:\n",n);
        for(int i=0;i<n;i++){
            printf("�����[%d]:",i);
            double x;
            double y;
            scanf("%lf,%lf",&x,&y);
            points[i]=pos_get(x,y);
        }
        printf("\n���ɵ��������ղ�ֵ��ʽΪ��");
        Lglrc lglrc=lglrc_get(points,n);
        char x='x';
        lglrc_show(lglrc,x);
        do{
            printf("\n�Ƿ�����µĵ㣬�����µ��������ղ�ֵ��ʽ");
            printf("\n����e�˳�,�����������µĵ�");
            char c=getch();
            if(c=='e'){
                break;
            }else{
                printf("\n�����µĵ㣨�����ʽ���ϣ�:");
                double tx;
                double ty;
                scanf("%lf,%lf",&tx,&ty);
                Pos add=pos_get(tx,ty);
                lglrc=lglrc_insert(lglrc,&add,1);
                printf("�µ��������ղ�ֵ����Ϊ��");
                lglrc_show(lglrc,x);
            }
        }while(1);
        printf("\n����e�˳�,����������");
        char c=getch();
        if(c=='e'){
            break;
        }
    }while(1);







    int max_num=10;
    Pos points[max_num];
    points[0]=pos_get(1,2);
    points[1]=pos_get(0,0);
    points[2]=pos_get(2,0);
    // points[3]=pos_get();
    // points[4]=pos_get();
    // points[5]=pos_get();
    // points[6]=pos_get();
    // points[7]=pos_get();
    Lglrc lglrc=lglrc_get(points,2);
    char x='x';
    lglrc_show(lglrc,x);

    printf("\n�¼���һ����(2,0)��\n");
    lglrc=lglrc_insert(lglrc,&points[2],1);
    lglrc_show(lglrc,x);






    getchar();
    return 0;
}