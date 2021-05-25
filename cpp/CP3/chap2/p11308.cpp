//--------------------------------------------------------------------
// File information.

// Name    :   11308 - Bankrupt Baker
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210524
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries and Macros

#include <bits/stdc++.h>
#include <cstdio>
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

    // ios_base::sync_with_stdio(false);   //Fast input and output
    // cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--){
        string title;
        getline(cin >> ws, title);
        transform(title.begin(),title.end(),title.begin(),::toupper);
        cout << title << endl;
        ll b;
        int m, n; cin >> m >> n >> b;
        map<string,int> ing;
        string str_tmp; int c;
        FOR(i,m){
            cin >> str_tmp >> c;
            ing[str_tmp] = c;
        }
        // n recipe -- store sorted order
        set<pair<int,string>> s;
        FOR(i,n){
            ll cost = 0;
            string dish;
            getline(cin >> ws,dish);
            int k; cin >> k;
            FOR(j,k){
                string ingrid; cin >> ingrid;
                int x; cin >> x;
                cost += (ing[ingrid]*x);
            }
            if(cost <= b){
                s.insert({cost,dish});
            }
        }
        if(s.empty()){
            cout << "Too expensive!"<< endl;
        } else {
            for(auto itr:s){
                cout << itr.second << endl;
            }
        }
        cout << endl;

    }

    return 0;
}
//--------------------------------------------------------------------
// EOF
//
// Care to be taken while using getline along with >> operator along
// with
// getline causes issues related to reading whitespaces
// Good Practice is to getline everywhere
// but trick is to extract all white spaces before using getline
// Instead of this getline(cin,str) do this getline(cin >> ws, str)
//