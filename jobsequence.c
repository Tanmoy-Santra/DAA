#include<stdio.h>
int n,p[10],id[10],d[10],x[10],dmax;
void d_max(){
    int i,dmax_t;
    dmax_t=d[0];
    for(i=0;i<=n-1;i++){
        if(dmax_t<d[i]){
            dmax_t=d[i];
        }
    }
    dmax=dmax_t;
    printf("\nmaximum no of slots are :%d",dmax);
}
void job(){
    int i,j,maxd,c=0,k,sump=0;
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
    printf("\nmax_profit is %d",sump);
}
void sort(){
	int i,j;
	int t;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
			if(p[j]<p[j+1])
			{
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
    int i,j;
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
    d_max();
    job();
    printf("\nsolution vector :\n");
    for(i=0;i<=dmax;i++){
        if(x[i]!=-1){
            printf(" %d ",id[x[i]]);
        }
    }
}
    

