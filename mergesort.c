#include<stdio.h>
int n,a[10];
void merge(int l,int mid ,int h){
    int i,j,k,b[10];
    i=l;
    j=mid+1;
    k=l;
    while((i<=mid) && (j<=h)){
        if(a[i]>a[j]){
            b[k++]=a[j++];
        }
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=h){
        b[k++]=a[j++];
    }
    for(k=l;k<=h;k++){
        a[k]=b[k];
    }

}
int mergesort(int l,int h){
    int mid;
    mid=(l+h)/2;
    if(l<h){
        mergesort(l,mid);
        mergesort(mid+1,h);
        merge(l,mid,h);
    }
}
int main(){
	int i;
	printf("enter the size of array-");
	scanf("%d",&n);
	printf("\nenter the elements-");
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
	printf("\nelements before sorting-");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	mergesort(0,n-1);
	printf("\nelements after sorting-");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
}