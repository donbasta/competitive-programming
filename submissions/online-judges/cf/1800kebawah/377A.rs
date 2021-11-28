#![allow(dead_code)]
#![allow(unused)]
 
#![allow(unused_imports)]
use std::collections::{HashSet, HashMap, VecDeque};
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
    let k = scan.token::<usize>();
    
    let mut grid = vec![vec![]; n];
    let mut vis = vec![vec![false; m]; n];
    let mut pos = (0, 0);
    for i in 0..n {
        let tmp = scan.token::<String>();
        grid[i] = tmp.as_str().chars().collect();
        for j in 0..m { if grid[i][j] != '#' { pos = (i, j); } }
    }

    let mut q = VecDeque::new();
    let mut ve = vec![];
    let dx: [i32; 4] = [1, -1, 0, 0];
    let dy: [i32; 4] = [0, 0, 1, -1];
    q.push_front(pos);
    vis[pos.0][pos.1] = true;
    while !q.is_empty() {
        let now = match q.back() {
            Some(x) => *x,
            None => {assert!(false); (0, 0)}
        };
        q.pop_back();
        for i in 0..4 {
            let nx: i32 = now.0 as i32 + dx[i];
            let ny: i32 = now.1 as i32 + dy[i];
            if nx < 0 || nx >= n as i32 || ny < 0 || ny >= m as i32 { continue; }
            let nx: usize = nx as usize;
            let ny: usize = ny as usize;
            if grid[nx][ny] == '#' { continue; }
            if vis[nx][ny] { continue; }
            vis[nx][ny] = true;
            q.push_front((nx, ny));
            ve.push((nx, ny));
        }
    }

    let s = ve.len();
    for i in (s - k)..s {
        grid[ve[i].0][ve[i].1] = 'X';
    }

    for i in 0..n {
        for j in 0..m {
            write!(w, "{}", grid[i][j]);
        }
        writeln!(w, "");
    }
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
