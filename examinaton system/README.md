# Examination System in C

This is an examination system implemented in C programming language, designed to facilitate the management of tests, student accounts, and results. The system includes functionality for both students and teachers, allowing teachers to create tests and students to view and attempt them. After completing the test, students can view their results.

login details : -
for admin login <br>
username : admin ,
password : admin@123

for candidate login<br>
email : guest@gmail.com ,
password : guest

## Features

### For Teachers:
- **Teacher Login**: Teachers can log in to their accounts using a username and password.
- **Create Test**: Teachers have the ability to create tests by specifying the test name, duration, and questions along with options and correct answers.
- **Manage Tests**: Teachers can view, edit, or delete tests they have created.

### For Students:
- **Student Login**: Students can log in to their accounts using a username and password.
- **View Tests**: Students can view the tests created by teachers and available for them to attempt.
- **Attempt Test**: Students can attempt the test by answering the questions within the specified duration.
- **View Results**: After completing the test, students can view their results showing the score and correct/incorrect answers.

## Implementation Details

- **Data Storage**: Data such as student accounts, teacher accounts, tests, and results can be stored in files or databases.
- **User Authentication**: Authentication mechanisms are implemented to ensure secure access to teacher and student accounts.
- **Test Generation**: Tests are generated dynamically based on the input provided by teachers.
- **Timer**: A timer feature is implemented to enforce the test duration.
- **Scoring**: Scoring mechanism is implemented to calculate the student's score based on the answers provided.

## Usage

1. Compile the code using a C compiler.
2. Run the compiled executable file.
3. Log in as a teacher or student using the provided credentials.
4. Teachers can create tests, while students can view and attempt tests.
5. After attempting the test, students can view their results.

## Note

- This system is designed for educational purposes and may lack advanced features such as user interfaces or database integration.
- It is recommended to use this system in a controlled environment for learning and practice purposes only.

## Disclaimer

This examination system is developed for educational purposes and may not have robust security features or scalability for real-world use. Use it responsibly and adhere to academic integrity guidelines when using it for educational purposes.

