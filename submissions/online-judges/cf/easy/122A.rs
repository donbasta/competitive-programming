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
    let mut n = scan.token::<usize>();
    let mut ok = true;
    let lucky = [4, 7, 44, 47, 74, 77,
                444, 447, 474, 477, 744, 747, 774, 777];
    let mut ans = "NO";
    for l in lucky.iter() {
        if n % l == 0 {
            ans = "YES";
        }
    }
    writeln!(w, "{}", ans).ok();
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let mut tc = 1;
    // tc = scan.token::<usize>();
    for i in 1..(tc + 1) {
        // print!("Case #{}:", i);
        solve(&mut scan, &mut out);
    }
}
