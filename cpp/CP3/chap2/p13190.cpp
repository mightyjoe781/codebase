//--------------------------------------------------------------------
// File information.

// Name    :   13190 - Rockabye Tobby
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210518
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Main functions
typedef pair<int,int> pii;
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        priority_queue<pii, vector<pii>, greater<pii>> minq;
        unordered_map<int,int> rank;
        unordered_map<int,string> m;
        int r = 0;
        for(int i = 0; i < n; i++){
            string s; int f;
            cin >> s >> f;
            m[i] = s;
            rank[i] = f;
            minq.push({f,i});
        }
        while(k--){
            pii x = minq.top(); minq.pop();
            minq.push({x.first+rank[x.second],x.second});
            cout << x.first << " " << m[x.second] << endl;
        }
    }

    return 0;
}

