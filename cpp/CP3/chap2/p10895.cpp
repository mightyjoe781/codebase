//--------------------------------------------------------------------
// File information.

// Name    :   10895 - Matrix Transpose
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210525
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries and Macros

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int m, n;
    while(cin >> m >> n){
        vector<vector<pair<int,int>>> t(n,(vector<pair<int,int>>()));
        FOR(i,m){
            int k;
            cin >> k;
            vector<int> idx(k), val(k);
            FOR(j,k) cin >> idx[j];
            FOR(j,k) cin >> val[j];
            FOR(j,k)
                t[idx[j]-1].push_back({i+1,val[j]});
        }

        cout << n << " " << m << endl;
        for(auto v : t){
            cout << v.size();
            FOR(i,(int)v.size())
                cout << " " << v[i].fi;
            cout << endl;
            FOR(i,(int)v.size()){
                if(i > 0) cout << " ";
                cout << v[i].se;
            }
            cout << endl;
        }
    }

    return 0;
}

