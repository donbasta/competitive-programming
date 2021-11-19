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

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, w: &mut W) {
    let s = scan.token::<String>();
    let n = s.len();
    let mut a1: i32 = n as i32;
    let mut a2: i32 = -1;
    let mut b1: i32 = n as i32;
    let mut b2: i32 = -1;
    for i in 0..(n - 1) {
        let ss = &s[i as usize..(i + 2) as usize];
        dbg!(ss);
        if ss == "AB" {
            a1 = min(a1, i as i32); a2 = max(a2, i as i32);
        }
        if ss == "BA" {
            b1 = min(b1, i as i32); b2 = max(b2, i as i32);
        }
    }
    dbg!(a1, a2, b1, b2);
    let mut ans = "NO";
    if a2 >= 0 && b2 >= 0 && (a2 - b1 > 1 || b2 - a1 > 1) {
        ans = "YES";
    }
    writeln!(w, "{}", ans);
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
