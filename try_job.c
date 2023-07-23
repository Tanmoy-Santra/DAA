#include<stdio.h>
int id[20],d[20],dmax,p[20],n,x[20],sump=0.0;
void job(){
    int i,j,k,c;
    for(i=0;i<=n-1;i++)
    x[i]=-1;
    for(i=0;i<=n-1;i++){
        k=d[i];
        while(k>0){
            if(x[k]==-1){
                x[k]=i; 
                c++;
                sump=sump+p[i];
                break;
            }
            k--;
        }
        if(c==dmax){
            break;
        }
    }
    printf("\nsolution vector : ");
    for(i=0;i<=dmax;i++){
        if(x[i]!=-1){
            printf(" %d ",id[x[i]]);
        }
    }
    printf("\nprofit %d",sump);
}
void max_deadline(){
    int i,max=d[0];
    for(i=0;i<=n-1;i++){
        if(max<d[i]){
            max=d[i];
        }
    }    
    dmax=max;
}
void sort(){
    int i,j,t;
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-i-1;j++){
          if(p[j]<p[j+1]) {
            t=p[j];
            p[j]=p[j+1];
            p[j+1]=t;

            t=id[j];
            id[j]=id[j+1];
            id[j+1]=t;

            t=d[j];
            d[j]=d[j+1];
            d[j+1]=t;
          }

        }
        
    }
}
int main(){
    int i;
    printf("\nenter the no of jobs : ");
    scanf("%d",&n);
    printf("\nenter id : ");
    for(i=0;i<=n-1;i++)
    scanf("%d",&id[i]);
    printf("\nenter the profits :");
    for(i=0;i<=n-1;i++)
    scanf("%d",&p[i]);
    printf("\nenter the deadlines : ");
    for(i=0;i<=n-1;i++)
    scanf("%d",&d[i]);
    sort();
    max_deadline();
    job();
}