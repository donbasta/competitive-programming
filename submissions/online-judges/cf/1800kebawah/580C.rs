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
    let n = scan.token::<usize>();
    let m = scan.token::<usize>();

    let mut ar = vec![0; n + 1];
    let mut adj = vec![vec![]; n + 1];
    let mut last = vec![0; n + 1];
    let mut ok = vec![true; n + 1];

    for i in 1..(n + 1) {
        ar[i] = scan.token::<i32>();
    }

    for i in 1..n {
        let x = scan.token::<usize>();
        let y = scan.token::<usize>();
        adj[x].push(y);
        adj[y].push(x);
    }

    let mut ans = 0;
    if ar[1] == 1 { last[1] = 1; }

    struct GraphEnv { last: Vec<usize>, ok: Vec<bool>, ans: i32 }
    struct Rec<'s> { f: &'s dyn Fn(&Rec, usize, usize, &mut GraphEnv) }
    let mut env = GraphEnv { last, ok, ans };
    let dfs = Rec {
        f: &|dfs, v, p, env| {
            let mut ch = 0;
            for c in adj[v].iter() {
                if *c == p { continue; }
                ch += 1;
                env.ok[*c] &= env.ok[v];
                if ar[*c] == 1 { env.last[*c] = env.last[v] + 1; }
                if env.last[*c] > m { env.ok[*c] = false; }
                (dfs.f)(dfs, *c, v, env);
            }
            if ch == 0 && env.ok[v] { env.ans += 1; }
        }
    };

    (dfs.f)(&dfs, 1, 1, &mut env);
    writeln!(w, "{}", env.ans);
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
