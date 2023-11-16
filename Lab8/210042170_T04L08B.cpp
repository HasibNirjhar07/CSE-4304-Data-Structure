#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int N=505;
const int INF=1e9+10;

vector<pair<int,int>>g[505];
vector<int>destination(N,INF);
vector<int>vis(N,0);

void Dijkstra(int source)
{
   set<pair<int,int>>st;
   st.insert({0,source});
    destination[source]=0;

    while(st.size()>0){
        auto node=*st.begin();
        int v=node.second;
        int v_dist=node.first;
        st.erase(st.begin());
        if(vis[v]) continue;

        vis[v]=1;
        for(auto child:g[v]){
            int child_v=child.first;
            int wt=child.second;

            if(destination[v]+wt <destination[child_v]){
                destination[child_v] = destination[v]+wt;
                st.insert({destination[child_v],child_v});
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y,weight;
        cin>>x>>y>>weight;
        g[x].push_back({y,weight});
        g[y].push_back({x,weight});

    }

    int u;
    cin>>u;
    Dijkstra(u);

    int z;
    cin>>z;

    while(z--){
        int v;
        cin>>v;
        if(destination[v]==INF){
            cout<<"NO PATH\n";
        }
        else{
            cout<<destination[v]<<"\n";
        }
    }


}