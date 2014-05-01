fn main() {
    let mut sum: uint = 0;
    for i in range(3, 1000) {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i as uint;
        }
    }
    println!("{}", sum);
}
