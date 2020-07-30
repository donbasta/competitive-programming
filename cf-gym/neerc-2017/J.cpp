#pragma GCC optimization ("O2");
#pragma GCC optimization ("unroll-loops");
 
#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using plii = pair<ll, pii>;
 
plii mp3(const ll& a, const int& b, const int& c){
    return mp(a, mp(b, c));
}
 
const int N = 3e3 + 10;
const ll INF = 1e18;
 
int n, m, k;
vector<pil> adj[N];
 
ll dijkstra(){
    ll dp[n + 2];
    fill(dp, dp + n + 2, INF);
    dp[1] = 0;
    set<pli> setdah;
    setdah.insert(mp(dp[1], 1));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        ll dist = tp.fi;
        for (auto x : adj[node]){
            if (dp[x.fi] > dist + x.se){
                setdah.erase(mp(dp[x.fi], x.fi));
                dp[x.fi] = dist + x.se;
                setdah.insert(mp(dp[x.fi], x.fi));
            }
        }
    }
    return dp[n];
}
 
ll dp[N][N];
 
ll solve(ll mn){
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    set<plii> setdah;
    setdah.insert(mp3(dp[1][0], 1, 0));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        ll dist = tp.fi;
        int node = tp.se.fi;
        int kk = tp.se.se;
        for (auto x : adj[node]){
            int nk;
            ll tam = x.se;
            if (tam < mn){
                tam = 0;
                nk = kk;
            } else{
                nk = min(kk + 1, n);
            }
            if (dist + tam < dp[x.fi][nk]){
                setdah.erase(mp3(dp[x.fi][nk], x.fi, nk));
                dp[x.fi][nk] = dist + tam;
                setdah.insert(mp3(dp[x.fi][nk], x.fi, nk));
            }
        }
    }
    ll ret = INF;
    for (int i=k;i<=n;i++){
        ret = min(ret, dp[n][i]);
    }
    return ret;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    set<ll> sall;
    vector<ll> vall;
 
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
        sall.insert(w);
    }
    for (auto x : sall) vall.pb(x);
    ll ans = dijkstra();
    int l = 0, r = (int)vall.size() - 1;
    while (r - l > 3){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ll f1 = solve(vall[m1]);
        ll f2 = solve(vall[m2]);
        if (f2 >= INF){
            r = m2;
            continue;
        }
        ans = min(ans, f1);
        ans = min(ans, f2);
        if (f1 < f2){
            r = m2;
        } else l = m1;
    }
    for (ll i=l;i<=r;i++){
        ans = min(ans, solve(vall[i]));
    }
    cout << ans << el;
 
    return 0;
}