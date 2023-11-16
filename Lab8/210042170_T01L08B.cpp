#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin>>x;
  for(int i=1;i<=x;i++){  

    vector<int>adjacency[25000];

    int visited[25000]={0};
    int type[25000]={0};

    set<int>nodes;

    int n;

    while(x--)
    {
        cin>>n;
        int a,b;
        cin>>a>>b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
        nodes.insert(a);
        nodes.insert(b);
    }

    ll ans=0;

    for(auto i:nodes)
    {
        if(!visited[i])
        {
            queue<int>q;
            q.push(i);
            visited[i]=1;
            type[i]=1;
            int count1=1,count2=0;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int v:adjacency[u])
                {
                    if(!visited[v])
                    {
                        visited[v]=1;
                        q.push(v);
                        if(type[u]==1) {type[v]=2; count2++;}
                        else {type[v]=1; count1++;}
                    }
                }
            }
            ans+=max(count1,count2);
        }
    }

    cout<<"Case "<<i<<": ";

    cout<<ans<<"\n";



  }




}    