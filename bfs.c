#include<stdio.h>
int q[10],vis[10],f=0,r=-1,g[10][10],n;
void bfs(int v){
    int i,j;
    for(i=1;i<=n;i++){
        if((!vis[i] && g[v][i]==1)){
            vis[i]=1;
            q[++r]=i;
            printf(" %d",i);
        }
        if(f<=r){
            bfs(q[f++]);
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
        }
       vis[i]=0;
       q[i]=0;
    }
    vis[1]=1;
    printf(" 1");
    bfs(1);
    
}