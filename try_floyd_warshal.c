#include<stdio.h>
#define INF 9999
int g[20][20],n,d[20][20],s[20][20];
int path(int i,int j){
    if(s[i][j]==INF){
        return 0;
    }
    else{
        printf("%d->",s[i][j]);
        path(s[i][j],j);
    }
}
void print(){
    int i,j;
    printf("\nd matrix is  : \n");
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                printf("%d\t",d[i][j]);
            }
            printf("\n");
            }
    printf("\ns matrix is : \n");
    for(i=1;i<=n;i++){  
            for(j=1;j<=n;j++){
               printf("%d\t",s[i][j]);
            }
            printf("\n");            
            }
}
void floyd(){
    int i,j,k;
    for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                d[i][j]=g[i][j];
            }
            s[i][j]=INF;
            }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(g[i][j]>(g[i][k]+g[k][j])){
                    g[i][j]=g[i][k]+g[k][j];
                    s[i][j]=k;
                }
            }
        }
    }
}
int main(){
    int i,j;
    printf("\nente tthe size of matrix : ");
    scanf("%d",&n);
    printf("\nenter the cost matrix elements :\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
            if(g[i][j]==0 && i!=j)
            g[i][j]=INF;
        }
       
    }
    floyd();  
    print();
    for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                printf("\npath between %d----%d",i,j);
                printf("\n%d->",i);
                path(i,j);
                printf("\n%d",j);
                printf("cost %d",d[i][j]);
            }
        }

}