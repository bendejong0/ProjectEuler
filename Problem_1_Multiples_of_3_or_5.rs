//rust
//prompt: find the sum of all the multiples of 3 or 5 below 1000.
fn main () {
    let mut sum: i32 = 0; // the total sum of the multiples
    for i in 0..1000{
        if i % 3 == 0 || i % 5 == 0{ // if it's divisible by 3 or 5 add it to the sum
            sum += i;
        }
    }
    println!("Sum: {}", sum);
}
