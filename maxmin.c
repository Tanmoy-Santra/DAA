#include<stdio.h>
int a[100],n,max,min;
int maxmin(int l,int h){
    int mid,max1,min1,i,j;
    if(l==h){
        max=min=a[l];
    }
    else if(l==h-1){
        if(a[l]>a[h]){
            max=a[l];
            min=a[h];
        }
        else{
            max=a[h];
            min=a[l];
        }
    }
    else{
        mid=(l+h)/2;
        maxmin(l,mid);
        max1=max;
        min1=min;
        maxmin(mid+1,h);
        if(max1>max){
            max=max1;
        }
        if(min1<min){
            min=min1;
        }
    }

}
int main(){
	int i;
	printf("\nenter the size of array-");
	scanf("%d",&n);
	printf("\nenter the elements-");
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
	printf("\nelements are-");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	maxmin(0,n-1);
	printf("\n\n\n\nfinal max=%d min=%d",max,min);
	
}