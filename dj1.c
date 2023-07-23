#include<stdio.h>
#define INF 9999
int g[10][10],dist[10],status[10],n,pre[10];
void print_details(){
	int i;
	printf("\nsortest path estimate : \n");
	for(i=1;i<=n;i++)
	printf("%d ",dist[i]);
	
	printf("\npredecesor vertex : \n");
	for(i=1;i<=n;i++)
	printf("predecesor of %d is %d \n",i,pre[i]);
}
int path(int t){
    if(t==1)
    printf(" 1 ");
    else{
        printf(" %d ",t);
        path(pre[t]);
    }
}
void dj(int s){
    int i,c,v,min,u;
    for(i=1;i<=n;i++){
        dist[i]=INF;
        pre[i]=0;
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
                dist[v]=(dist[u]+g[u][v]);
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