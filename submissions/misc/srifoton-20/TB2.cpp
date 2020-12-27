#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int N = 110;
 
string win[2] = {"Dora", "Boots"};
 
int q;
int n;
int ar[N];
 
void solve(){
    cin >> n;
    int tot = 0, mx = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tot += ar[i];
        mx = max(mx, ar[i]);
    }
    if (n == 1) {
        cout << win[0] << el;
        return;
    }
    if (mx > tot - mx){
        cout << win[0] << el;
        return;
    }
    if (tot & 1) cout << win[0] << el;
    else cout << win[1] << el;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // cin >> q;
    q = 1;
    while (q--){
        solve();
    }
 
    return 0;
}