// prompt: By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

fn main () {
    let mut vec = Vec::new();
    vec.push(1);
    vec.push(2);
    let mut sum = 0;
    // first we need to find the terms that do not exceed four million.

    // loop to add new numbers to our fibonacci sequence
    while vec[vec.len()-1] < 4000000{ // while the latest term is less than 4 million
        let latest = *vec.last().unwrap(); // the first previous term
        let second_latest = vec[vec.len()-2]; // the second previous term
        let new_num = latest + second_latest; // the new term is the sum of the previous two
        if new_num > 4000000 { // if the new term is greater than 4 million, break the loop
            break;
        }
        vec.push(new_num); // otherwise, append it to the list.
    }

    // find the sum of all even values
    for i in &vec {
        if i%2==0 {
            sum = sum + i;
        };
    }
    println!("Sum: {}", sum); // print the sum
}
