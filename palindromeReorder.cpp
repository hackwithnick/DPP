/*
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 <= n <= 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	string s;
	cin >> s;
	vector<ll> v(26,0);

	for(char c:s)
		v[c-'A']++;
	int count = 0;

	for(ll c:v){
		if(c&1)
			count++;
	}
	if(count > 1){
		cout << "NO SOLUTION\n";
		return 0;
	}
	else{
		string a,b,ans;
		char c='*';
		for(int i = 0; i < 26; i++){
			if(v[i] == 0)
				continue;

			if(v[i]&1){
				c = 'A' + i;
			}
			ll ct = v[i]/2;

			while(ct--){
				a += 'A' + i;
				b += 'A' + i;
			}
		}
		if(c != '*')
		a += c;
		reverse(b.begin(),b.end());
		ans = a+b;
		cout << ans << endl;
	}
	
}