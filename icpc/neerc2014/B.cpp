#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+69;

int cnt[N];
int c[N];
int n,k,kosong;
pair<int,int> ans[N];
vector<int> ve[N], lol;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> k >> n;
	int d = k/n;
	for(int i=1; i<=k; i++){
		int x;
		cin >> x;
		if(x > 0){
			cnt[x]++;
			ve[x].push_back(i);
		}
		else{
			ve[1].push_back(i);
		}
	}

	for(int i=1; i<=n; i++){
		if(cnt[i] > 0 && cnt[])
	}


	
}