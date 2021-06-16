#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
set<pair<int, int>> R, G, B; 
set<pair<int, int>> se;
vector<pair<int, int>> RR, GG, BB;
vector<int> ID;
map<int, int> red, green, blue, cost;

void lol(int del, set<pair<int, int>>& SET, map<int, int>& MAP) {
  auto it = SET.find(make_pair(MAP[del], del));
  auto temp = it;
  int now = MAP[del];
  if(temp == SET.begin()) {
    auto la = SET.end(); --la;
    auto next = it; ++next;
    int dis1 = next->first - now;
    int dis2 = 360 - la->first + now;
    // if(la->first == next->first) return;
    if(next->first == now) {
      auto iit = next; auto temp = iit; 
      if(++temp == SET.end()) iit = SET.begin();
      else ++iit;
      if(iit->first != now) {
        se.erase(se.find(make_pair(cost[next->second], -(next->second))));
        cost[next->second] += (iit->first - now + dis2);
        if(iit == SET.begin()) cost[next->second] += 360;
        se.insert(make_pair(cost[next->second], -(next->second)));
      }
      return;
    }
    se.erase(se.find(make_pair(cost[la->second], -(la->second))));
    se.erase(se.find(make_pair(cost[next->second], -(next->second))));
    auto lol = la; --lol;
    if(lol->first != la->first) cost[la->second] += dis1;
    lol = next; ++lol;
    if(lol->first != next->first) cost[next->second] += dis2;
    se.insert(make_pair(cost[la->second], -(la->second)));
    se.insert(make_pair(cost[next->second], -(next->second)));
  } else if((++temp) == SET.end()) {
    auto fi = SET.begin();
    auto prev = it; --prev;
    int dis1 = 360 + fi->first - now;
    int dis2 = now - prev->first;
    if(fi->first == prev->first) return;
    if(prev->first == now) {
      auto iit = prev; auto temp = iit;
      if(temp == SET.begin()) iit = SET.end();
      --iit;
      if(iit->first != now) {
        se.erase(se.find(make_pair(cost[prev->second], -(prev->second))));
        cost[prev->second] += (dis1 + now - iit->first);
        if(prev == SET.begin()) cost[prev->second] += 360;
        se.insert(make_pair(cost[prev->second], -(prev->second)));
      }
      return;
    }
    se.erase(se.find(make_pair(cost[fi->second], -(fi->second))));
    se.erase(se.find(make_pair(cost[prev->second], -(prev->second))));
    auto lol = fi; ++lol;
    if(lol->first != fi->first) cost[fi->second] += dis2;
    lol = prev; --lol;
    if(lol->first != prev->first) cost[prev->second] += dis1;
    se.insert(make_pair(cost[fi->second], -(fi->second)));
    se.insert(make_pair(cost[prev->second], -(prev->second)));
  } else {
    auto next = it; ++next;
    auto prev = it; --prev;
    int dis1 = next->first - now;
    int dis2 = now - prev->first;
    if(next->first == prev->first) return;
    if(next->first == now) {
      auto iit = next; auto temp = iit; 
      if(++temp == SET.end()) iit = SET.begin();
      else ++iit;
      if(iit->first != now) {
        se.erase(se.find(make_pair(cost[next->second], -(next->second))));
        cost[next->second] += (iit->first - now + dis2);
        if(iit == SET.begin()) cost[next->second] += 360;
        se.insert(make_pair(cost[next->second], -(next->second)));
      }
      return;
    } 
    if(prev->first == now) {
      auto iit = prev; auto temp = iit;
      if(temp == SET.begin()) iit = SET.end();
      --iit;
      if(iit->first != now) {
        se.erase(se.find(make_pair(cost[prev->second], -(prev->second))));
        cost[prev->second] += (dis1 + now - iit->first);
        if(prev == SET.begin()) cost[prev->second] += 360;
        se.insert(make_pair(cost[prev->second], -(prev->second)));
      }
      return;
    }
    se.erase(se.find(make_pair(cost[prev->second], -(prev->second))));
    se.erase(se.find(make_pair(cost[next->second], -(next->second))));
    auto lol = next; ++lol;
    auto temp = next;
    if(--temp == SET.end() || lol->first != next->first) cost[next->second] += dis2;
    lol = prev; --lol;
    temp = prev;
    if(temp == SET.begin() || lol->first != prev->first) cost[prev->second] += dis1;
    se.insert(make_pair(cost[prev->second], -(prev->second)));
    se.insert(make_pair(cost[next->second], -(next->second)));
  }
}

void upd(int del) {
  lol(del, R, red);
  lol(del, G, green);
  lol(del, B, blue);
  R.erase(R.find(make_pair(red[del], del)));
  G.erase(G.find(make_pair(green[del], del)));
  B.erase(B.find(make_pair(blue[del], del)));
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int r, g, b, id;
    cin >> r >> g >> b >> id;
    ID.emplace_back(id);
    red[id] = r;
    green[id] = g;
    blue[id] = b;
    R.emplace(r, id), RR.emplace_back(r, id);
    G.emplace(g, id), GG.emplace_back(g, id);
    B.emplace(b, id), BB.emplace_back(b, id);
  }
  sort(ID.begin(), ID.end(), greater<int>());
  if(n == 1) {
    cout << ID[0] << '\n';
    return;
  } else if(n == 2) {
    cout << ID[0] << '\n';
    cout << ID[1] << '\n';
    return;
  }
  sort(RR.begin(), RR.end());
  sort(GG.begin(), GG.end());
  sort(BB.begin(), BB.end());
  for(int i = 0; i < n; i++) {
    int prev, next;
    if(i == 0 || i == n - 1) {
      if(i == 0) prev = n - 1, next = 1;
      else if(i == n - 1) prev = n - 2, next = 0;
      if(RR[i].first != RR[prev].first && RR[i].first != RR[next].first)
        cost[RR[i].second] += RR[next].first - RR[prev].first + 360;
      if(BB[i].first != BB[prev].first && BB[i].first != BB[next].first)
        cost[BB[i].second] += BB[next].first - BB[prev].first + 360;
      if(GG[i].first != GG[prev].first && GG[i].first != GG[next].first)
        cost[GG[i].second] += GG[next].first - GG[prev].first + 360;
      continue;
    }
    prev = i - 1, next = i + 1;
    if(RR[i].first != RR[prev].first && RR[i].first != RR[next].first)
      cost[RR[i].second] += RR[next].first - RR[prev].first;
    if(BB[i].first != BB[prev].first && BB[i].first != BB[next].first)
      cost[BB[i].second] += BB[next].first - BB[prev].first;
    if(GG[i].first != GG[prev].first && GG[i].first != GG[next].first)
      cost[GG[i].second] += GG[next].first - GG[prev].first;
  }
  for(auto i : ID) {
    se.emplace(cost[i], -i);
  }
  while((int)se.size() > 2) {
    auto now = *(se.begin());
    se.erase(se.begin());
    cout << -now.second << '\n';
    upd(-now.second);
  }
  pair<int, int> las[2];
  int j = 0;
  for(auto i : se) {
    las[j++] = i;
  }
  assert(las[0].first == las[1].first);
  cout << max(-las[0].second, -las[1].second) << '\n';
  cout << min(-las[1].second, -las[0].second) << '\n';
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