#include<stdio.h>
float m;
int n;
float x[10],p[10],w[10],r[10];
void print(){
    int  i;
    float cost =0.0;
    printf("\nsolution vector is :\n");
    for(i=1;i<=n;i++){
        printf(" %f",x[i]);
    }
    for(i=1;i<=n;i++){
        cost=cost+(p[i]*x[i]);
    }
    printf("\ncost %f",cost);
}
void ratio(){
    int i;
    for(i=1;i<=n;i++)
    r[i]=p[i]/w[i];
}
void sort(){
    int i,j;
    float t;
    for(i=1;i<=n-1;i++){
        for(j=1;j<=n-i;j++){
            if(r[j]<r[j+1]){
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
           
                t=w[j];
                w[j]=w[j+1];
                w[j+1]=t;
           
                t=r[j];
                r[j]=r[j+1];
                r[j+1]=t;
            }
        }
    }
}
void knapsack(){
    int i;
    float u;
    u=m;
    for(i=1;i<=n;i++){
        if(w[i]>u)
        break;
        x[i]=1.0;
        u=u-w[i];
    }
    if(i<=n){
        x[i]=u/w[i];
    }
}
int main(){
    int i;
    printf("\nrnter the mo of elements : ");
    scanf("%d",&n);
    printf("\nenter the size of knapsack : ");
    scanf("%f",&m);
    printf("\nenter the value of profit : ");
    for(i=1;i<=n;i++)
    scanf("%f",&p[i]);
    printf("\nenter the value of weight : ");
    for(i=1;i<=n;i++) 
    scanf("%f",&w[i]);
    for(i=1;i<=n;i++){
        x[i]=0.0;
    }
    ratio();
    sort();
    knapsack();
    print();
}