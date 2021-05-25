//--------------------------------------------------------------------
// File information.

// Name    :   12504 - Updating a Dictionary
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210524
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries and Macros

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;

//--------------------------------------------------------------------
// Main functions

void getMap(map<string,string>& mp){
       string line;
       cin >> line;
       line = line.substr(1,line.length()-2);
       istringstream istream1(line);

       string key,value;
       while(getline(istream1,key,':')){
            getline(istream1,value,',');
            mp.insert({key,value});
       }
}

bool printSet(set<string>& s,const char& d){
    if(!s.empty()){
        cout << d ;
        int sz = s.size(), cnt = 0;
        for(auto itr:s){
            cout << itr;
            if(cnt++ != sz-1)
                cout <<  ',';
        }
        cout << endl;
        return true;
    }
    return false;
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t >> ws;
    while(t--){
        map<string,string> m1,m2;
        map<string,string>::iterator it;

        getMap(m1);
        getMap(m2);

        set<string> add;
        set<string> minus;
        set<string> change;

        for(auto itr : m2){
            map<string,string>::iterator itm = m1.find(itr.first);
            if(itm == m1.end()){
                add.insert(itr.first);
            } else if(itm->second != itr.second){
                change.insert(itr.first);
                m1.erase(itr.first);
            } else {
                m1.erase(itr.first);
            }
        }
        for(auto it : m1)
            minus.insert(it.first);

        bool printed = false;
        bool a,b,c;
        a = printSet(add,'+');
        b = printSet(minus,'-');
        c = printSet(change,'*');
        printed = a || b || c;

        if(!printed)
            cout << "No changes" << endl;
        cout << endl;
    }

    return 0;
}
