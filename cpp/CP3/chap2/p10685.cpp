//--------------------------------------------------------------------
// File information.

// Name    :   10685 - Nature
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210525
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
// DisjointSet Class
class DisjointSet{
    public:
    // constructor.
    DisjointSet(int len){
        parent.resize(len);
        size.resize(len);
        for(int i = 0; i < len; i++){
            size[i] = 1;
            parent[i] = i;
        }

        num_components = len;
    }
    void union_(int x, int y){
        int r_x = find_(x);
        int r_y = find_(y);
        if(r_x != r_y){
            if(size[r_x] < size[r_y])
                swap(r_x,r_y);

            parent[r_y] = r_x;
            size[r_x] += size[r_y];
            num_components--;
        }
    }

    int find_(int x){
        while(x != parent[x])
            x = parent[x];
        return x;
    }
    int size_(int x){
        return size[find_(x)];
    }
    int getNumComponents(){
        return num_components;
    }

    private:
    vector<int> parent;
    vector<int> size;
    int num_components;
};

// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int c, r;
    while(cin >> c >> r && c){
        unordered_map<string,int> mp;
        DisjointSet dc(c);
        int cnt = 0;
        FOR(i,c){
            string str; cin >> str;
            mp[str] = cnt++;
        }
        FOR(i,r){
            string a, b;
            cin >> a >> b;
            dc.union_(mp[a],mp[b]);
        }
        int ans = INT_MIN;
        FOR(i,c){
            ans = max(ans,dc.size_(i));
        }
        cout << ans << endl;
        string blank;
        getline(cin,blank);
    }
    return 0;
}

