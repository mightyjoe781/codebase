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

	int n;
	while(cin>>n){
		int arr[n];
		for(int i = 0 ;i < n ;i++)
			cin>>arr[i];
		int sum = 0;
		bool flag = true;
		for(int i = 1; i < n; i++){
			if(abs(arr[i] - arr[i-1] > n-1 || abs(arr[i] - arr[i-1]) <1 ))
				{ flag = false;}
			sum+= abs(arr[i] - arr[i-1]);
		}

		if(sum == (n*(n-1))/2 && flag) cout<< "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}

	return 0;
}