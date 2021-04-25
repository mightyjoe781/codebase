#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); //fast input and output
    cin.tie(NULL); //flush output
    //online judge config
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    while(getline(cin,s)){
        int arr[256] = {0};
        for(int i = 0; i<s.size(); i++)
            if((s[i] >= 'a' && s[i] <= 'z')|| (s[i]>='A' && s[i] <= 'Z'))
                arr[s[i]]++;

        int max_f = -1;
        for(int i = 0; i< 256 ; i++)
            max_f = max(max_f,arr[i]);
        for(int i = 0; i< 256 ; i++)
            if(arr[i] == max_f)
                cout<<char(i);
        cout << " " << max_f << endl;
    }

    return 0;
}