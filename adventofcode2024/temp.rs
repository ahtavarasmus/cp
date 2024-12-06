use std::fs::read_to_string;

fn read_input(file_path: &str) -> String {
    read_to_string(file_path).unwrap().trim().to_string()
}

fn part1(input: &str) -> i32 {
    // Implement part 1 solution here
    0
}

fn part2(input: &str) -> i32 {
    // Implement part 2 solution here
    0
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


