//--------------------------------------------------------------------
// File information.

// Name    :   11997 - K Smallest Sums
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210517
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//--------------------------------------------------------------------
// DEBUG Macros

#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define DBG cerr << "debug here" << endl;
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}

//--------------------------------------------------------------------
// Main functions
typedef pair<int,int> ii;
#define ff first
#define ss second

void merge(vector<int>& a,vector<int>& b,vector<int>& c, int k){
    // this function is the core of solution
    // just take min sum pairs from 2 vectors!


    priority_queue<ii, vector<ii>, greater<ii> > pq;

    for(int i = 0; i < k; ++i) pq.push({a[i]+b[0], 0});

    int idx = 0;

    while(!pq.empty()) {
        ii t = pq.top(); pq.pop();
        c[idx++] = t.ff;
        // this step is smartly choosing the pair!
        if(t.ss + 1 < k)
            pq.push({t.ff - b[t.ss] + b[t.ss+1], t.ss+1});

        if(idx == k) break;
    }
}

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k;
    while(cin >> k){
        vector<int> v1(k), v2(k);
        for(int i = 0; i < k; i++)
            cin >> v1[i];
        sort(v1.begin(), v1.end());

        for(int i = 1; i < k; i++){
            for(int j = 0; j < k; j++)
                cin >> v2[j];
            sort(v2.begin(),v2.end());
            merge(v1,v2,v1,k);
        }
        cout << v1[0];
        for(int i = 1; i < k; i++)
            cout <<  " " << v1[i];
        cout << endl;
    }


    return 0;
}
