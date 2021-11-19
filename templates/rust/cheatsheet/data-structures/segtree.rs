use std::cmp::{min,max};

pub struct Segtree {
    n: usize,
    tree: Vec<i32>
}

impl Segtree {
    fn f(n: usize) -> Self {
        Self { n: n, tree: vec![0; 4 * n + 5] }
    }
    fn build(&mut self, v: usize, l: usize, r: usize, ar: &[i32]) {
        if l == r {
            self.tree[v] = ar[l];
        } else {
            let mid: usize = (l + r) / 2;
            Self::build(self, v * 2, l, mid, ar);
            Self::build(self, v * 2 + 1, mid + 1, r, ar);
            self.tree[v] = self.tree[v * 2] + self.tree[v * 2 + 1];
        }
    }
    fn upd(&mut self, v: usize, s: usize, e: usize, l: usize, r: usize, val: i32) {
        if l > r || r < s || l > e {
            return
        } else if l == s && r == e {
            self.tree[v] += val;
            return
        }
        let mid: usize = (s + e) / 2;
        Self::upd(self, v * 2, s, mid, l, min(mid, r), val);
        Self::upd(self, v * 2 + 1, mid + 1, e, max(l, mid + 1), r, val);
    }
    fn get(&self, v: usize, s: usize, e: usize, l: usize, r: usize) -> i32 {
        if l > r || r < s || l > e {
            return 0;
        } else if l == s && r == e {
            return self.tree[v];
        } 
        let mid: usize = (s + e) / 2;
        return Self::get(self, v * 2, s, mid, l, min(mid, r)) + Self::get(self, v * 2 + 1, mid + 1, e, max(l, mid + 1), r);
    }
}

fn main() {
    let mut segtree: Segtree = Segtree::f(10);
    let ve: Vec<i32> = vec![2; 15];
    segtree.build(1, 1, 10, &ve);
    println!("{}", segtree.get(1, 1, 10, 1, 10));
    segtree.upd(1, 1, 10, 1, 1, 3);
    segtree.upd(1, 1, 10, 3, 3, 7);
    println!("{}", segtree.get(1, 1, 10, 1, 2));
    println!("{}", segtree.get(1, 1, 10, 3, 3));
}