//--------------------------------------------------------------------
// File information.

// Name    :   11321 - Sort! Sort! Sort!
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210404
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    while(cin >> n >> m && (n && m)){
        std::vector<ll> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end(), [](const ll i, const ll j){

            if(i%m != j%m)
                return i%m < j%m;
            if(i & 1) // i is odd
            {
                if(j & 1)
                    return i > j;
                return true;
            }
            if(j & 1)
            {
                return false;
            }
            return i < j;
        });
        cout << n << " " << m << endl;
        for(auto x:v)
            cout << x << endl;
    }
        cout << 0 << " " << 0 << endl;

    return 0;
}
