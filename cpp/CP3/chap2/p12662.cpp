//--------------------------------------------------------------------
// File information.

// Name:      12662 - Good Teacher
// Purpose:   UHunt Practice
// License:   MIT
// Revision:  210323
// Author:    smk (Sudhanshu Mohan Kashyap)

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

    vector<int> positions;              //stores non '?' indices
    int n; cin >> n;
    string c[n];                        //original string

    for(int i = 0; i < n; i++){
        cin >> c[i];
        if(c[i]!="?")
            positions.push_back(i);
    }

    int q; cin >> q;
    while(q--){
        int pos; cin >> pos;
        pos--;


        int min_dist = INT_MAX;  // min distance from valid character
        int pos_ = 0;            // keeps  track of a valid character

        for(int i = 0; i < positions.size(); i++){
            if(abs(positions[i]-pos) < min_dist){
                min_dist = abs(positions[i] - pos);
                pos_     = positions[i];
            } else if (abs(positions[i] - pos) == min_dist){
                cout << "middle of " << c[pos_] << " and "
                << c[positions[i]] << endl;
                min_dist = -1;
            } else break;
        }

        // above loop calculates min distance from a valid chracter
        // and saves that chracter position
        // its kind of like a Brute Force approach
        // also -1 is for speacial case when the chracter is equidis-
        // -tant from both the chracters

        if(min_dist == -1)
            continue;

        if(pos_ - pos < 0) {
            for(int i = 0; i < min_dist; i++)
                cout << "right of ";
            cout << c[pos_] << endl;

        } else {
            for(int i = 0; i < min_dist; i++)
                cout << "left of ";
            cout << c[pos_] << endl;
        }

    }
    return 0;
}

//-------------------------------------------------------------------
// EOF
