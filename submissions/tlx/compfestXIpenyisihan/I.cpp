#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

int m, n, kanan = -1, atas = -1;
int ans[N + 5], pre[N + 5], add[N + 5];
vector<pair<int, int>> juri;
vector<pair<pair<int, int>, pair<int, int>>> grad;
vector<pair<pair<int, int>, int>> ch, kue;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if(a.first.first == b.first.first)
    return a.first.second > b.first.second;
  return a.first.first < b.first.first;
}

bool ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  int dx1 = b.first - a.first, dy1 = b.second - a.second;
  int dx2 = c.first - a.first, dy2 = c.second - a.second;
  return (1LL * dx1 * dy2 - 1LL * dx2 * dy1 > 0);
}

pair<int, int> gradien(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}

bool compGrad(pair<int, int> a, pair<int, int> b) {
  return (1LL * a.first * b.second - 1LL * a.second * b.first < 0);
}

bool compGradFull(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
  return compGrad(a.first, b.first);
}

bool equal(pair<int, int> a, pair<int, int> b) {
  return (1LL * a.first * b.second == 1LL * a.second * b.first);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> m >> n;
  for(int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    juri.emplace_back(b, -a);
  }
  int atas = -1, bawah = -1;
  for(int i = 1; i <= n; i++) {
    int l, c;
    cin >> l >> c;
    kue.emplace_back(make_pair(l, c), i);
    atas = max(atas, c);
    kanan = max(kanan, l);
  }
  sort(kue.begin(), kue.end(), comp);
  ch.emplace_back(make_pair(0, atas), -1);
  for(int i = 0; i < (int)kue.size(); i++) {
    while((int)ch.size() >= 2 && ccw(ch[ch.size() - 2].first, ch[ch.size() - 1].first, kue[i].first))
      ch.pop_back();
    ch.emplace_back(kue[i].first, kue[i].second);
  }
  ch.emplace_back(make_pair(kanan, 0), -1);
  int le = 0, ri = 1;
  pair<int, int> curGrad = make_pair(1, 0);
  for(int i = 1; i < (int)ch.size() - 1; i++) {
    if(equal(gradien(ch[i + 1].first, ch[i].first), curGrad))
      ri = i + 1;
    else {
      grad.emplace_back(curGrad, make_pair(le, ri));
      le = ri;
      ri = i + 1;
      curGrad = gradien(ch[ri].first, ch[le].first);
    }
  }
  grad.emplace_back(curGrad, make_pair(le, ri));

  for(int i = 0; i < (int)juri.size(); i++) {
    auto j = lower_bound(grad.begin(), grad.end(), make_pair(juri[i], make_pair(0, 0)), compGradFull) - grad.begin();
    if(equal(grad[j].first, juri[i])) {
      add[grad[j].second.first]++;
      add[grad[j].second.second + 1]--;
    } else {
      add[grad[j].second.first]++;
      add[grad[j].second.first + 1]--;
    }
  }
  for(int i = 1; i < (int)ch.size() - 1; i++) {
    pre[i] = pre[i - 1] + add[i];
    ans[ch[i].second] = pre[i];
  }
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}