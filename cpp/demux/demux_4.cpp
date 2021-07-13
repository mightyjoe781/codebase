//--------------------------------------------------------------------
// File information.

// Name    :   Sophia's Circle
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
const ll mod = 1e9+7;
//--------------------------------------------------------------------
// MACRO Utility-2

#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
//--------------------------------------------------------------------
// Main functions
#define N 0
#define E 1
#define S 2
#define W 3
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll m,n;
    cin >> m >> n;
    ll hc,vc;
    cin >> hc >> vc;
    vector<vector<int>> v(2,(vector<int>(n,0)));
    vector<int> hcx(hc),vcx(vc);
    FOR(i,hc) cin >> hcx[i];
    FOR(i,vc) cin >> vcx[i];
    // FOR(i,hc){
    cout << "test" << endl;
    //     FOR(j,vc){
    //         v[i][j] = max(v[i-1][j],v[i][j+1]);
    //     }
    // }


    return 0;
}
