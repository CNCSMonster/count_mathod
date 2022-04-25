#include "..\all.h"

int main(){
    do{
        int n;
        printf("\n输入插值的点的个数为：");
        scanf("%d",&n);
        Pos points[n];
        printf("以x,y的形式输入%d个点为:\n",n);
        for(int i=0;i<n;i++){
            printf("输入点[%d]:",i);
            double x;
            double y;
            scanf("%lf,%lf",&x,&y);
            points[i]=pos_get(x,y);
        }
        printf("\n生成的拉格朗日插值公式为：");
        Lglrc lglrc=lglrc_get(points,n);
        char x='x';
        lglrc_show(lglrc,x);
        do{
            printf("\n是否加入新的点，生成新的拉格朗日插值公式");
            printf("\n输入e退出,其他键加入新的点");
            char c=getch();
            if(c=='e'){
                break;
            }else{
                printf("\n输入新的点（输入格式如上）:");
                double tx;
                double ty;
                scanf("%lf,%lf",&tx,&ty);
                Pos add=pos_get(tx,ty);
                lglrc=lglrc_insert(lglrc,&add,1);
                printf("新的拉格朗日插值函数为：");
                lglrc_show(lglrc,x);
            }
        }while(1);
        printf("\n输入e退出,其他键继续");
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

    printf("\n新加入一个点(2,0)后\n");
    lglrc=lglrc_insert(lglrc,&points[2],1);
    lglrc_show(lglrc,x);






    getchar();
    return 0;
}