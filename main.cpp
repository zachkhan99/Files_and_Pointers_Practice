#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Function to find the maximum value in an array
float findMax(float * arr, int size) {
    float max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
float findMin(float * arr, int size) {
    float min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Bubble sort function to sort an array in ascending order
void bubbleSort(float * arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    ifstream studentsScores;                                                                // open input file for reading
    studentsScores.open("students_scores.txt");
    if (!studentsScores) {                                                                  // check if the file does not open
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    string studentName;                                                                     // declare string variable
    while (getline(studentsScores, studentName)) {                                          // loop to read student name
        cout << "Student " << studentName << " has ";

        getline(studentsScores, studentName);                                               // read line in file that has the grades
        stringstream ss(studentName);                                                       //stringstream object to parse grades line
        vector<float> grades;                                                               // store students grades in vector
        float grade;                                                                        // get the grade as a float
        while (ss >> grade) {
            if (grade < 0) {                                                                // detect invalid grades (neg values)
                cerr << "invalid grades, negative number detected: " << grade << endl;
                grades.clear();
                break;
            }
            
            grades.push_back(grade);                                                        // push the obtained grade into vector
            if (ss.peek() == ',') {                                                         // ignore commas
                ss.ignore();
            }
        }

        float * gradesArray = & grades[0];                             // create pointer to float "gradesArray" that points to data in grades vector
        int numGrades = grades.size();                                 // get number of grades in the grades vector and store it in numGrades

        try {                                                          // try-catch block for exceptions
            float maxGrade = findMax(gradesArray, numGrades);
            float minGrade = findMin(gradesArray, numGrades);

            cout << "a high score of " << maxGrade << " and a low score of " << minGrade << endl;

            bubbleSort(gradesArray, numGrades);
            cout << "Sorted Grades:";
            for (int i = 0; i < numGrades; i++) {
                cout << " " << gradesArray[i];
            }
            cout << "\n" <<endl;
        } catch (const invalid_argument & e) {                         // if invalid argument, print error message
            cerr << "Grades for student " << studentName << " are invalid, " << e.what() << endl;
        }
    }

    studentsScores.close();
    return 0;
}
