//--------------------------------------------------------------------
// File information.

// Name    :   Perfect Song
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
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n; cin >> n;
    vector<int> freq(60,0);
    ll tmp;
    for(ll i = 0; i < n; i++){
        cin >> tmp;
        freq[tmp%60]++;
    }
    ll sum = freq[0] *(freq[0]-1)/2;
    for(ll i = 1; i <= 30 && i!=(60-i); i++)
        sum+= freq[i] * freq[60-i];
    sum += (freq[30]*(freq[30]-1)/2);
    cout << sum;

    return 0;
}
// Simple Question just make modulo pairs of size 60 rather than doing
// obvious O(n^2) solution
// this solution is O(k^2) which is O(1) in this case! k = 60

