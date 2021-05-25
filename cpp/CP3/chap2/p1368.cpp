//--------------------------------------------------------------------
// File information.

// Name    :   p1368 - DNA Consensus String
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210518
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Main functions
char getMostFreq(map<char,int>& mp, int& maxfreq){
    int max = INT_MIN;
    char ans;
    for(auto it:mp){
        if(it.second > max){
            max = it.second;
            ans = it.first;
        }
    }
    maxfreq = max;
    return ans;
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        string v[m];
        for(int i = 0; i < m; i++)
            cin >> v[i];

        string res = v[0];
        int cnt = 0;
        for(int i = 0; i < n; i++){
            map<char,int> mp;
            int maxfreq = 0;
            for(int j = 0; j < m; j++){
                mp[v[j][i]]++;
            }
            res[i] = getMostFreq(mp,maxfreq);
            cnt+= (m-maxfreq);
        }
        cout << res << endl;
        cout << cnt << endl;
        // calculating error
    }

    return 0;
}
//--------------------------------------------------------------------
// Write Up
//
// Question simple boils down to finding the words that has most freq-
// uent characters in a column j because that will produce minimum
// hamming distance.
// So question is just construct a word with each char word[i] equal
// to max frequent character in the column i of given m words and
// use that fact to calculate the hamming distance.

//--------------------------------------------------------------------
// EOF
