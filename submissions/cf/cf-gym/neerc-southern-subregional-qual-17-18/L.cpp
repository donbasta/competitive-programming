#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int N = 1e3 + 10;
 
int n;
struct Sub{
    int p;
    set<int> nodes;
    Sub(){}
    Sub(int p, const vector<int>& v) : p(p) {
        for (auto x : v){
            nodes.insert(x);
        }
    }
};
 
vector<int> get_parse(const string& s){
    int n = stoi(s);
    int id = 0;
    while (s[id] != ':') id++;
    vector<int> ret;
    for (int i=1;i<=n;i++){
        id++;
        string temp;
        while (s[id] != ','){
            temp.pb(s[id]);
            id++;
        }
        ret.pb(stoi(temp));
    }
    return ret;
}
 
int par[N], sz[N];
void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
bool make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return 1;
}
 
vector<Sub> vec, rvec;
set<pii> setdah;
bool skip[N];
vector<pii> edges;
vector<int> adj[N];
 
set<int> sbt;
void bikin(int node, int p){
    sbt.insert(node);
    for (auto x : adj[node]){
        if (x == p) continue;
        bikin(x, node);
    }
}
 
bool check(int p, const set<int>& nodes){
    int ch = -1;
    for (auto x : adj[p]){
        if (nodes.find(x) != nodes.end()){
            ch = x;
            break;
        }
    }
    if (ch == -1) return 0;
    sbt.clear();
    bikin(ch, p);
    if (nodes.size() != sbt.size()) return 0;
    auto it1 = nodes.begin();
    auto it2 = sbt.begin();
    while (it1 != nodes.end()){
        if (*it1 != *it2) return 0;
        it1++;
        it2++;
    }
    return 1;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
    init();
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        s.pb('-');
        string stree;
        for (auto x : s){
            if (x == '-'){
                stree.pb(',');
                vector<int> temp = get_parse(stree);
                vec.emplace_back(i, temp);
                rvec.emplace_back(i, temp);
                stree.clear();
                continue;
            }
            stree.pb(x);
        }
    }
    // cout << "TES" << el;
    int len = vec.size();
    for (int i=1;i<n;i++){
        setdah.clear();
        for (int j=0;j<len;j++){
            if (!vec[j].nodes.empty() && !skip[j]) setdah.insert(mp((int)vec[j].nodes.size(), j));
        }
 
        if (setdah.empty()) break;
        auto tp = *setdah.begin();
        int id = tp.se;
        int a = vec[id].p;
        int b = *vec[id].nodes.begin();
        edges.emplace_back(a, b);
        if (!make(a, b)){
            cout << -1 << el;
            return 0;
        }
        skip[b] = 1;
        for (int i=0;i<len;i++){
            vec[i].nodes.erase(b);
        }
    }
    if (edges.size() != n - 1){
        cout << -1 << el;
    } else{
        bool ok = 1;
        for (auto x : edges){
            adj[x.fi].pb(x.se);
            adj[x.se].pb(x.fi);
        }
        for (int i=0;i<len;i++){
            if (!check(rvec[i].p, rvec[i].nodes)){
                ok = 0;
                break;
            }
        }
        if (!ok){
            cout << -1 << el;
            return 0;
        }
        cout << edges.size() << el;
        for (auto x : edges){
            cout << x.fi << " " << x.se << el;
        }
    }
 
    return 0;
}