/*
	1. Permute array A to B, so that A[i] != B[i] for all ∈ [0,n].
	A[11] : {1,5,3,1,2,1,3,3,2,3,1}
	B[11] :

	2. If it is not possible then print -1
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> findDerragements(vector<int>& a,int n){
	vector<pair<int,int>> vp(n);
	unordered_map<int,int> m;

	for(int i = 0; i < n; i++){
		vp[i] = {a[i],i};
		m[a[i]]++;
	}

	sort(vp.begin(),vp.end());

	int mxFreq = -1;
	for(auto it:m){
		if(mxFreq < it.second)
			mxFreq = it.second;
	}

	//If an element repeat itself more than n/2 times then it can't be possible to find any arrangement for it.
	if(mxFreq*2 > n)
		return {};

	vector<pair<int,int>> b(n);

	for(int i = 0; i < n; i++){
		b[(i+mxFreq)%n] = vp[i];
	}

	vector<int> ans(n);

	for(int i = 0; i < n; i++){
		ans[vp[i].second] = b[i].first;
	}

	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x:a){
		cin >> x;
	}

	vector<int> ans = findDerragements(a,n);

	if(ans.empty())
		cout << -1 << endl;
	else{
		for(int x:ans)
			cout << x << " ";
		cout << endl;
	}
}