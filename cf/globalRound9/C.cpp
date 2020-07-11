// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;
// using ld = long double;

// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0); cout.tie(0);

//   int tc;
//   cin >> tc;
//   while(tc--) {
//     int n;
//     cin >> n;
//     vector<int> ve;
//     for(int i = 0; i < n; i++) {
//       int x;
//       cin >> x;
//       ve.emplace_back(x);
//       while((int)ve.size())
//       if(!ve.empty() && ve.back() < x)
//         continue;
//     }
//     while((int)ve.size() > 1 && ve[ve.size() - 2] < ve.back())
//       ve.pop_back();
//     if((int)ve.size() == 1)
//       cout << "YES";
//     else
//       cout << "NO";
//     cout << '\n';
//   }

//   return 0;
// }

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    vector<int> ve(n);
    for(int i = 0; i < n; i++) {
      cin >> ve[i];
    }
    if(ve[0] < ve[n - 1])
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }

  return 0;
}
