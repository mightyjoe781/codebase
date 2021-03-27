//--------------------------------------------------------------------
// File information.

// Name    :   12187 - Brothers
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210327
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;
//--------------------------------------------------------------------
// Constants

const int moves[4][2] = {{-1, 0}, {0, -1},{0, 1}, {1, 0}};

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, r, c, k;

    while(cin >> n >> r >> c >> k){
        if(n == 0) return 0;        //early termination
        vector< vector<int>> arr(r, vector<int> (c));
        //-------------------------------------------------
        // Attack array to keep track of next attack

        vector<int> att(n, 0);
        for(int i = 0; i < n-1; i++)
            att[i] = i+1;
        //--------------------------------------------------
        // Input

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> arr[i][j];


        while(k--){             // Actual Solution to the problem
                                // Used tmp to take action as a whole
            vector< vector<int> > tmp = arr;

            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){

                    for(int m = 0; m < 4; m++){
                        int x = i + moves[m][0];
                        int y = j + moves[m][1];
                        if(x > -1 && x < r && y > -1 && y < c &&
                            att[arr[i][j]] == arr[x][y])
                            tmp[x][y] = arr[i][j];
                    }
                }
            }
            arr = tmp;
        }

        //------------------------------------------------
        // Output

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cout << arr[i][j] << ((j == c-1)?"\n":" ");

    }

    return 0;
}

//--------------------------------------------------------------------
// Write up

// Do as the problem says, Implementation is something to focus on

//--------------------------------------------------------------------
// EOF