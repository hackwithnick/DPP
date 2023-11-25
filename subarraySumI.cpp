/*
Given an array of n positive integers, your task is to count the number of subarrays having sum x.
Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.

Constraints: 1 <= n <= 2*10^5, 1 <= x,a[i] <= 1e9

Example
Input:
5 7
2 4 1 2 7

Output:
3
*/
#include<bits/stdc++.h>
using namespace std;

int findSubarraySum(vector<int>&a, int n,int x){
	unordered_map<long long,long long> m;
	int ans = 0;
	long long sum = 0;

	for(int i = 0; i < n; i++){
		sum += a[i];

		if(sum == x)
			ans++;

		if(m.count(sum-x))
			ans++;

		m[sum]++;
	}
	return ans;
}

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> a(n);

	for(int &x:a)
		cin >> x;

	cout << findSubarraySum(a,n,x) << endl;
}