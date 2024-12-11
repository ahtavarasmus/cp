use std::fs::read_to_string;
use regex::Regex;

fn read_input(file_path: &str) -> String {
    read_to_string(file_path).unwrap().trim().to_string()
}

fn part1(input: &str) -> usize {
    let grid: Vec<Vec<char>> = input.lines().map(|line| line.chars().collect()).collect();
    let mut sum: usize = 0;
    for i in 0..grid.len() {
        let re = Regex::new(r"XMAS").unwrap();

        

        let left: String = grid[i].iter().collect();
        sum += re.find_iter(&left).count();

        let right: String = grid[i].iter().rev().collect();
        sum += re.find_iter(&right).count();

        let top: String = grid.iter().map(|row| row[i]).collect();
        sum += re.find_iter(&top).count();

        let bottom: String = grid.iter().map(|row| row[i]).rev().collect();
        sum += re.find_iter(&bottom).count();

        let mut top_left: Vec<char> = Vec::new();
        let mut k: usize = 0;
        for j in i..grid.len() {
            top_left.push(grid[j][k]);
            k += 1;
        }
        let top_left_str: String = top_left.iter().collect();
        sum += re.find_iter(&top_left_str).count();

        let mut bottom_right: Vec<char> = Vec::new();
        k = 0;
        for j in (0..=i).rev() {
            bottom_right.push(grid[j][k]);
            k += 1;
        }
        let bottom_right_str: String = bottom_right.iter().collect();
        sum += re.find_iter(&bottom_right_str).count();

    }
    // Implement part 1 solution here
    sum
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


