#include<stdio.h>
#include<math.h>
int x[10];
int m[10][10];
void print(int n){
    int i,j;    
    printf("\nsolution vector is\n");
    for(i=1;i<=n;i++){
        printf(" %d",x[i]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            m[i][j]=0;
        }
    }
    for(i=1;i<=n;i++){
        m[i][x[i]]=i;
    }
    printf("\nsolution matrix is : \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(m[i][j]==0)
            printf(" .");
            else
           printf(" Q%d",m[i][j]);
        }
        printf("\n");
    }


}
int place(int k,int i){
    int j;
    for(j=1;j<=k-1;j++){
        if((x[j]==i) || (abs(x[j]-i)==abs(j-k))){
            return 0;
        }
        
       
    }
     return 1;
}
int  n_queen(int k,int n){
    int i;
    for(i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
        if(k==n){
            print(n);
        }
        else{
            n_queen(k+1,n);
        }
        }
    }
}
int main(){
    int n,i,j;
    printf("\nenter the no. of queens : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            m[i][j]=0;
        }
        x[i]=0;
    }
    n_queen(1,n);
}