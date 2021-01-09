#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define x first
#define y second

int n;
vector<vector<pair<int, int>>> pt;
const ld MX = 2e3;
const ld eps = 1e-1;

void run1 (vector<pair<int, int>> V) {
    vector<pair<ld, ld>> bat;
    sort(V.begin(), V.end());
    int sz = (int)V.size();
    bat.emplace_back(MX, -MX);
    bat.emplace_back(MX, -MX-1);
    bat.emplace_back(-MX, -MX-1);
    bat.emplace_back(-MX, -MX);
    bat.emplace_back(V[0].x + eps*2, -MX);
    for (int i = 0; i < sz; i++) {
        bat.emplace_back(V[i].x + eps*2, V[i].y - eps);
        bat.emplace_back(V[i].x - eps, V[i].y - eps);
        bat.emplace_back(V[i].x - eps, V[i].y + eps);
        if (i == sz - 1 || V[i].x != V[i + 1].x) {
            bat.emplace_back(V[i].x + eps*3, V[i].y + eps);
            bat.emplace_back(V[i].x + eps*3, -MX);
            if (i != sz - 1) bat.emplace_back(V[i + 1].x + eps*2, -MX);
        } else {
            bat.emplace_back(V[i].x + eps*2, V[i].y + eps);
        }
    }
    cout << (int)bat.size() << '\n';
    for (auto e : bat) {
        cout << e.x << ' ' << e.y << '\n';
    }
}

void run2 (vector<pair<int, int>> V) {
    vector<pair<ld, ld>> bat;
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    int sz = (int)V.size();
    bat.emplace_back(-MX, MX);
    bat.emplace_back(-MX, MX+1);
    bat.emplace_back(MX, MX+1);
    bat.emplace_back(MX, MX);
    bat.emplace_back(V[0].x - eps*2, MX);
    for (int i = 0; i < sz; i++) {
        bat.emplace_back(V[i].x - eps*2, V[i].y + eps);
        bat.emplace_back(V[i].x + eps, V[i].y + eps);
        bat.emplace_back(V[i].x + eps, V[i].y - eps);
        if (i == sz - 1 || V[i].x != V[i + 1].x) {
            bat.emplace_back(V[i].x - eps*3, V[i].y - eps);
            bat.emplace_back(V[i].x - eps*3, MX);
            if (i != sz - 1) bat.emplace_back(V[i + 1].x - eps*2, MX);
        } else {
            bat.emplace_back(V[i].x - eps*2, V[i].y - eps);
        }
    }
    cout << (int)bat.size() << '\n';
    for (auto e : bat) {
        cout << e.x << ' ' << e.y << '\n';
    }
}

void solve() {
    cin >> n;
    pt.resize(3);
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        pt[--c].emplace_back(x, y);
    }
    run1(pt[0]);
    run2(pt[1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(1);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}