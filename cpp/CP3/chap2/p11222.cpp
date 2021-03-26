//--------------------------------------------------------------------
// File information.

// Name:      11222-Only I did it
// Purpose:   UHunt Practice
// License:   MIT
// Revision:  210325
// Author:    smk (Sudhanshu Mohan Kashyap)

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;
int n = 10001;
bool arr[10001][3] = {false};
//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int x, y, z;
    int t; cin >> t;
    int s = 0;
    while( s++ < t){
        //------------------------------------------------
        // Taking input using a multidimensional vector
        // Just for the sake of shorter code

        vector< vector<int>> v(3);
        for(int i = 0; i < 3; i++){
            int sz; cin >> sz;
            v[i].push_back(sz);
            for(int j = 0; j < sz; j++){
                int temp; cin >> temp;
                v[i].push_back(temp);
            }
        }

        bool arr[10001][3] = {false};

        //-------------------------------------------------
        // Boolean DATA processed (could have been avoided if data
        // was unique)

        for(int i = 0; i < 3; i++){
            for(int j = 1; j <= v[i][0]; j++){
                arr[v[i][j]][i] = true;
            }
        }

        //------------------------------------------------
        // counting unique elements

        int cnt[3] = {0,0,0};

        for(int j = 0; j < 3; j++){
            for(int i = 1; i < n; i++){
                if(arr[i][j%3] && (arr[i][j%3] & ~arr[i][(j+1)%3] &
                 ~arr[i][(j+2)%3]))
                    cnt[j]++;
            }
        }
        int cntMax = max(cnt[0], max(cnt[1],cnt[2]));

        cout << "Case #" << s << ":\n";

        //-----------------------------------------------
        // Smart printing using loops :)

        for(int j = 0; j < 3; j++){
            if(cnt[j] == cntMax){
                cout << (j+1) << " " << cnt[j];
                for(int i = 1; i < n; i++){
                    if(arr[i][j%3] && (arr[i][j%3] & ~arr[i][(j+1)%3]
                    & ~arr[i][(j+2)%3]))
                        cout <<" " << i;
                }
                cout << endl;
            }
        }
        v.clear();

    }


    return 0;
}
//--------------------------------------------------------------------
// Write UP
//          A B C   #problem
// Matrix : 1 0 1 -> 0
//        : 0 0 1 -> 1  // this is unique problem done
//        : 1 0 1 -> 2
//        : 1 0 1 -> 3
//        : 1 0 0 -> 4  // this is unique problem done
//        : 1 0 1 -> 5
// Basically Code is quite simple
// Its the implementation that took a lot of time to simplify code
// Coding using 1D array was making program quite large in size

//--------------------------------------------------------------------
// EOF