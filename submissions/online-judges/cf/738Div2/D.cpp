#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

int p1[N + 5], p2[N + 5];

int s1[N + 5], s2[N + 5];

void init () {
    for(int i = 1; i <= N; i++){
        p1[i] = i, s1[i] = 1;
        p2[i] = i, s2[i] = 1;
    }
}

int fpar1(int a) {
    return (a == p1[a] ? a : p1[a] = fpar1(p1[a]));
}

int fpar2(int a) {
    return (a == p2[a] ? a : p2[a] = fpar2(p2[a]));
}

void merge1(int a, int b){
    a = fpar1(a);
    b = fpar1(b);
    if (a != b) {
        if(s1[a] < s1[b]) {
            swap(a,b);
        }
        p1[b] = a;
        s1[a] += s1[b];
    }
}

void merge2(int a, int b){
    a = fpar2(a);
    b = fpar2(b);
    if (a != b) {
        if(s2[a] < s2[b]) {
            swap(a,b);
        }
        p2[b] = a;
        s2[a] += s2[b];
    }
}

int n, m1, m2;

void solve() {
    init();

    cin >> n >> m1 >> m2;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        merge1(u, v);
    }
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        merge2(u, v);
    }
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((fpar1(i) != fpar1(j)) && (fpar2(i) != fpar2(j))) {
                edges.emplace_back(i, j);
                merge1(i, j);
                merge2(i, j);
            }
        }
    }
    cout << edges.size() << '\n';
    for (auto t : edges) {
        cout << t.first << ' ' << t.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}