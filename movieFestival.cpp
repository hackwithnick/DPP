/*
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
Output
Print one integer: the maximum number of movies.
Constraints

1 <= n <= 2*10^5
1 <= a < b <= 10^9

Example
Input:
3
3 5
4 9
5 8

Output:
2
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> vp(n);

	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		vp[i] = {b,a};
	}
	sort(vp.begin(),vp.end());

	int ans = 1,last = vp[0].first;

	for(int i = 1; i < n; i++){
		if(last <= vp[i].second){
			ans++;
			last = vp[i].first;
		}
	}

	cout << ans << endl;
}