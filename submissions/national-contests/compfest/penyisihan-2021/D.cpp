#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int x, y, n;

void answer(int p, int q) {
    cout << "! " << p << ' ' << q << endl;
    exit(0);
}

pair<int, char> ask(int p, int q) {
    int ret;
    char cc;
    cout << "? " << p << ' ' << q << endl;
    cin >> ret >> cc;
    return make_pair(ret, cc);
}

void update(int& ax, int& ay, char c) {
    if (c == 'S') return;
    else if (c == 'U') {
        ay = min(ay + 1, y);
    } else if (c == 'D') {
        ay = max(ay - 1, 0);
    } else if (c == 'L') {
        ax = max(ax - 1, 0);
    } else if (c == 'R') {
        ax = min(ax + 1, x);
    }
}

void solve() {
    cin >> x >> y >> n;
    n = 20;
    int ax = 0, ay = 0, bx = x, by = y;
    pair<int, int> gotcha;
    bool ketemu = false;
    char kabur;
    for (int i = 0; i < n; i++) {
        if (((bx - ax) == 1) && ((by - ay) == 1)) {
            answer(bx, by);
        }
        int mx = (ax + bx) / 2;
        int my = (ay + by) / 2;
        pair<int, char> query = ask(mx, my);
        update(ax, ay, query.second);
        update(bx, by, query.second);
        update(mx, my, query.second);
        if (query.first == 1) {
            ax = mx, ay = my;
        } else if (query.first == 2) {
            ay = my, bx = mx;
        } else if (query.first == 3) {
            bx = mx, by = my;
        } else if (query.first == 4) {
            ax = mx, by = my;
        }
        if (((bx - ax) == 1) && ((by - ay) == 1)) {
            ketemu = true;
            gotcha = make_pair(bx, by);
            break;
        }
    }
    if (ketemu) {
        int a = gotcha.first, b = gotcha.second;
        answer(a, b);
    }
}

int main() {
    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}