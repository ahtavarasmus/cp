use std::{fs::read_to_string};

fn read_input(file_path: &str) -> String {
    read_to_string(file_path).unwrap().trim().to_string()
}

fn safe_report(report: Vec<i32>) -> bool {
    let mut prev: i32 = report[0];
    let mut safe: bool = true;
    let mut dir: i32 = -1; // decreasing = 0, rising = 1, not decided yet = -1
    for i in 1..report.len() {
        let diff: i32 = prev - report[i];
        if diff > 0 && dir == -1 {
            dir = 1;
        } else if diff < 0 && dir == -1 {
            dir = 0;
        } else if diff == 0 && dir == -1 {
            safe = false;
        }
        if (dir == 0 && diff >= 0) || (dir == 1 && diff <= 0) {
            safe = false;
        }
        if diff.abs() > 3 || diff.abs() < 1 {
            safe = false;
        }
        prev = report[i];
    }
    safe
}

fn part1(input: &str) -> i32 {
    // Implement part 1 solution here
    let mut safe_count: i32 = 0;
    let reports: Vec<Vec<i32>> = input.lines().map(|line: &str|
            line.split_whitespace().map(|num: &str| num.parse().unwrap()).collect()
        ).collect();
    for report in reports {
        if safe_report(report) {
            safe_count += 1;
        }
    }
    safe_count
}

fn part2(input: &str) -> i32 {
    // Implement part 2 solution here
    let mut safe_count: i32 = 0;
    let reports: Vec<Vec<i32>> = input.lines().map(|line: &str|
            line.split_whitespace().map(|num: &str| num.parse().unwrap()).collect()
        ).collect();
    for report in reports {
        let mut safe: bool = false;
        for i in 0..report.len() {
            let mut report1: Vec<i32> = report.clone();
            // removing index i from report1:
            report1.remove(i);
            if safe_report(report1) {
                safe = true;
                break;
            }
        }
        if safe {
            safe_count += 1;
        }
    }
    safe_count
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


