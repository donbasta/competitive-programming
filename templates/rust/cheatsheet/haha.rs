#![allow(dead_code)]
#![allow(unused)]
 
#![allow(unused_imports)]
use std::collections::{HashSet, HashMap};
use std::cmp::{min, max, Reverse};
use std::io::{self, prelude::*};
use std::str;

struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitWhitespace<'static>,
}

impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self { reader, buf_str: vec![], buf_iter: "".split_whitespace() }
    }
    fn token<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader.read_until(b'\n', &mut self.buf_str).expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_whitespace())
            }
        }
    }
}

use std::ops::{Add, Div, Mul, Neg, Sub, AddAssign, SubAssign, MulAssign, DivAssign};
use std::fmt::{Display, Formatter, Result};

#[derive(Clone, Copy, Eq, PartialEq, Debug, Hash)]
pub struct ModInt<const M: i32> { val: i32 }

fn fpow<const M: i32>(a: &ModInt<M>, mut b: i32) -> ModInt<M> {
    let mut res: ModInt<M> = ModInt::<M>::from(1);
    let mut ca = *a;
    while b > 0 {
        if b % 2 == 1 { res *= ca; }
        ca *= ca; b /= 2;
    }
    res
}
fn inverse<const M: i32>(a: &ModInt<M>) -> ModInt<M> { fpow(a, M - 2) }

impl<const M: i32> ModInt<M> { fn f(s: i32) -> Self { let val = if s < 0 { s + M } else { s }; Self { val } } }
impl<const M: i32> From<i32> for ModInt<M> { fn from(val: i32) -> Self { Self::f(val % M) } }
impl<const M: i32> From<i64> for ModInt<M> { fn from(val: i64) -> Self { Self::f((val % M as i64) as i32) } }
impl<const M: i32> From<usize> for ModInt<M> { fn from(val: usize) -> Self { Self::f((val as i32) % M) } }
impl<const M: i32> Neg for ModInt<M> { type Output = Self; fn neg(self) -> Self { Self::f(-self.val) } }
impl<const M: i32> Add for ModInt<M> { type Output = Self; fn add(self, other: Self) -> Self { Self::f(self.val + other.val - M) } }
impl<const M: i32> Sub for ModInt<M> { type Output = Self; fn sub(self, other: Self) -> Self { Self::f(self.val - other.val) } }
impl<const M: i32> Mul for ModInt<M> { type Output = Self; fn mul(self, other: Self) -> Self { Self::from(self.val as i64 * other.val as i64) } }
impl<const M: i32> Div for ModInt<M> { type Output = Self; fn div(self, other: Self) -> Self { self * inverse(&other) } }
impl<const M: i32> AddAssign for ModInt<M> { fn add_assign(&mut self, other: Self) { *self = *self + other; } }
impl<const M: i32> SubAssign for ModInt<M> { fn sub_assign(&mut self, other: Self) { *self = *self - other; } }
impl<const M: i32> MulAssign for ModInt<M> { fn mul_assign(&mut self, other: Self) { *self = *self * other; } }
impl<const M: i32> DivAssign for ModInt<M> { fn div_assign(&mut self, other: Self) { *self = *self / other; } }
impl<const M: i32> Display for ModInt<M> { fn fmt(&self, f: &mut Formatter<'_>) -> Result { write!(f, "{}", self.val) } }

const MOD: i32 = 1e9 as i32 + 7;
type Mint = ModInt<MOD>;

fn init_fac(mx: usize) -> (Vec<Mint>, Vec<Mint>) {
    let mut fc: Vec<Mint> = vec![Mint::from(0); mx + 5];
    let mut ifc: Vec<Mint> = vec![Mint::from(0); mx + 5];
    fc[0] = Mint::from(1);
    for i in 1..(mx + 1) { fc[i] = fc[i - 1] * Mint::from(i as i32); }
    ifc[mx] = inverse(&fc[mx]);
    for i in (0..mx).rev() { ifc[i] = ifc[i + 1] * Mint::from((i + 1) as i32); }
    (fc, ifc)
}

const MX: i32 = 400;

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let n = scan.token::<i32>();
    let k = scan.token::<i32>();
    let sz = min(n, MX);
    let mut pick = vec![Mint::from(0); (sz + 1) as usize];
    pick[0] = Mint::from(1);
    pick[1] = Mint::from(n);
    for i in 2..(sz + 1) as usize {
        pick[i] = pick[i - 1] * Mint::from(n - i as i32 + 1) / Mint::from(i as i32);
    }
    let mut f = vec![vec![Mint::from(0); (sz + 1) as usize]; (sz + 1) as usize];
    f[0][0] = Mint::from(1);
    for i in 2..(sz + 1) as usize {
        for j in 1..((i / 2) + 1) as usize  {
            f[i][j] = Mint::from(i - 1) * (f[i - 2][j - 1] + f[i - 1][j]);
        }
    }
    let mut dp = vec![Mint::from(0); (k + 1) as usize];
    let mut ans = vec![Mint::from(0); (k + 1) as usize];
    for i in 0..(k + 1) as usize {
        for j in i..(sz + 1) as usize {
            dp[i] += f[j][j - i] * pick[j];
        }
    }
    ans[0] = dp[0];
    ans[1] = dp[1];
    for i in 2..(k + 1) as usize {
        ans[i] = ans[i - 2] + dp[i];
    }
    for i in 1..(k + 1) as usize {
        write!(w, "{} ", &ans[i]);
    }
    writeln!(w, "");
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let mut tc = 1;
    for i in 1..(tc + 1) {
        solve(&mut scan, &mut out);
    }
}
