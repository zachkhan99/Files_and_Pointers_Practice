# Student Grades Analysis Program

This C++ program analyzes student grades stored in a file named 'students_scores.txt'. It reads each student's name and corresponding grades, performs basic statistical analysis, and outputs the high and low scores for each student, along with a sorted list of grades.

## Usage

Input File: Ensure that there is a file named 'students_scores.txt' in the same directory as the executable. The file should contain the names of students followed by their grades, separated by commas.

Example:
```
John Doe
85, 90, 78, 92
Jane Smith
76, 88, 95, 82
```

## Functions
1. findMax Function
Description: Finds the maximum value in an array of grades.

3. findMin Function
Description: Finds the minimum value in an array of grades.

4. bubbleSort Function
Description: Sorts an array of grades in ascending order using the bubble sort algorithm.

5. Main Program
   * File Reading: Opens and reads the 'students_scores.txt' file, extracting student names and grades.
   * Data Validation: Checks for negative grades and handles invalid data gracefully.
   * Statistical Analysis: Calculates and displays the high and low scores for each student.
   * Sorting: Sorts and displays the grades in ascending order for each student.
   * Exception Handling: Uses try-catch blocks to handle potential exceptions, such as invalid grades.


## Notes
* Ensure that the input file ('students_scores.txt') follows the specified format for successful execution.
* Negative grades are treated as invalid, and an error message is displayed.
