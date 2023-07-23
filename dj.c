#include<stdio.h>
#define INF 9999
int n,g[10][10],dist[10],status[10],pre[10];
int path(int s,int t){
     if(pre[t]==0){	
	printf("%d",t);
	}
	else{        
	path(s,pre[t]);	
    printf("-->%d",t);		
	
    }

}

void print_details(){
	int i;
	printf("\nsortest path estimate : \n");
	for(i=1;i<=n;i++)
	printf("%d ",dist[i]);
	
	printf("\npredecesor vertex : \n");
	for(i=1;i<=n;i++)
	printf("predecesor of %d is %d \n",i,pre[i]);
}

void dj(int s){
    int i,c,j,min,u,v,t;
    for(i=1;i<=n;i++){
		status[i]=0;
		dist[i]=INF;
		pre[i]=0;
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
    // printf("\nenter the terget vertex : ");
    // scanf("%d",&t);
    
    for(i=1;i<=n;i++){
    printf(" [with cost %d] ",dist[i]);
    path(s,i);
    printf("\n");
    }
    print_details();
   


}
/*
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0

0 1 2 1 0
0 0 0 0 0
0 2 0 9 3
0 5 0 0 0
6 0 0 4 0

0 5 2 10 6
5 0 13 5 0
2 13 0 9 3
10 5 9 0 4
6 0 3 4 0
*/