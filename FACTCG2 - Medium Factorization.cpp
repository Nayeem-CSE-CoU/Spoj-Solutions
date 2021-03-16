#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1.0)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t;cin>>t;while(t--)
#define endl "\n"
using namespace std;
bool status[100000005];
vector<int> prime;
void sieve(int n)
{
    for(int i=3;i*i<=n;i+=2)
        if(!status[i])
            for(int j=i*i;j<=n;j+=(i+i))
                status[j]=1;
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
        if(!status[i])
            prime.push_back(i);

}
void factor(int n)
{
	int i=0;
	cout<<1;
	for(i=0;prime[i]*prime[i]<=n;i++)
		while(n%prime[i]==0)
		{
			cout<<" x "<<prime[i];
			n/=prime[i];
		}
        if(n>1)
            cout<<" x "<<n;
	cout<<endl;

}
int main()
{
    fast; 
    sieve(100000);
    int n;
    while(cin>>n)
    {
        
        factor(n);
    }
}