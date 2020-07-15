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

	double x;
	double maks = 0, ans=0;

	while(cin>>x){
		if(x>maks) maks=x;
		ans += x;
	}
	ans -= maks;
	if(ans < maks) cout << "MUSTAHIL" << "\n";
	else cout << "MUNGKIN" << "\n";
	
}