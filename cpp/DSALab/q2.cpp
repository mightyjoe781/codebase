//--------------------------------------------------------------------
// File information.

// Name    :   Find the Nearest Hospital
// Purpose :   Compre Lab : Q2
// License :   MIT
// Revision:   210430
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;
#define pb push_back
#define fi first
#define se second

//--------------------------------------------------------------------
// Main functions

ll n,m;
vector<pair<ll, ll>> adj[100005];

int main() {

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        // Constructing the graph.
        for(ll i=0; i < m; i++){
            ll u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }

        ll b; cin >> b;
        set<pair<ll, ll>> s;
        for(ll i=0; i < b; i++){
            ll c; cin >> c; c--;
            s.insert({0, c});
        }

        ll wt[n] = {};
        for(ll i = 0; i < n; i++)
            wt[i] = 1e18;

        while(s.size()){
            auto cur = *(s.begin());
            s.erase(cur);
            if(wt[cur.se]<cur.fi)
                continue;
            wt[cur.se] = cur.fi;
            for(auto& e: adj[cur.se]){
                if(wt[e.fi]<=e.se+cur.fi)
                    continue;
                wt[e.fi] = e.se+cur.fi;
                s.insert({wt[e.fi], e.fi});
            }
        }
        for(int i = 0; i < n; i++)
            cout << wt[i] << " ";
        cout << endl;
        // Clearing the Adjacency Matrix
        for(int i = 0; i < n; i++) adj[i].clear();
    }
    return 0;
}
