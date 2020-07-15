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

char solve(int B, long long X){

	//find the number of char in the word
	ll cur=0, idx=1, power=B;
	while(cur + idx*power<=X){
		cur += idx*power;
		idx++;
		power*=B;
	}
	ll sisa, p;
	ll kata = (X-cur)/idx;
	ll urutan = (X-cur)%idx;
	if(kata==0) return ((char) B+97);
	if(!urutan) return ((char)((kata-1)%B)+97);
	kata--;
	vector<int> v;
	ll i=1;
	while(i<=idx){
		p = kata % B;
		v.pb(p);
		kata /= B;
		i++;
	}
	return (char) (v[idx-urutan]+97);

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	int T,B;
    long long X;
    cin >> T;
    while(T--){
        cin >> B >> X;
        if(B == 1) cout << 'a' << "\n";
        else cout << solve(B,X) << "\n";
    }  
	
}

