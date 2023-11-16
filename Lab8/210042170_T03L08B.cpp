#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


int dx[]={1,0,-1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};
char a[105][105];
int visited[105][105];

ll m,n;

bool isPossible(ll x, ll y)
{
    if(x >= 0 && x < m && y >= 0 && y < n && a[x][y] != '*' && visited[x][y]==0)
    {
        return true;
    }
    return false;
}

void dfs(ll x, ll y)
{ 
    visited[x][y]=1;

    for(ll i = 0; i < 8; i++)
    {
        ll mx = x + dx[i];
        ll ny = y + dy[i];
        if(isPossible(mx, ny))
        {
            dfs(mx,ny);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin>>m>>n;
    while(m!=0 && n!=0)
    {
        memset(visited,0,sizeof(visited));
        ll i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        ll distinct=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='@' && visited[i][j]==0)
                {
                    distinct++;
                    dfs(i,j);
                }
            }
        }
        cout<<distinct<<"\n";
        cin>>m>>n;
    }
    return 0;
}