struct BIT<T> { n: i32, bit: Vec<T> }

impl<T> BIT<T> {
    fn upd(self, mut x: i32, val: T) {
        while x > 0 { bit[x as usize] += val; x -= (x & (-x)); }
    }
    fn get(self, mut x: i32) -> T {
        let mut res = 0;
        while x <= n { res += bit[x as usize]; x += (x & (-x)); }
        res
    }
    fn get(self, l: i32, i: i32) { get(r) - get(l - 1) }
}

