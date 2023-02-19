class Solution {
   public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long res = 0;
        map<int, vector<int>> g;
        for (auto& v : roads) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        auto dfs = [&](int node, int mask, auto&& self) -> int {
            int totalCar = 1;  // count this node
            for (auto& childNode : g[node]) {
                if ((mask >> childNode) && 1) continue;
                totalCar += self(childNode, mask | (1 << childNode), self);
            }
            cout << totalCar << " " << node << "\n";
            return ceil((double)totalCar / seats);
        };
        return dfs(0, 1, dfs) - 1;
    }
};