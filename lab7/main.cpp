#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <string>
#include "main.h"



using namespace std;

string GetStudentName() {
    string name;
    cout << "Enter your second name here: ";
    cin >> name;
    cout << endl;
    return name;
}
string GetStudentgroupNumber() {
    string groupnumber;
    cout << "Enter your group number here: ";
    cin >> groupnumber;
    cout << endl;
    return groupnumber;
}

void PrintMenu() {
    cout << "Select the point you need:\n";
    cout << "1. Start test\n";
    cout << "2. Get info about the test\n";
    cout << "3. Watch results of the test\n";
    cout << "4. Change your name and group\n";
    cout << "5. Exit\n";
}

void GetInfoAboutTest() {
    cout << "This test will check your knowledge\n";
    cout << "of programming in the C-language.\n";
    cout << "You need just to choose the variant,\n";
    cout << "you think is right. You have unlimited time.\n";
}

class Question {
public:
    string question;
    string variant1;
    string variant2;
    string variant3;
    int rightVariant;
    enum variant {
        first,
        second,
        third,
    };
    variant yourAnswer;
    int yourScore;
    Question(string question, string variant1, string variant2, string variant3, int rightVariant) {
        this->question = question;
        this->variant1 = variant1;
        this->variant2 = variant2;
        this->variant3 = variant3;
        this->rightVariant = rightVariant;
        this->yourScore = 0;

    }
    void PrintQuestion() {
        system("cls");
        cout << "============================================\n" << question <<"\n============================================\n" << "\n1. " << variant1 << "\n2. " << variant2 << "\n3. " << variant3 <<endl;
    }
    void EnterAndCheck() {
        int answer;
        cin >> answer;
        switch (answer) {
        case 1: 
            yourAnswer = first;
            if (rightVariant == 1) {
                yourScore += 10;
            }
            break;
        case 2: 
            yourAnswer = second;
            if (rightVariant == 2) {
                yourScore += 10;
            }          
            break;
        case 3: 
            yourAnswer = third;
            if (rightVariant == 3) {
                yourScore += 10;
            }
            break;
        default: 
            cout << "Wrong point" << "\nPress any button to try again";;
            _getch();
            PrintQuestion();
            EnterAndCheck();
            break;
        }
    }
};

int test() {
    cout << "Okay, good luck";
    _getch();
    int scores = 0;
    Question Q1("What was the C programming language initially designed for ?", "website development", "operating system development", "graphics", 2);
    Q1.PrintQuestion();
    Q1.EnterAndCheck();
    system("cls");
    Question Q2("Which of the following are valid data types in C?", "int, float, string, char","int, double, char, boolean", "int, float, double, char", 3);
    Q2.PrintQuestion();
    Q2.EnterAndCheck();
    system("cls");
    Question Q3("How to declare an integer variable num and assign it the value 9 ?", "int num = 9;", "int num := 9;", "int num == 9;", 1);
    Q3.PrintQuestion();
    Q3.EnterAndCheck();
    system("cls");
    Question Q4("Every C programm starts with a function:", "main", "#include", "int()", 1);
    Q4.PrintQuestion();
    Q4.EnterAndCheck();
    system("cls");
    Question Q5("When the c programming language was appeared?", "2000", "1972", "1763", 2);
    Q5.PrintQuestion();
    Q5.EnterAndCheck();
    system("cls");
    scores = Q1.yourScore + Q2.yourScore + Q3.yourScore + Q4.yourScore + Q5.yourScore;
    cout << "Your total score is " << scores << " of 50\n" << "Press any button to enter main menu";
    _getch();
    system("cls");
    return scores;
}

int main()
{
    cout << "Hello, welcome to the C-programming test\n" << "Press any key to continue\n";
    _getch();
    system("cls");
    string name = GetStudentName();
    string group = GetStudentgroupNumber();


    system("cls");
    int button;
    int scores;
    while (true) {
        ofstream outResults;
        ifstream inResults("results.txt");
        string line;
        system("cls");
        cout << "Name: " << name << "\nGroup: " << group << endl << endl;

        PrintMenu();
        cin >> button;
        switch (button) {
        case 1:
            system("cls");
            scores = test();
            outResults.open("results.txt", ios::app);
            time_t t;
            time(&t);
            outResults << ctime(&t) << " " << group << " " << name << " " << scores << "\n\n";
            break;
        case 2:
            system("cls");
            GetInfoAboutTest();
            cout << "Press any button to enter main menu";
            _getch();
            system("cls");
            break;
        case 3:
            system("cls");
            if (inResults.is_open()) {
                while (getline(inResults, line)) {
                    cout << line << endl;
                }
                _getch();
                system("cls");
            }
            break;
        case 4:
            system("cls");
            name = GetStudentName();
            group = GetStudentgroupNumber();
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "Really? (Write Y if yes or another letter if no)\n";
            char d;
            cin >> d;
            if (d == 'Y' || d == 'y') {
                exit(0);
            }
            else {
                break;
            }
        default:
            system("cls");
            cout << "There is no such point\n";
            _getch();

        }
    }

}