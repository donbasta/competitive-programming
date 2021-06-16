#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 69;
set<pair<int,int> > s;
vector<int> v[N];
bool del[N];
int deg[N],occ[N];
void remove(int node)
{
    if (del[node])
    return;
    s.erase({deg[node],node});
    del[node]=1;
    for (int u:v[node])
    {
        if (!del[u])
        {
            s.erase({deg[u],u});
            deg[u]--;
            s.insert({deg[u],u});
        }
    }
}
int main()
{
      #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for (int i=1; i<=n; i++)
    s.insert({deg[i],i});
    vector<int> ans;
    cerr << "lol\n";
    while (!s.empty())
    {
        auto p=*s.begin();
        s.erase(s.begin());
        ans.push_back(p.second);
        remove(p.second);
        for (int u:v[p.second])
        remove(u);
    }
    cout << (int)ans.size() << '\n';
    vector<bool> yes(n + 1);
    for(auto i : ans){
        yes[i] = true;
    }
    for(int i = 1; i <= n; i++) {
        cout << (yes[i] ? 1 : 0) << ' ';
    }
}