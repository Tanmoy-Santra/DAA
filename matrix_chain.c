//matrix chain
#include<stdio.h>
#define INF 9999999;
int n,p[10],m[10][10],s[10][10];
int optimul_parence(int i,int j){
    
    if(i==j){        
        printf("A%d",i);
    }
    else{
        printf("(");
        optimul_parence(i,s[i][j]);
        optimul_parence(s[i][j]+1,j);
         printf(")");
    }
   
}
void print(int N){
    int i,j,k;
    printf("\nm table ;\n");
    for(i=1;i<=N;i++){
	  	for(k=1;k<=N;k++){
	  		if(i<=k)
	  		printf("%d\t",m[i][k]);
	  		else
	  		printf("\t");
		  }printf("\n");
	  }
	  printf("\ns table-\n");
	  for(i=1;i<=N;i++){
	  	for(k=1;k<=N;k++){
	  		if(i<=k)
	  		printf("%d\t",s[i][k]);
	  		else
	  		printf("\t");
		  }
		  printf("\n");
	  }
	  printf("\noptimal cost of matrix multiplication is : %d\n",m[1][N]);
}

void mat_mult(){
    int l,i,j,k,q;
    int N;
    N=n-1;
    printf("\nno. of matrices : %d",N);
    for ( i = 1; i <= N; i++)
    m[i][i] = 0;
    for(l=2;l<=N;l++){
        for(i=1;i<=N-l+1;i++){
            j=i+l-1;
            m[i][j]=INF;
            for(k=i;k<=j-1;k++){
                q = (m[i][k] + m[k+1][j] +(p[i-1]*p[k]*p[j]));
                printf("\nq=%d",q);
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
                
            }
        }
    }
    print(N);
    optimul_parence(1,N);
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

/*
10 20 50 1 100
<5 10 3 12 5 50 6>
*/