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
    dbg!(mx);
    let mut fc: Vec<Mint> = vec![Mint::from(0); mx + 5];
    let mut ifc: Vec<Mint> = vec![Mint::from(0); mx + 5];
    fc[0] = Mint::from(1);
    for i in 1..(mx + 1) { fc[i] = fc[i - 1] * Mint::from(i as i32); }
    ifc[mx] = inverse(&fc[mx]);
    for i in (0..mx).rev() { ifc[i] = ifc[i + 1] * Mint::from((i + 1) as i32); }
    (fc, ifc)
}

fn mint<T>(a: T) -> Mint where Mint: From<T> { Mint::from(a) }

fn main() {
    let a: Mint = mint(1);
    let b: Mint = mint(2);
    let c: Mint = a / b;
    println!("a={}, b={}, c={}", a, b, c);
    let (fc, ifc) = init_fac(20);
    for i in 1..20 {
        println!("factorial of {} is equal to {} in modulo {}", i, fc[i], MOD);
    }
}
