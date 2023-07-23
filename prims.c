#include<stdio.h>
#define INF 9999
int n,g[20][20],vis[10];
void prims(int s){
    int i,k,j,min,mincost=0,v1,v2;
    vis[s]=1;
    for(k=1;k<=n-1;k++){
        min=INF;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(g[i][j]!=INF && vis[i]==1 && vis[j]==0){
                    if(g[i][j]<min){
                        min=g[i][j];
                        v1=i;
                        v2=j;
                    }
                }
            }
        }
        
        mincost=mincost+min;
        printf("\n edge %d (%d -> %d) wthi the cost  %d",k,v1,v2,min);
        vis[v2]=vis[v1]=1;
    }
    printf("\nmincost %d",mincost);
}
int main(){
    int i,j;
    printf("\nenter the size of matrix : ");
    scanf("%d",&n);
    printf("\nenter the elemennts : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
            if(g[i][j]==0)
            g[i][j]=INF;
            
        }
        vis[i]=0;
    }
    prims(1);
}
/*
0 28 0 0 0 10 0
28 0 16 0 0 0 14
0 16 0  12 0 0 0
0 0 12 0 22 0 18
0 0 0 22 0 25 24
10 0 0 0 25 0 0
0 14 0 18 24 0 0


0 4 0 0 0 0 0 0 8
4 0 0 8 0 0 0 0 11
0 0 0 2 0 0 0 6 7
0 8 2 0 7 0 4 0 0 
0 0 0 7 0 9 14 0 0
0 0 0 0 9 0 10 0 0
0 0 0 4 14 10 0 2 0
0 0 6 0 0 0 2 0 1
8 11 7 0 0 0 0 1 0

*/