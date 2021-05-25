//--------------------------------------------------------------------
// File information.

// Name    :   10145 - Lock Manager
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

    string blank;
    int t; cin >> t;
    getline(cin,blank);
    while(t--){
        char c;
        // ignore list
        set<int> ignore;
        // xclusive list
        map<int,int> Xclusive;
        // shared list
        map<int,set<int>> share;
        while(cin >> c && c!='#'){
            int txn_id , item;
            cin >> txn_id >> item;

            if(ignore.count(txn_id)){
                cout << "IGNORED" << endl;
            } else if(c == 'S'){
                if(Xclusive[item] && Xclusive[item] != txn_id){
                    cout << "DENIED" << endl;
                    ignore.insert(txn_id);
                } else {
                    share[item].insert(txn_id);
                    cout << "GRANTED" << endl;
                }
            } else {
                if(Xclusive[item] && Xclusive[item] != txn_id){
                    cout << "DENIED" << endl;
                    ignore.insert(txn_id);
                } else if(share[item].count(txn_id) != share[item].size()){
                    cout << "DENIED" << endl;
                    ignore.insert(txn_id);
                } else {
                    Xclusive[item] = (txn_id);
                    cout << "GRANTED" << endl;
                }

            }
        }
        if(t)
            cout << endl;
        getline(cin,blank);
    }

    return 0;
}
