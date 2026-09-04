#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==============================
// Course Class
// ==============================

class Course
{
private:
    string name;
    int difficulty;
    double studyHours;
    double grade;

public:

    Course(string n, int d, double h, double g)
    {
        name = n;
        difficulty = d;
        studyHours = h;
        grade = g;
    }

    string getName() const
    {
        return name;
    }

    int getDifficulty() const
    {
        return difficulty;
    }

    double getStudyHours() const
    {
        return studyHours;
    }

    double getGrade() const
    {
        return grade;
    }
};

// ==============================
// Add Course
// ==============================

void addCourse(vector<Course>& courses)
{
    string name;
    int difficulty;
    double studyHours;
    double grade;

    cout << "\nEnter course name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter difficulty (1-5): ";
    cin >> difficulty;

    cout << "Enter study hours per week: ";
    cin >> studyHours;

    cout << "Enter grade: ";
    cin >> grade;

    Course newCourse(name, difficulty, studyHours, grade);

    courses.push_back(newCourse);

    cout << "\nCourse added successfully!\n";
}


// ==============================
// Show Courses
// ==============================

void showCourses(const vector<Course>& courses)
{
    if (courses.empty())
    {
        cout << "\nThere are no courses.\n";
        return;
    }

    cout << "\n========== All Courses ==========\n";

    for (int i = 0; i < courses.size(); i++)
    {
        cout << "\nCourse #" << i + 1 << endl;
        cout << "Name: " << courses[i].getName() << endl;
        cout << "Difficulty: "
            << courses[i].getDifficulty()
            << "/5" << endl;

        cout << "Study Hours: "
            << courses[i].getStudyHours()
            << endl;

        cout << "Grade: "
            << courses[i].getGrade()
            << endl;
    }
}


// ==============================
// Average Grade
// ==============================

double calculateAverageGrade(const vector<Course>& courses)
{
    if (courses.empty())
    {
        return 0;
    }

    double total = 0;

    for (int i = 0; i < courses.size(); i++)
    {
        total += courses[i].getGrade();
    }

    return total / courses.size();
}


// ==============================
// Average Study Hours
// ==============================

double calculateAverageStudyHours(const vector<Course>& courses)
{
    if (courses.empty())
    {
        return 0;
    }

    double total = 0;

    for (int i = 0; i < courses.size(); i++)
    {
        total += courses[i].getStudyHours();
    }

    return total / courses.size();
}


// ==============================
// Average Difficulty
// ==============================

double calculateAverageDifficulty(const vector<Course>& courses)
{
    if (courses.empty())
    {
        return 0;
    }

    double total = 0;

    for (int i = 0; i < courses.size(); i++)
    {
        total += courses[i].getDifficulty();
    }

    return total / courses.size();
}


// ==============================
// Find Best Course
// ==============================

void findBestCourse(const vector<Course>& courses)
{
    if (courses.empty())
    {
        cout << "\nThere are no courses.\n";
        return;
    }

    int bestIndex = 0;

    for (int i = 1; i < courses.size(); i++)
    {
        if (courses[i].getGrade() >
            courses[bestIndex].getGrade())
        {
            bestIndex = i;
        }
    }

    cout << "\n========== Best Course ==========\n";

    cout << "Name: "
        << courses[bestIndex].getName()
        << endl;

    cout << "Grade: "
        << courses[bestIndex].getGrade()
        << endl;
}


// ==============================
// Find Hardest Course
// ==============================

void findHardestCourse(const vector<Course>& courses)
{
    if (courses.empty())
    {
        cout << "\nThere are no courses.\n";
        return;
    }

    int hardestIndex = 0;

    for (int i = 1; i < courses.size(); i++)
    {
        if (courses[i].getDifficulty() >
            courses[hardestIndex].getDifficulty())
        {
            hardestIndex = i;
        }
    }

    cout << "\n========== Hardest Course ==========\n";

    cout << "Name: "
        << courses[hardestIndex].getName()
        << endl;

    cout << "Difficulty: "
        << courses[hardestIndex].getDifficulty()
        << "/5"
        << endl;
}


// ==============================
// Show Statistics
// ==============================

void showStatistics(const vector<Course>& courses)
{
    if (courses.empty())
    {
        cout << "\nThere are no courses.\n";
        return;
    }

    cout << fixed << setprecision(2);

    cout << "\n========== Statistics ==========\n";

    cout << "Average Grade: "
        << calculateAverageGrade(courses)
        << endl;

    cout << "Average Study Hours: "
        << calculateAverageStudyHours(courses)
        << endl;

    cout << "Average Difficulty: "
        << calculateAverageDifficulty(courses)
        << endl;
}


// ==============================
// Main
// ==============================

int main()
{
    vector<Course> courses;

    int choice;

    do
    {
        cout << "\n\n";
        cout << "====================================\n";
        cout << "   UNIVERSITY COURSE ANALYZER\n";
        cout << "====================================\n";

        cout << "1. Add Course\n";
        cout << "2. Show All Courses\n";
        cout << "3. Show Statistics\n";
        cout << "4. Find Best Course\n";
        cout << "5. Find Hardest Course\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addCourse(courses);
            break;

        case 2:
            showCourses(courses);
            break;

        case 3:
            showStatistics(courses);
            break;

        case 4:
            findBestCourse(courses);
            break;

        case 5:
            findHardestCourse(courses);
            break;

        case 6:
            cout << "\nProgram ended.\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}