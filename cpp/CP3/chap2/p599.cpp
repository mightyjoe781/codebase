//--------------------------------------------------------------------
// File information.

// Name    :   p599 - The Forest for the Trees
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210524
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

    int t; cin >> t;
    while(t--){
        vector<int> edge_count(26,0);
        int v = 0, e = 0, acorns = 0;
        string s, vertices;
        while(cin>>s){
            if(s[0] == '*')
                break;
            edge_count[s[1]-'A']++;
            edge_count[s[3]-'A']++;
            e++;
        }
        cin >> vertices;
        for(auto c:vertices){
            if(c!=',')
            {
                if(edge_count[c-'A'] == 0)
                    acorns++;
                v++;
            }
        }
    printf("There are %d tree(s) and %d acorn(s).\n", v - e - acorns, acorns);
    }

    return 0;

}
// -------------------------------------------------------------------
// This problem is quite interesting considering how simple above
// solution is.
// Earlier i tried dfs and counting the connected components but that
// was stupid approach and was not required.
//
// Write Up
//
// We use union find algorithm to find acorns.To find acrons find
// vertices such that parent(v) = v and parent(u)!=v for all
// vertices other than v.
//
// Accorns doesn't have any incoming or outgoing edges.
//
// Total number of connected components in acyclic graph(given)=V-E
//
// Trees = (V-E) - acorns.
