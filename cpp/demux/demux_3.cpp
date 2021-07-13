//--------------------------------------------------------------------
// File information.

// Name    :   Critical Trade Bridge
// Purpose :   Contest
// License :   MIT
// Revision:   210523
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

//--------------------------------------------------------------------
// Macro Utility-1

#define pb push_back
//--------------------------------------------------------------------
// Main functions
ll dfs(vector<vector<ll>>& graph, ll i, vector<ll>& rank,
    vector<vector<ll>>& res, ll prev, ll n){
    rank[i] = prev+1;
    ll t = INT_MAX;

    for(const auto& nbr: graph[i]){
        // unvisited
        if(rank[nbr] == -1){
            ll k = dfs(graph,nbr,rank,res,prev+1,n);
            if(k > rank[i])
                res.push_back({i,nbr});
            t = min(t,k);
        } else if(rank[nbr] == n+1)
            continue;
        else if(rank[nbr]!= prev)
            t = min(t,rank[nbr]);
    }
    rank[i] = n+1;
    return t;
}

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n,e;
    cin >> n >> e;
    vector<vector<ll>> graph(n);
    ll t = e;
    ll a,b;
    // undirected graph construction
    while(t--){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    // Tarzan's Algo
    vector<vector<ll>> res;
    vector<ll> rank(n,-1);

    ll k =  dfs(graph,0,rank,res,0,n);

    ll m = res.size();
    cout << m << endl;
    sort(res.begin(),res.end());
    for(auto itr:res){
        for(auto x:itr)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

