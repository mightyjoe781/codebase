//--------------------------------------------------------------------
// File information.

// Name    :   612 - DNA Sorting
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210411
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
#include <algorithm>
using namespace std;

//--------------------------------------------------------------------
// Main functions

struct dna
{
   int pos,inversion;
};

int getInversion(string s){
    int inv = 0;
    for(int i = 0; i < s.size(); i++)
        for(int j = i+1; j < s.size(); j++)
            if(s[i] > s[j]) inv++;
    return inv;
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s[100];
    int M; cin >> M;
    dna list[100];
    while(M--){
        int n,m; cin >> n >> m;

        for(int i = 0; i < m; i++) cin >> s[i];
        for(int i = 0; i < m; i++){
            list[i].pos = i;
            list[i].inversion = getInversion(s[i]);
        }

        sort(list,list+m,[](const dna& lhs, const dna& rhs){
            if(lhs.inversion != rhs.inversion) return lhs.inversion <
                rhs.inversion;
            return lhs.pos < rhs.pos;
        });

        for(int i = 0; i < m; i++)
            cout << s[list[i].pos] << endl;
        if(M) cout << endl;
    }

    return 0;
}
