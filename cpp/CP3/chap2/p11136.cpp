//--------------------------------------------------------------------
// File information.

// Name    :   11136 - Hoax or What
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210524
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

    int numDays;
    while(cin >> numDays , numDays){
        multiset<int> numbers;
        ll cost = 0;
        while(numDays--){
            int k;
            cin >> k;
            while(k--){
                int t;
                cin >> t;
                numbers.insert(t);
            }
            multiset<int>::iterator lo = numbers.begin();
            multiset<int>::iterator hi = --numbers.end();
            cost += *hi - *lo;
            numbers.erase(lo);numbers.erase(hi);
        }
        cout << cost << endl;
    }

    return 0;
}
