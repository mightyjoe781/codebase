//--------------------------------------------------------------------
// File information.

// Name    :   13037 - Chocolate
// Purpose :   UHunt - Practice
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
// MACRO Utility-2

#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))

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
    int k = 1;
    while(t--){
        int l, r, s;
        // cin >> l >> r >> s;
        map<int,int> mp;
        int idx = 0;
        vector<int> imp(3,0);
        FOR(i,3) cin >> imp[i];
        // ----------------------------------
        // int m = 1e5;
        // ---------- Saving space----------
        int m = imp[0]+imp[1]+imp[2];
        vector<vector<int>> v(3,vector<int> (m,0));
        int tmp;
        // -----------------------------------------------------------
        // To understand this concise loop look below the flat version
        FOR(j,3){
            FOR(i,imp[j]){
                cin >> tmp;
                if(!mp.count(tmp)){
                    mp[tmp] = idx++;
                }
                v[j][mp[tmp]] = 1;
            }
        }
        cout << "Case #" << k++ << ":" << endl;
        FOR(i,3){
            int exc = 0, inc = 0;
            FOR(j,idx){
                if(v[i%3][j]&~v[(i+1)%3][j]&~v[(i+2)%3][j])
                    exc++;
                if(~v[i%3][j]&v[(i+1)%3][j]&v[(i+2)%3][j])
                    inc++;
            }
            cout << exc << " " << inc << endl;
        }

    }

    return 0;
}

// EOF----------------------------------------------------------------
// Earlier implementation probably help me understand how i establish-
// ed relationship among loops
        // FOR(i,l){
        //     cin >> tmp;
        //     if(!mp.count(tmp)){
        //         mp[tmp] = idx++;
        //     }
        //     v[0][mp[tmp]] = 1;
        // }
        // FOR(i,r){
        //     cin >> tmp;
        //     if(!mp.count(tmp)){
        //         mp[tmp] = idx++;
        //     }
        //     v[1][mp[tmp]] = 1;
        // }
        // FOR(i,s){
        //     cin >> tmp;
        //     if(!mp.count(tmp)){
        //         mp[tmp] = idx++;
        //     }
        //     v[2][mp[tmp]] = 1;
        // }
//--------------------------------------------------------------------