#include<stdio.h>
#include<stdlib.h>
#define INF 9999;
int p[20],s[20][20],m[20][20],n,q;
int  o_p(int i,int j){
    if(i==j){
        printf("A%d",i);
        
    }
    else{
        printf("(");
        o_p(i,s[i][j]);
        o_p(s[i][j]+1,j);
        printf(")");
    }
}

void print(int n1){
    int i,j,k;
    printf("\ncost matrix :\n");
    for(i=1;i<=n1;i++){
        for(j=1;j<=n1;j++){
            if(i<=j)
            printf("%d\t",m[i][j]);
            else
            printf("\t");
        }
        printf("\n");
    }
    printf("\ns matrix:\n");
    for(i=2;i<=n1;i++){
        for(j=1;j<=n1;j++){
            if(i<=j)
            printf("%d\t",s[i][j]);
            else
            printf("\t");
        }
        printf("\n");
    }
     printf("\noptimal cost of matrix multiplication is : %d\n",m[1][n1]);
}
void mat_mult(){
    int l,i,j,k,n1;
    n1=n-1;
    for ( i = 1; i <= n1; i++)
    m[i][i] = 0;
    for(l=2;l<=n1;l++){
        for(i=1;i<=n1-l+1;i++){
            j=l+i-1;
            m[i][j]=INF;
            for(k=i;k<=j-1;k++){
                q=(m[i][k]+m[k+1][j]+(p[i-1]*p[j]*p[k]));
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    print(n1);
    o_p(1,n1);
}
int main(){
    int i;
    printf("\nenter the size os p array size : ");
    scanf("%d",&n);
    printf("\nenter the orders of matrix chain :\n");
    for(i=0;i<n;i++){
        p[i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    mat_mult();
}