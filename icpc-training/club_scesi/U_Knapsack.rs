use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let w = lines.next().unwrap().unwrap().parse().unwrap()
    let sl = lines.next().unwrap().unwrap();
    let mut parts = sl.split_whitespace();
    let mut items = Vec::new();
    while (parts.len() > 1) {
        items.push(parts.next().unwrap().parse().unwrap());
    
    let mut jairo = vec![std::i64::MIN; w + 1];
    jairo[0] = 0;
    
    for x in items {
        for j in (x..=w).rev() {
            let ant = j - x;
            if jairo[ant] != std::i64::MIN && jairo[j] < jairo[ant] + x {
                jairo[j] = jairo[ant] + x;
            }
        }
    }
    
    let max_valor = jairo.iter().max().unwrap();
    println!("{}", max_valor);
}