//--------------------------------------------------------------------
// File information.

// Name    :   11629 - Ballot Evaluation
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210521
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
#include <map>
#include <cmath>  /* for std::round(double) */
using namespace std;

//--------------------------------------------------------------------
// Main functions
bool checkOp(string op){
    if(op == "<=" || op == "<" || op == ">=" || op == ">" || op == "=")
        return false;
    return true;
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int p,g; cin >> p >> g;
    map<string,double> m;
    for(int i = 0; i < p ; i++){
        string name; double tmp;
        cin >> name >> tmp;
        m[name] = tmp;
    }
    m["+"] = 0;

    for(int i = 0; i < g; i++){
        bool ans = false;
        string party;
        double lhs = 0;
        while(cin>>party && checkOp(party)){
            lhs += m[party];
        }

        string op;
        op = party;
        double rhs = 0;
        cin >> rhs;
        // Trick to fix the comparisons between double sum (lhs) comp
        // int (rhs).

        lhs = round(lhs*100);
        rhs = round(rhs*100);

        // Parse operator
        if(op == "<")
            ans = (lhs < rhs);
        if(op == ">")
            ans = (lhs > rhs);
        if(op == ">=")
            ans = (lhs >= rhs);
        if(op == "<=")
            ans = (lhs <= rhs);
        if(op == "=")
            ans = (abs(lhs-rhs) < 1e-9);

        cout << "Guess #" << i+1 << " was ";
        if(ans)
                cout << "correct." << endl;
        else
            cout << "incorrect." << endl;
    }

    return 0;
}
