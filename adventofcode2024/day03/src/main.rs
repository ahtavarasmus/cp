use std::fs::read_to_string;
use regex::Regex;

fn read_input(file_path: &str) -> String {
    read_to_string(file_path).unwrap().trim().to_string()
}

fn part1(input: &str) -> i32 {
    let re = Regex::new(r"mul\((\d{1,3}),(\d{1,3})\)").unwrap();
    let mut sum = 0;
    for cap in re.captures_iter(&input) {
        let x: i32 = cap[1].parse().unwrap();
        let y: i32 = cap[2].parse().unwrap();
        sum += x*y;
    }
    sum
}

fn part2(input: &str) -> i32 {
    // Implement part 2 solution here
    let mul_re= Regex::new(r"mul\((\d{1,3}),(\d{1,3})\)").unwrap();
    let do_re = Regex::new(r"do\(\)").unwrap();
    let dont_re = Regex::new(r"don't\(\)").unwrap();
    let combined_re = Regex::new(r"mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\)").unwrap();
    let mut sum = 0;
    let mut enabled: bool = true;

    for caps in combined_re.captures_iter(&input) {
        let whole = &caps[0];
        if mul_re.is_match(whole) {
            if enabled {
                let mul_caps = mul_re.captures(whole).unwrap();
                let x: i32 = mul_caps[1].parse().unwrap();
                let y: i32 = mul_caps[2].parse().unwrap();
                sum += x * y;
            }
        } else if do_re.is_match(whole) {
            enabled = true;
        } else if dont_re.is_match(whole) {
            enabled = false;
        }

    }

    sum
}

fn main() {
    let input = read_input("src/input.txt");
    
    println!("Part 1: {}", part1(&input));
    println!("Part 2: {}", part2(&input));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_part1() {
        let test_input = "";  // Add example input here
        assert_eq!(part1(test_input), 0);
    }

    #[test]
    fn test_part2() {
        let test_input = "";  // Add example input here
        assert_eq!(part2(test_input), 0);
    }
}


