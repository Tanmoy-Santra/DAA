#include<stdio.h>
int m[10],n;
int bs(int l,int h,int key){
    int mid;
    mid=(l+h)/2;
    if(l>h)
    return -1;
    else if(m[mid]==key)
    return mid;
    else{
        if(key<m[mid])
        return bs(l,mid-1,key);
        else
        return bs(mid+1,h,key);
    }
}
int main(){
    int i,pos,key;
    printf("\nenter the iz of aay : ");
    scanf("%d",&n);
    printf("\nenter the element : ");
    for(i=1;i<=n;i++){
        scanf("%d",&m[i]);
    }
    printf("\nenter the key value : ");
    scanf("%d",&key);
    pos=bs(1,n,key);
    printf("\nelement is found at position %d",pos);
}