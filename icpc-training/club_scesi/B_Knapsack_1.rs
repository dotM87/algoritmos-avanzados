use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let fline = lines.next().unwrap().unwrap();
    let mut parts = fline.split_whitespace();
    let n: usize = parts.next().unwrap().parse().unwrap();
    let w: usize = parts.next().unwrap().parse().unwrap();
    
    let mut items = Vec::new();
    for _ in 0..n {
        let line = lines.next().unwrap().unwrap();
        let mut parts = line.split_whitespace();
        let peso: usize = parts.next().unwrap().parse().unwrap();
        let valor: i64 = parts.next().unwrap().parse().unwrap();
        items.push((peso, valor));
    }
    
    let mut diego = vec![std::i64::MIN; w + 1];
    diego[0] = 0;
    
    for (peso, valor) in items {
        for j in (peso..=w).rev() {
            let ant = j - peso;
            if diego[ant] != std::i64::MIN && diego[j] < diego[ant] + valor {
                diego[j] = diego[ant] + valor;
            }
        }
    }
    
    let max_valor = diego.iter().max().unwrap();
    println!("{}", max_valor);
}