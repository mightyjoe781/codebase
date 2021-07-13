//--------------------------------------------------------------------
// File information.

// Name    :   Unique Sequence
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

//--------------------------------------------------------------------
string getNext(string &curr){
    string next(8,' ');
    next[0] = next[7] = '0';
    for(int i = 1; i<7; i++)
        next[i] = curr[i-1] == curr[i+1] ? '1' : '0';
    return next;
}
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll k; cin >> k;
    unordered_map<string,int> m;
    vector<string> conf;
    string res;

    int i = 0,cycle_len;
    string init(8,' ');
    for(int i = 0; i < 8; i++)
        cin >> init[i];
    string curr = init, next;
    m[init] = 0;
    conf.push_back(init);

    for(i = 1; i <= k; i++){
        next = getNext(curr);
        // check cycle
        if(m.find(next) != m.end())
            break;
        // not a cycle
        m[next] = i;
        conf.push_back(next);
        curr = next;
    }
    if( i == k+1) // found config before cycle
        res = next;
    else {
        // logic for solving the cycle
        ll cycle_len = i - m[next];
        ll tail_len = m[next];

        ll j = (k-tail_len)%cycle_len;

        res = conf[tail_len + j];

    }
    // showing answer
    for(int i = 0; i < 8; i++)
    cout << res[i] -'0' << " ";
    return 0;
}
