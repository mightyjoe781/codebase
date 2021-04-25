//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
#include <cstdio>
#include <vector>
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
    int x;
    basic_istream<int> ss(stdin);
    while(getline(ss,x))
        cout << x << " ";
    return 0;

}
