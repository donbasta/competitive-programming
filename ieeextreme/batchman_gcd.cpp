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
const int MAXN = 100005;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	int n,k,maks=0;
	cin >> n >> k;
	int a[MAXN+5];
	bitset<100005> m[MAXN+5];

	for(int i=0; i<n; i++){
		cin >> a[i]; maks = max(maks, a[i]);
		for(int j=1; j*j<=a[i]; j++){
			if(a[i]%j==0){
				m[j].set(i);
				if(j != n/j) m[n/j].set(i);
			}
		}
	}

	int ans=0;

	set< bitset<100005> > s;


	bitset<100005> nil;
	for(int i=maks; i>1; i--){
		auto j = s.find(m[i]);
		if(j != s.end()) continue;
		ans++; s.insert(m[i]);
	}

	cout<<ans;

}