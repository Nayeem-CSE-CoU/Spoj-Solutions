#include<bits/stdc++.h>
#define MAX 1000005
using namespace std;
bool status[MAX];
int prime[MAX];
void sieve(int n)
{
    int i,j,ind=0;
    for(i=3;i*i<n;i+=2)
        if(status[i]==0)
        for(j=i*i;j<=n;j+=i+i)
        status[j]=1;
    prime[ind++]=2;
    //cout<<prime[0]<<" ";
    for(i=3;i<=n;i+=2)
        if(status[i]==0)
           /* cout<<i<<" ",*/prime[ind++]=i;
 
}
void solve(int n)
{
    int i,ans=0;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        int pow=0;
 
        while(n%prime[i]==0)
            n/=prime[i],pow++;
        ans=max(ans,pow);
    }
    if(!ans)
        ans++;
    cout<<ans<<endl;
 
}
int main()
{
    
    sieve(MAX);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}