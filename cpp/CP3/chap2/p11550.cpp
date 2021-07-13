//--------------------------------------------------------------------
// File information.

// Name    :   11550 - Demanding Dillema
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210525
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries

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
        int n, m;
        cin >> n >> m;
        int mat[n][m];
        FOR(i,n) FOR(j,m) cin >> mat[i][j];

        bool flag = true;
        set<string> ss;
        FOR(i,m){
            int sum = 0;
            string s = "";
            FOR(j,n){
                sum+=mat[j][i];
                if(mat[j][i] != 0){
                    s+=('0'+j);
                }
            }
            // cout << s << endl;
            if(sum!=2 || s.length()!=2 || ss.find(s)!=ss.end()){
                flag = false;
                break;
            }
            ss.insert(s);
        }

        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
//--------------------------------------------------------------------
// EOF
// Write - Up
// Usually incidence matrices are used to represent directed graphs.
// and we have -1 for the incident, 1 - reflected and 0 for no edges
// and there is a simple property that sum of any column is zero.
// Incidence Matrices have a lot application in Circuit Solvers.

// But here in the problem its undirected graph so sum should be
// divisible by 2 in each column.

// Here we have to check 2 cases.
// 1. Sum in a column can be 0 or 2
// 2. No two different edges can join same two vertices. // multiple
//      edges are not allowed for two same vertices
//      graph is a "simple" graph
//
