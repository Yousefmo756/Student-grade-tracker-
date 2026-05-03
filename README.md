# Student Grade Tracker

A console-based grade tracking application written in C++. Developed as part of a Problem Solving course at Misr International University.

## What It Does

- Enter grades for up to 100 students across up to 7 subjects
- Automatically calculates the average grade per student
- Saves all grades and averages to a text file (`grade_tracker.txt`)
- Load and display previously saved grades at any time

## How It Works

The program runs as a menu-driven loop with three options:

1. **Add Grades** — prompts for student names and subject grades with input validation
2. **Show Saved Grades** — reads and displays the saved file
3. **Exit**

Grades are appended to the file each session, so previous records are preserved.

## Key Concepts Used

- **File I/O** — writing with `ofstream` (append mode) and reading with `ifstream`
- **2D arrays** — grades stored in a `student[100][7]` matrix
- **Input validation** — loops to reject invalid values (negative grades, out-of-range counts)
- **Modular functions** — separate functions for adding grades, calculating averages, saving, and loading

## Tech Stack

- C++
- Visual Studio
- Standard file streams (`fstream`)
