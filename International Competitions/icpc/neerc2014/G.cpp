#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+69;

int n,k;
int pre[N];
int mn = 2e9+69;
deque<pair<int,int>> de;
pair<int,int> mx[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		pre[i] = pre[i-1] + x;
		mn = min(x, mn);
	}

	for(int i=1; i<=k; i++){
		while(!de.empty() && (de.back().first < pre[i] || (de.back().first == pre[i] && de.back().second < i)))
			de.pop_back();
		de.push_back(make_pair(pre[i],i));
	}
	mx[k] = de.front();

	for(int i=k+1; i<=n; i++){
		while(!de.empty() && (de.back().first < pre[i] || (de.back().first == pre[i] && de.back().second < i))){
			// cerr << i << " " << de.back().first << " " << de.back().second << " " << pre[i] << " ";
			de.pop_back();
		}
		de.push_back(make_pair(pre[i],i));
		if(!de.empty() && de.front() == make_pair(pre[i-k],i-k)){
			de.pop_front();
		}
	
		// deque<pair<int,int>> debug = de;
		// while(!debug.empty()){
		// 	cout << debug.front().first << " " << debug.front().second << " ";
		// 	debug.pop_front();
		// }
		// cout << "\n";
		mx[i] = de.front();
	}

	for(int i=1; i<=n; i++){
		cerr << i << " " << pre[i] << "\n";
	}

	for(int i=k; i<=n; i++){
		cerr << i << " " << mx[i].first << " " << mx[i].second << "\n";
	}

	int need = N;
	for(int i=1; i+k-1<=n; i++){
		int maks = mx[i+k-1].first, idx = mx[i+k-1].second;
		if(maks < 0){
			cout << 0 << "\n";
			for(int i=1; i<=n; i++){
				cout << pre[i] - pre[i-1] << " ";
			}
			return 0;
		}
		if(pre[idx-1] - mn * (idx-1) < 1 + maks)
			continue;
		if(1 + maks <= need){
			need = 1 + maks;
			cerr << need << " " << idx << "??\n";
		}
	}

	cout << need << "\n";
	for(int i=1; i<=n; i++){
		int dec = min(need, pre[i]-pre[i-1]-mn);
		cout << pre[i]-pre[i-1]-dec << " ";
		need -= dec;
	}

}