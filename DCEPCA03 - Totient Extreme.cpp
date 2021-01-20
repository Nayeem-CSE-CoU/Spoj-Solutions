#include<bits/stdc++.h>
using namespace std;
int phi[1000006];
void eTotient(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        phi[i]=i;
    for(i=2;i<=n;i++)
    {
        if(phi[i]==i)
        for(j=i;j<=n;j+=i)
            phi[j]=(phi[j]/i)*(i-1);
        phi[i]+=phi[i-1];
    }
 
}
int main()
{
    eTotient(10005);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
       cout<<1LL*phi[n]*phi[n]<<endl;
 
    }
    return 0;
}