#include<stdio.h>
int n,g[10][10],vis[10];
void dfs(int v){
    int i;
    printf(" %d ",v);
    vis[v]=1;
    for(i=1;i<=n;i++){
        if(vis[i]!=1 && g[v][i]==1){
            dfs(i);
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
    }
    dfs(1);

}
/*
0 1 1 0 0 0 0 0 
1 0 0 1 1 0 0 0 
1 0 0 0 0 1 1 0
0 1 0 0 0 0 0 1
0 1 0 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 0 1 1 1 1 0

*/

