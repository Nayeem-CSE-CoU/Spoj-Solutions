#include<bits/stdc++.h>
#define tc int t;cin>>t;while(t--)
#define vi vector<int>
#define vii vector<vi>
#define pb push_back
#define pii pair<int,int>
#define vpii vector<pii>
using namespace std;
bool optimum(vii graph,vpii soldier)
{
    bool res=true;
    vi distance(graph.size()),visited(graph.size());
    for(auto x:soldier)
    {
 
        int node=x.first;
        int power=x.second;
        if(visited[node]==true)
        {
            res=false;
            return res;
        }
        queue<int>q;
        q.push(node);
        visited[node]=node;
        distance[node]=0;
        if(power==0)
                continue;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto v:graph[temp])
            {
                if(visited[v] && visited[v]!=node)
                    return false;
                visited[v]=node;
                distance[v]=distance[temp]+1;
                if(distance[v]<power)
                    q.push(v);
            }
        }
 
 
    }
    for(int i=1;i<visited.size();i++)
        if(visited[i]==false)
            res=false;
   return res;
}
int main()
{
    tc
    {
        int node,edge,m;
        cin>>node>>edge>>m;
        vii graph(node+1);
        int i;
        for(i=1;i<=edge;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        vpii soldier(m);
 
        for(i=0;i<m;i++)
            cin>>soldier[i].first>>soldier[i].second;
 
        if(optimum(graph,soldier))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
 
 
    }
}
 