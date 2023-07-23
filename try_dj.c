#include<stdio.h>
#include<stdlib.h>
#define INF 999
int g[20][20],pre[20],dist[20],status[20],n;
int path(int t){
    if(t==1){
        printf(" 1 ");
    }
    else{
        printf(" %d ",t);
        path(pre[t]);
    }
}
void print_details(){
    int i;
    printf("\nshortest path estimate :\n");
    for(i=1;i<=n;i++){
        printf("%d ",dist[i]);
    }
    printf("\npedecesors :\n");
    for(i=1;i<=n;i++){
        printf("predecesor of %d is %d ",i,pre[i]);
    }
}
void dj(int s){
    int u,min,i,c,v;
    for(i=1;i<=n;i++){
        pre[i]=0;
        dist[i]=INF;
        status[i]=0;
    }
    dist[s]=0;
    for(c=1;c<=n;c++){
        min=INF;
        for(i=1;i<=n;i++){
            if(dist[i]<min && status[i]!=1){
                min=dist[i];
                u=i;
            }

        }
        status[u]=1;
        for(v=1;v<=n;v++){
            if(dist[v]>(dist[u]+g[u][v]) && status[v]!=1){
                dist[v]=dist[u]+g[u][v];
                pre[v]=u;
            }
        }
    }
}
int main(){
    int i,j,s,t;
    printf("\nenter the size of matrix : ");
    scanf("%d",&n);
    printf("\nenter the elemennts : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
            if(g[i][j]==0)
            g[i][j]=INF;            
        }
       
    }
    printf("\nenter the source vertex : ");
    scanf("%d",&s);
    dj(s);
    printf("\nenter the terget vertex : ");
    scanf("%d",&t);
    print_details();
    printf(" [with cost %d] ",dist[t]);
    path(t);


}