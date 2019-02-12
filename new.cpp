#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define Maxn 100007
using namespace std;

vector <pair<ll,ll> > g[Maxn];
ll dis[Maxn];
ll vis[Maxn];
ll par[Maxn];

int main(){
    ll n,x,m,i;
    cin>>n>>m;
    for(i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].pb(mp(y,z));
        g[y].pb(mp(x,z));
    }
    memset(dis,10,sizeof(dis));
    deque <ll> q;
    q.push_back(1);
    vis[1]=1;
    dis[1]=0;
    while(!q.empty()){
        ll node=q.front();
        cout<<node<<" ";
        q.pop_front();
        for(auto x : g[node]){
               // vis[x.first]=1;
                if((dis[x.first]) > (dis[node]+x.second)){
                    dis[x.first]=dis[node]+x.second;
                    
                    if(x.second==0){
                        q.push_front(x.first);
                    }
                    else{
                        q.push_back(x.first);
                    }
                }
               // par[x.first]=node;
        }
    }
    cout<<endl;
    for(i=1;i<=n;i++){
        cout<<i<<" "<<dis[i]<<endl;
    }
    
}
