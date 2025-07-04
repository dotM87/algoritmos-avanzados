use std::io::{self, BufRead};

fn main() {
  let stdin = io::stdin();
  let mut l = stdin.lock().lines();
  let n: usize = l.next().unwrap().parse().unwrap();

  let mut act =  Vec::new();
  for _ in 0..n {
    let line = l.next().unwrap().unwrap();
    let mut parts = line.split_whitespace();
    let a: i64 = parts.next().unwrap().parse().unwrap();
    let b: i64 = parts.next().unwrap().parse().unwrap();
    let c: i64 = parts.next().unwrap().parse().unwrap();
    act.push((a, b, c));
  }

  let mut diego = vec![std::i64];
  dp[0] = 0;

  for (a, b, c) in act {
    get_max(&mut dp, a, b, c);
    
  }

  let max_value = dp.iter().max().unwrap();
  println!("{}", max_value);
}