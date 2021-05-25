//--------------------------------------------------------------------
// File information.

// Name    :   978 - Lemmings Battle!
// Purpose :   Uhunt - Practice
// License :   MIT
// Revision:   210522
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
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
//--------------------------------------------------------------------
// MACRO Utility-2

#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}
//--------------------------------------------------------------------
// DEBUG Macros

#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define DBG cerr << "debug here" << endl;
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t;
    while(t--){
        ll b,sg,sb,gs,bs;
        cin >> b >> sg >> sb;
        int tmp;
        priority_queue<int,vector<int>> green,blue;
        vi gv,bv;
        while(sg--){
            cin >> tmp;
            green.push(tmp);
        }
        while(sb--){
            cin >> tmp;
            blue.push(tmp);
        }
        //
        while(!green.empty() && !blue.empty()){
            gs = green.size();
            bs = blue.size();
            tmp = min(b,min(gs,bs));
            // Battle Simulation
            FOR(i,tmp){
                gs = green.top(); green.pop();
                bs = blue.top(); blue.pop();
                if(gs > bs){
                    gv.pb(gs-bs);
                } else if(gs < bs){
                    bv.pb(bs-gs);
                }
            }
            // Returning Soldier
            FOR(i,gv.size())
                green.push(gv[i]);
            FOR(i,bv.size())
                blue.push(bv[i]);
            gv.clear(); bv.clear();
        }
        if(green.empty() && blue.empty()){
            cout << "green and blue died" << endl;
        } else if(blue.empty()){
            cout << "green wins" << endl;
            while(!green.empty()){
                cout << green.top() << endl;
                green.pop();
            }
        } else {
            cout << "blue wins" << endl;
            while(!blue.empty()){
                cout << blue.top() << endl;
                blue.pop();
            }
        }
        if(t)
            cout << endl;
    }

    return 0;
}
