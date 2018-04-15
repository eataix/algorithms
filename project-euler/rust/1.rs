#![feature(iter_arith)]

fn main() {
    let sum: u64 = (1u64..1000u64).filter(|i| i % 3 == 0 || i % 5 == 0).sum();
    println!("{}", sum);
}
