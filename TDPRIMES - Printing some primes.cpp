#include<bits/stdc++.h>
#define MAX 100000000
#define Size 10000000
using namespace std;
bool status[MAX];
int prime[Size];
int sieve()
{
    int i,j,ind=0;
    prime[ind++]=2;
    for(i=3;i*i<=MAX;i+=2)
        if(!status[i])
            for(j=i*i;j<=MAX;j+=(i+i))
                status[j]=1;
    for(i=3;i<=MAX;i+=2)
        if(!status[i])
            prime[ind++]=i;
    return ind;
}
int main()
{
    int ind=sieve();
    for(int i=0;i<ind;i+=100)
        cout<<prime[i]<<endl;
    return 0;
 
}
 