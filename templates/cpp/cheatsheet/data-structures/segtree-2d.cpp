class Segtree2D {
    vector<vector<int>> tree;
    vector<vector<int>> ar;
    int m, n;

   public:
    Segtree2D(const vector<vector<int>>& ar) ar(ar) {
        int m = ar.size();
        int n = ar[0].size();
        this->m = m, this->n = n;
        tree.assign(4 * m + 5, vector<int>(4 * n + 5));
        build_x(1, 0, m - 1);
    }
    void build_x(int v, int s, int e) {
        if (s != e) {
            int mid = (s + e) >> 1;
            build_x(v << 1, s, mid);
            build_x(v << 1 | 1, mid + 1, e);
        }
        build_y(v, s, e, 1, 0, n - 1);
    }
    void build_y(int vx, int sx, int ex, int vy, int sy, int ey) {
        if (sy == ey) {
            if (sx == ex) {
                tree[vx][vy] = ar[sx][sy];
            } else {
                tree[vx][vy] = tree[vx << 1][vy] + tree[vx << 1 | 1][vy];
            }
        } else {
            int mid = (sy + ey) >> 1;
            build_y(vx, sx, ex, vy << 1, sy, mid);
            build_y(vx, sx, ex, vy << 1 | 1, mid + 1, ey);
            tree[vx][vy] = tree[vx][vy << 1] + tree[vx][vy << 1 | 1];
        }
    }
    int sum_x(int vx, int sx, int ex, int lx, int rx, int ly, int ry) {
        if (lx > rx) return 0;
        if (lx == sx && rx == ex) return sum_y(vx, 1, 0, n - 1, ly, ry);
        int mx = (sx + ex) >> 1;
        return sum_x(vx << 1, sx, mx, lx, min(rx, mx), ly, ry) + sum_x(vx << 1 | 1, mx + 1, ex, max(lx, mx + 1), rx, ly, ry);
    }
    int sum_y(int vx, int vy, int sy, int ey, int ly, int ry) {
        if (ly > ry) return 0;
        if (ly == sy && ry == ey) return tree[vx][vy];
        int my = (sy + ey) >> 1;
        return sum_y(vx, vy << 1, sy, my, ly, min(ry, my)) + sum_y(vx, vy << 1 | 1, my + 1, ey, max(ly, my + 1), ry);
    }
    void upd_x(int vx, int sx, int ex, int x, int y, int new_val) {
        if (sx != ex) {
            int mx = (sx + ex) >> 1;
            if (x <= mx)
                upd_x(vx << 1, sx, mx, x, y, new_val);
            else
                upd_x(vx << 1 | 1, mx + 1, ex, x, y, new_val);
        }
        upd_y(vx, sx, ex, 1, 0, n - 1, x, y, new_val);
    }
    void upd_y(int vx, int sx, int ex, int vy, int sy, int ey, int x, int y, int new_val) {
        if (sy == ey) {
            if (sx == ex)
                tree[vx][vy] = new_val;
            else
                tree[vx][vy] = tree[vx << 1][vy] + tree[vx << 1 | 1][vy];
        } else {
            int my = (sy + ey) >> 1;
            if (y <= my) {
                upd_y(vx, sx, ex, vy << 1, sy, my, x, y, new_val);
            } else {
                upd_y(vx, sx, ex, vy << 1 | 1, my + 1, ey, x, y, new_val);
            }
            tree[vx][vy] = tree[vx][vy << 1] + tree[vx][vy << 1 | 1];
        }
    }
}