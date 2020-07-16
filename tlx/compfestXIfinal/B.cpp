// #include<bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using ld = long double;

// const int MX = 1e4;

// int cnt(int a, int m) {
//   return phi[m] * (a / m) + phi[a % m];
// }

// int cnt(int l, int r, int m) {
//   return cnt(r, m) - cnt(l - 1, m);
// }

// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0); cout.tie(0);

//   for(int i = 1; i <= MX; i++) {
//     phi.resize(i + 1);
//     phi[0] = 0;
//     for(int j = 1; j <= i; j++) {
//       phi[j] = phi[j - 1] + (__gcd(i, j) == 1);
//     }
//     //itung interval
//   }

  
//   return 0;
// }

#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int N = 1e4 + 10;
 
int tc;
int n;
 
vector<pii> v[N]; // vector of interval in row;
 
void init(){
    for (int i=0;i<N;i++){
        v[i].clear();
    }
}
 
void add_interval(int xa, int ya, int xb, int yb){
    for (int i=xa;i<=xb;i++){
        v[i].pb(mp(ya, yb));
    }
}
 
void merge_interval(){
    for (int i=0;i<N;i++){
        if (v[i].empty()) continue;
        vector<pii> temp;
        sort(v[i].begin(), v[i].end());
        for (auto x : v[i]){
            if (temp.empty()){
                temp.pb(x);
                continue;
            }
            if (temp.back().se + 1 >= x.fi){
                temp.back().se = max(temp.back().se, x.se);
            } else{
                temp.pb(x);
            }
        }
        v[i].swap(temp);
    }
}
 
void solve(){
    cin >> n;
    init();
    for (int i=1;i<=n;i++){
        int xa, xb, ya, yb;
        cin >> xa >> ya >> xb >> yb;
        add_interval(xa, ya, xb, yb);
    }
    merge_interval();
    // for (int i=0;i<N;i++){
    //     if (v[i].empty()) continue;
    //     cout << i << " => ";for (auto x : v[i]) cout << x.fi << " " << x.se << ", ";
    //     cout << el;
    // }
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> tc;
    while (tc--){
        solve();
    }
 
    return 0;
}