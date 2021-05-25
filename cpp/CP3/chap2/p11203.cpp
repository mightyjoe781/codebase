//--------------------------------------------------------------------
// File information.

// Name    :   11203 - Can you decide for ME
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210518
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
#include <string>
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

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int x = 0, y = 0, z = 0;
        int i = 0;
        int n = s.size();
        while(s[i] != 'M' && i < n)
            if(s[i++] == '?' ) x++;

        while(s[i] != 'E' && i < n)
            if(s[i++] == '?' ) y++;
        while(i < n)
            if(s[i++] == '?' )
                z++;
        if(x+y == z && x > 0 && y >0 && x+y+z == n-2 )
            cout << "theorem" << endl;
        else cout << "no-theorem" << endl;
    }

    return 0;
}
//--------------------------------------------------------------------
// EOF

// Well As steven says problem statement is quite convoluted.
// Think of M as '+' sign and E as '=' sign then problem reduces to
// just counting the x + y = z where x represents number of '?'
// before M and y is number of '?' in between M and E and then z
// represents    number of '?' after '=' sign.

// So basically we need to check x > 0 and y > 0 and x+y == z along
// with usuall constraints like no character other than '?'.

//--------------------------------------------------------------------