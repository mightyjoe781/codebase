#include <bits/stdc++.h>
using namespace std;

int main(){

    //online judge config
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    int cnt = 1;
    while(t--){
        set<string> s;
        int m, n;
        cin >> m >> n;
        string blank;
        getline(cin,blank);
        string x[m],y[n];
        for(int i = 0; i < m; i++)
            getline(cin,x[i]);

        for(int i = 0; i < n; i++)
            getline(cin,y[i]);

        for(int i = 0; i < m ; i++)
            for(int j = 0; j < n; j++)
                s.insert(x[i]+y[j]);
        cout << "Case " << cnt++ << ": " << s.size() << endl;
    }
    return 0;
}