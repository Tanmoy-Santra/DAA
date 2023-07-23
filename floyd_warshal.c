#include<stdio.h>
#define INF 9999
int n,g[10][10],d[10][10],p[10][10];
int path(int s,int t){
    if(p[s][t]==INF){
        return 0;
    }
    else{
        printf(" %d",p[s][t]);
        path(p[s][t],t);
    }
    //("\n");
}
void print(){
    int i,j;
    printf("\nd matrix is : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
           printf("\t%d",d[i][j]);
        }
       printf("\n");
    }
    printf("\np matrix is : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
           printf("\t%d",p[i][j]);
        }
       printf("\n");
    }
}
void floyd(){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            d[i][j]=g[i][j];
            p[i][j]=INF;
        }
       }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(d[i][j]>(d[i][k]+d[k][j])){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=k;
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
    printf("\nall possible path : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("\npath between %d -- %d\n",i,j);
            printf(" %d",i);
            path(i,j);
            printf(" %d",j);
            printf("\noptimal cost %d\n",d[i][j]);
        }
        
        printf("\n");
       
    }
    
}
/*
0 8 0 1
0 0 1 0
4 0 0 0
0 2 9 0

0 4 11
6 0 2
3 0 0

A B C D E
0 2 3 0 0
5 0 0 7 4
7 3 0 6 0
0 0 1 0 5
0 0 0 3 0
*/