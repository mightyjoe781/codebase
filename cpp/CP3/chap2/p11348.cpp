//--------------------------------------------------------------------
// File information.

// Name    :   11348 - Exhibition
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210521
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

    int K; cin >> K;
    for(int k = 1; k <=  K; k++){

        int n; cin >> n;
        map< int, set<int>> stamps;
        // key : type of stamp
        // value : friends who owns the stamps
        for(int i = 0; i < n; i++){
            int m; cin >> m;
            while(m--){
                int a; cin >> a;
                pair< map<int,set<int>>::iterator, bool> res = stamps.insert(
                    {a,set<int>()});
                (res.first) -> second.insert(i);
            }
        }
        int ctr = 0;
        vector<int> unique_stamps(n,0);
        for(auto it : stamps){
            if(it.second.size() == 1){
                ctr++;
                unique_stamps[*it.second.begin()]++;
            }
        }
        printf("Case %d:", k);
        if (ctr)
          for (size_t i = 0; i < n; i++)
            printf(" %.6lf%%", (static_cast<double>(unique_stamps[i]) * 100.0) /
              static_cast<double>(ctr));
        putchar('\n');
    }

    return 0;
}
