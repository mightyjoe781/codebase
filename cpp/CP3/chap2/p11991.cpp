//--------------------------------------------------------------------
// File information.

// Name    :   11991 - Easy Problem for Rujia Liu ?
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

    int n, m, d, k;
    vector<vector<int>> v(1000000,(vector<int>()));
    while(cin >> n >> m){
        for(int i = 1; i <= n; i++){
            cin >> d;
            v[d].push_back(i);
        }
        FOR(i,m){
            cin >> k >> d;
            if(k-1 < v[d].size())
                cout << v[d][k-1] << endl;
            else
                cout << "0" << endl;
        }
    }
    return 0;
}

//--------------------------------------------------------------------
// Write Up
//
// If we store it in an array, then if we do the linear search for
// each queries then total complexity becomes O(n^2)

// Now we need to store information about how many times an
// integer is found.

// So Adjacency List is a quite good solution!
// We get O(1) queries now and we get total O(n) solution.
