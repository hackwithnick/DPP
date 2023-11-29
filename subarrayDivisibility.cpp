/*
Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.
Input
The first input line has an integer n: the size of the array.
The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints

1 <= n <= 2*10^5
-10^9 <= a[i] <= 10^9

Example
Input:
5
3 1 2 7 4

Output:
1
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
	int n;
	cin >> n;
	vector<int> a(n);

	for(int &x:a)
		cin >> x;

	unordered_map<int,int> m;
	ll sum = 0,ans = 0;
	m[0]++;
	
	for(int i = 0; i < n; i++){
		sum += a[i];

		int rem = sum%n;
		if(rem < 0)
			rem += n;

		if(m.count(rem))
			ans += m[rem];

		m[rem]++;
	}

	cout << ans << endl;
}