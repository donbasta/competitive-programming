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

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a%mod * a%mod)%mod;
        b >>= 1;
    }
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);     
	cout.tie(NULL);

	ll X,Y;
	int N;
	cin >> N;
	while(N--){
		cin >> X >> Y;

	}
	
}