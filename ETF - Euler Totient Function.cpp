#include<bits/stdc++.h>
using namespace std;
int phi[1000006],mark[1000006];
void eTotient(int n)
{
    int i,j;
    for(i=0; i<=n; i++)
        phi[i]=i;
    //phi[1]=1;
    mark[1]=1;
    for(i=2; i<=n; i++)
        if(!mark[i])
        {
            for(j=i;j<=n;j+=i)
            {
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
}
int main()
{
	eTotient(1000000);
	int t;
	cin>>t;
	while(t--)
	{
    int n;
    cin>>n;
    //eTotient(n);
    cout<<phi[n]<<endl;
	}
 
    return 0;
}