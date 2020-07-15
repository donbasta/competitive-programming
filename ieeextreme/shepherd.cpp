#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define foru(i,a,b) for(int i = (int) a; i < (int) b; i++)
#define ford(i,a,b) for(int i = (int) a; i > (int) b; i--)
#define fors(i,n) for(int i = 0; i < n; i++)
#define fill(a,b) memset(a, (b), sizeof(a))
#define pii pair<int, int>
#define pll pair<long long, long long>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	int n,k,x,y;
	cin >> n >> k;
	vector<int> edge[n+5];
	for(int i=1; i<n; i++){
		cin >> x >> y;
		edge[x].pb(y); edge[y].pb(x);
	}
	if(k!=1) cout<<-1<<endl;
	else {
		int idx;
		for(int i=1; i<n; i++){
			if(edge[i].size()==1) {idx=i; break;}
		}
		cout << "flip " << idx << "\n";
		cout << "cut " << idx << " " << edge[idx][0] << "\n";
	}
	
}