//--------------------------------------------------------------------
// File information.

// Name    :   p902 - Password Search
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210519
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    while(cin >> n){
        int k = n;
        string s; cin >> s;
        map<string,int> m;
        int i = 0, max=INT_MIN;
        string ans;
        int sz = s.size();
        while(i < sz-k+1){
            string tmp = s.substr(i,k);
            m[tmp]++;
            if(m[tmp] > max){
                max = m[tmp];
                ans = tmp;
            }
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}
