#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int Max_studentnum = 100;
const int Max_subjectnum = 7;
int subject_Num = 0;
int student_Num = 0;

double average[Max_studentnum];

void addgrade(string names[Max_studentnum], int student[][Max_subjectnum], int& student_Num, int& subject_Num) {
    cout << "Enter number of students to grade (limit 100): ";
    cin >> student_Num;
    while (student_Num <= 0 || student_Num > Max_studentnum) {
        cout << "Please enter a number between 1 and 100: ";
        cin >> student_Num;
    }

    cout << "Enter number of subjects to grade: ";
    cin >> subject_Num;
    while (subject_Num <= 0 || subject_Num > Max_subjectnum) {
        cout << "Please enter a number between 1 and 7: ";
        cin >> subject_Num;
    }

    for (int i = 0; i < student_Num; i++) {
        cout << "\nEnter name for student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, names[i]);

        cout << "Grades for student " << names[i] << ":\n";
        for (int j = 0; j < subject_Num; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin >> student[i][j];
            while (student[i][j] < 0) {
                cout << "Invalid input! Enter a non-negative number: ";
                cin >> student[i][j];
            }
        }
        cout << "Grades entered successfully.\n";
    }
}

void calc_avg(int student[][Max_subjectnum], int student_Num, int subject_Num) {
    for (int i = 0; i < student_Num; i++) {
        int sum = 0;
        for (int j = 0; j < subject_Num; j++) {
            sum += student[i][j];
        }
        average[i] = static_cast<double>(sum) / subject_Num;
    }
}

void show_grade(string names[], int student[][Max_subjectnum], int student_Num, int subject_Num) {
    ofstream output("grade_tracker.txt", ios::app);
    if (output.fail()) {
        cout << "Error opening file!";
        return;
    }

    for (int i = 0; i < student_Num; i++) {
        bool gradesEntered = false;
        output << "\n------------------------------\n";
        output << "Grades for " << names[i] << ":\n";
        for (int j = 0; j < subject_Num; j++) {
            output << "Subject " << j + 1 << ": " << student[i][j] << endl;
            if (student[i][j] != 0) {
                gradesEntered = true;
            }
        }
        if (!gradesEntered) {
            cout << "Error: No grades entered! Please add grades first.\n";
            return;
        }
        else {
            output << "Average: " << average[i] << endl;
        }
    }

    output.close();
    cout << "\nGrades saved to 'grade_tracker.txt'.\n";
}

void loadGrades() {
    ifstream input("grade_tracker.txt");
    if (input.fail()) {
       
        cout << "No saved grade file found.\n";
        return;
    }

    string line;
    cout << "\n--- Loaded Grades ---\n";
    while (getline(input, line)) {
        cout << line << endl;
    }
    input.close();
}

int main() {
    string names[Max_studentnum];
    int student[Max_studentnum][Max_subjectnum] = { 0 };
    int choice;

    while (true) {
        cout << "\n =============================\n";
        cout << "|      Grade Tracker Menu     |\n";
        cout << "|-----------------------------|\n";
        cout << "| 1. Add Grades               |\n";
        cout << "| 2. Show Saved Grades & Avg  |\n";
        cout << "| 3. Exit Program             |\n";
        cout << " =============================\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
        case 1:
            addgrade(names, student, student_Num, subject_Num);
            calc_avg(student, student_Num, subject_Num);
            show_grade(names, student, student_Num, subject_Num);
            break;
        case 2:
            loadGrades();
            break;
        case 3:
            cout << "Exiting program.......\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}