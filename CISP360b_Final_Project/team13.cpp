//CISP360
//T/TH 1:30-2:50pm
//Spring 2017
//Team 13 Project: Dynamic Study Guide and Random Question Generator for C++
//Write a program for students to study C++ and for instructors to see how 
//well the students are learning C++.

//team13.cpp

#include <iostream>  //cout, cin
#include <cstdlib>   //srand, rand
#include <string>    //string
#include <fstream>   //ifstream
#include <vector>    //vector
#include <algorithm> //swap 
#include <iomanip>   //setw, setprecision

using namespace std;

//Prototypes
void inputValue(string, char &);
void inputStudentID(vector<string>, string);
void valInput(char &);
void selSubject(int &);
void valYesNo(char &);
void openFiles();

int main()
{
	string studentID;
	int subject;  //Select Subject
	vector<string> studentVector;

	char yesno,   //Select Y for Yes or N for No
		stuIn;	  //S for Student or I for Instructor 

	inputValue("Are you a student or instructor? Select S for Student or I for Instructor?", stuIn);
	valInput(stuIn);

	if (stuIn == 'S')
	{
		do {
			inputStudentID(studentVector, studentID);
			cout << "Do something here - Display current Status - % correct in each area of study" << endl;
			selSubject(subject);

			cout << "Do something here - Grade Test" << endl;
			cout << "Display Test Name: Area of Study, Date, % incorrect" << endl;
			inputValue("Would you like to study more questions?", yesno);
			valYesNo(yesno);
		} while (yesno == 'Y'); //Continue while Yes
	}
	else
	{
		do {
			cout << "Do something here - Display report variables: Student ID, Area of Study, Date" << endl;
			cout << "Do something here - Display sort order options based on selected report variables" << endl;
			cout << "Do something here - Generate report" << endl;
			cout << "Do something here - Display report" << endl;
			inputValue("Would you like to view another report?", yesno);
			valYesNo(yesno);
		} while (yesno == 'Y'); //Continue while Yes
	}
	system("pause");
	return 0;
}

//*************************************************************
// Definition of function getYesNo.                           *
// This function validates for a Y for Yes or N for No answer *
//*************************************************************
void valYesNo(char &answer)
{
	do {
		cout << endl;
		//convert lower case to upper case
		if (answer == 'y') {
			answer = 'Y';
		}
		else if (answer == 'n') {
			answer = 'N';
		}
		if (answer != 'Y' && answer != 'N') {
			cout << "Please enter Y for yes or N for N: ";
		}
	} while (answer != 'Y' && answer != 'N');
}
//*************************************************************
// Definition of function getChar. This function validates for*
// an S for Student or I for Instructor answer                *
//*************************************************************
void valInput(char &answer)
{
	do {
		cout << endl;
		//convert lower case to upper case
		if (answer == 's') {
			answer = 'S';
		}
		else if (answer == 'i') {
			answer = 'I';
		}
		if (answer != 'S' && answer != 'I') {
			cout << "Please enter S for student or I for instructor: ";
			cin >> answer;
		}
	} while (answer != 'S' && answer != 'I');
}
//*************************************************************
// Definition of function inputValue.                         *
//  This function displays query and accepts input value      *
//*************************************************************
void inputValue(string description, char &value)
{
	cout << description << endl;
	cin >> value;
}

//*************************************************************
// Definition of function inputStudentID.                     *
// This function displays query and accepts input value for   *
// student ID                                                 *
//*************************************************************
void inputStudentID(vector<string> v, string id)
{
	cout << "Enter ID: ";
	cin >> id;
	v.push_back(id);
}

//*************************************************************
// Definition of function createTest.                         *
// This function randomly generates a list of 10 questions for*
// area of study selected                                     *
//*************************************************************

void selSubject(int &choice)
{
	do {
		cout << "        Subject Menu" << endl;
		cout << "------------------------------" << endl;
		cout << "1. Arrays" << endl;
		cout << "2. Pointers" << endl;
		cout << "3. Vectors" << endl;
		cout << "4. Any" << endl;
		cout << "5. Quit this progam" << endl;
		cout << "------------------------------" << endl;
		cout << "Enter your choice (1-5): ";
		cin >> choice;
		while (cin.fail()) {                      // If cin fails to receive a value matching the declared data type.
			cout << "Data Type not permitted.\n"; // Notify the user of error.
			cin.clear();                          // Clear the error flag within cin.
			cin.ignore(10000, '\n');              // Ignore the newline character in the buffer to prevent an infinite loop.
		}
		while (choice > 5 || choice < 1) //Validate entry for number within 1-5 range
		{
			cout << "The valid choices are 1, 2, 3, 4, and 5. Please choose: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			openFiles();
		}
		else if (choice == 2)
		{
			openFiles();
		}
		else if (choice == 3)
		{
			openFiles();
		}
		else if (choice == 4)
		{
			openFiles();
		}

	} while (choice != 5); //If 5 selected exit program
}

//*************************************************************
// Definition of function openFiles. This function opens files*
// for questions and answers                                  *
//*************************************************************
void openFiles()
{
	const int NUM_QUESTIONS = 50;
	const int NUM_ASKED = 10;

	ifstream fin("questions.txt");
	if (!fin)
		cout << "Error in opening questions.txt file";

	vector<string> questions;
	string line;
	while (getline(fin, line))
		questions.push_back(line);

	ifstream fin2("answers.txt");
	if (!fin2)
		cout << "Error in opening answers.txt file";

	vector<string> answers;
	string tf;
	while (getline(fin2, tf))
		answers.push_back(tf);



	string inp;
	int count = 0;
	int r;
	int remaining = NUM_QUESTIONS;
	double score = 0;

	cout << "\nEnter 'True' or 'False'. Press enter for next question. \n\n";
	while (count != NUM_ASKED) {
		srand(time_t(0));
		//srand((unsigned int)time_t(NULL));
		cin.ignore(10000, '\n');              // Ignore the newline character in the buffer to prevent an infinite loop.
		
		// Random numbers divided into 'remaining' buckets, instead of using rand() % remaining.
		// Adding 'count' pushes the random number past the range of already-used questions and answers
		r = count + (int)(remaining * rand() / (RAND_MAX + 1.0));
		//r = rand() % 50;         //Create random number 1 max 50

		/* Ask a question... */
		cout << questions[r] << endl;
		/* Get an answer! */
		getline(cin, inp);

		if (inp == answers[r]) {
			cout << "Correct!\n";
			score += 1;
		}
		else {
			cout << "Incorrect.\n";
		}

		questions[r].swap(questions[count]);
		answers[r].swap(answers[count]);
		count += 1;
		remaining -= 1;
	}
	fin.close();
	fin2.close();
	double correct = score / NUM_ASKED;
	cout << "\nYour score is " << right << fixed << setprecision(0) << correct *100 << "%.\n\n";
}