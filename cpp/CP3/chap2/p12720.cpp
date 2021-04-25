//--------------------------------------------------------------------
// File information.

// Name    :   12720 - Algorithm of Phil
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210417
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries
#include <iostream>
using namespace std;
long long mod = 1e9+7;
//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    int cases = 0;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        int ret = 0;
        int p,q,r;
        q = n/2; p = q-1;
        for(int i = 0, j= n&1; i < n; i++, j=!j){
            if(j){ // odd size
                if(n-q > p) // clip the middle which ever part is
                    //large
                    r = (s[q++] - '0');
                else
                    r = (s[p--] - '0');
            } else { // even size
                if(s[p] > s[q]) // greater bit inserted in r
                    r = (s[p--] - '0');
                else
                    r = (s[q++] - '0');
            }
            ret = (ret << 1) + r;
            if(ret >= mod) ret %= mod;
        }
        cout << "Case #" << ++cases << ": " << ret << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// Write Up
//
// Do as indicated : for convesion to get decimal number directly
// maintain a decimal number , act of appending bits at the end by
// left shift is equivalent to product by 2 and adding that bit.
//

//--------------------------------------------------------------------
// EOF