pub struct BIT { n: i32, bit: Vec<i32> }

impl BIT {
    fn f(n: i32) -> Self { Self { n: n, bit: vec![0; (n + 1) as usize] } }
    fn upd(&mut self, mut x: i32, val: i32) { while x <= self.n { self.bit[x as usize] += val; x += x & (-x); } }
    fn get(&self, mut x: i32) -> i32 { let mut res = 0; while x > 0 { res += self.bit[x as usize]; x -= x & (-x); } res }
    fn get_range(&self, l: i32, r: i32) -> i32 { Self::get(self, r) - Self::get(self, l - 1) }
}

fn main() {
    let n: i32 = 10;
    let mut bit: BIT = BIT::f(n);
    bit.upd(1, 2);
    println!("{}", n);
    println!("{}", bit.get(1));
    bit.upd(2, 3);
    println!("{}", bit.get_range(1, 2));
    let x1: i32 = bit.get_range(1, 5);
    bit.upd(1, -1);
    let x2: i32 = bit.get_range(1, 5);
    println!("x1 = {}", x1);
    println!("x2 = {}", x2);
}