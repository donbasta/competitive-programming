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
    let mut ret = String::new();
    let ve = ['a', 'o', 'y', 'e', 'u', 'i'];
    for ch in s.chars() {
        let ch_lower = ch.to_ascii_lowercase();
        let mut ada = false;
        for vowel in &ve {
            if vowel == &ch_lower { ada = true; }
        }
        if !ada {
            ret.push('.');
            ret.push(ch_lower);
        } 
    }
    writeln!(w, "{}", ret);
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
