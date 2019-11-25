/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define edges 5
struct Edge{
    int src,dest,weight;
};

void put(int visited[],int s,int d,int *t){
    int temp1=1,temp2=1;
    for(int i=0;i<(*t);i++){
        if(s==visited[i]){
            temp1=temp1*0;
        }
        else if(d==visited[i]){
            temp2=temp2*0;
        }
    }
    if(temp2==1){
        visited[++(*t)]=d;
    }
    if(temp1==1){
        visited[++(*t)]=s;
    }
}

int check(struct Edge e,int visited[],int* t){
    int s=1,d=1;
    for(int i=0;i<=(*t);i++){
        if(e.src==visited[i]){
            s=s*0;
        }
        else if(e.dest==visited[i]){
            d=d*0;
        }
    }
    if(s==0 && d==0){
        return 0;
    }
    else{
        return 1;
    }
}

void print(int include[],struct Edge e[edges],int k){
    for(int i=0;i<=k;i++){
        printf("the dist from %d to %d is %d\n",e[include[i]].src,e[include[i]].dest,e[include[i]].weight);
    }
}

void kruskal(struct Edge e[edges],int ver){
    int i,j;
    int include[ver-1];
    int visited[ver-1];
    int k=-1;
    int t=-1;
    int q;
    struct Edge p;
    for(i=0;i<edges;i++){
        p=e[i];
        if(i!=0){
            j=i-1;
            while(e[j].weight>p.weight && j>=0){
                e[j+1]=e[j];
                j--;
            }
            e[j+1]=p;
        }
    }
    include[++k]=0;
    visited[++t]=e[0].src;
    visited[++t]=e[0].dest;
    for(i=1;i<edges;i++){
        q=0;
        q=check(e[i],visited,&t);
        if(q==1){
            include[++k]=i;
            put(visited,e[i].src,e[i].dest,&t);
        }
    }
    print(include,e,k);
}

void inserting(int s[],int val,int* k){
    int temp=0;
    for(int i=0;i<=(*k);i++){
        if(val==s[i]){
            temp=1;
            break;
        }
    }
    if(temp==0){
        s[++(*k)]=val;
    }
}

int main()
{
    int count,s[edges];
    int k=-1;
    int i;
    struct Edge e[edges];
    for(i=0;i<edges;i++){
        printf("\n\nedge %d \nfrom\n",i+1);
        scanf("%d",&e[i].src);
        printf("to \n");
        scanf("%d",&e[i].dest);
        printf("length \n");
        scanf("%d",&e[i].weight);
        if(i==0){
            s[++k]=e[i].src;
            //printf("inside 1 value of k is %d",k);
            s[++k]=e[i].dest;
            //printf("inside 2 value of k is %d",k);
        }
        else{
            inserting(s,e[i].src,&k);
            //printf("%d value of k is %d",i+1,k);
            inserting(s,e[i].dest,&k);
            //printf("%d value of k is %d",i+1,k);
        }
    }
    k=k+1;
    printf("number of vertices are %d\n",k);
    kruskal(e,k);
}
