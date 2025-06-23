
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
	string name;
	string surname;
	int age;
	string number;
};

void addStudent(vector<Student>& students) {
	Student newStudent;
	cout << "Student Name: ";
	cin.ignore();
	getline(cin, newStudent.name);

	cout << "Student Surname: ";
	getline(cin, newStudent.surname);

	cout << "Student Age: ";
	cin >> newStudent.age;

	cout << "Student Number: ";
	cin >> newStudent.number;

	students.push_back(newStudent);
	cout << "The student has been added successfully." << endl << endl;
}

void listStudent(vector<Student>& students) {
	if (students.empty()) {
		cout << "There are no students registered!" << endl;
		return;
	}
	cout << "----Student List----" << endl << endl;
	for (int i = 0; i < students.size(); i++) {
		cout << i + 1 << "th student" << endl;
		cout << "Name: " << students[i].name << endl;
		cout << "Surname: " << students[i].surname << endl;
		cout << "Age: " << students[i].age << endl;
		cout << "Number: " << students[i].number << endl;
		cout << "----------------------------------------" << endl << endl << endl;
	}
}

void searchStudent(vector<Student>& students) {
	string number;
	cout << "The student number you want to call: ";
	cin >> number;
	cout << endl;
	bool found = false;

	for (auto& student : students) {
		if (student.number == number) {
			cout << "Student Found! " << endl;
			cout << "Name: " << student.name << endl;
			cout << "Surname: " << student.surname << endl;
			cout << "Age: " << student.age << endl;
			cout << "Number: " << student.number << endl;
			cout << endl;
			found = true;
			break;
		}
	} 
	if (!found) {
		cout << "Student Record not found!" << endl << endl;
	}

}

void deleteStudent(vector<Student>& students) {
	string number;
	cout << "Student number you want to delete: ";
	cin >> number;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].number == number) {
			students.erase(students.begin() + i);
			cout << "The student was successfully deleted." << endl << endl;
			return;
		}
	}
	cout << "Student Record not found!" << endl << endl;
}

int main(){
	vector<Student>students;
	int option = 0;
	while (option != 5) {
		cout << "-----Student Tracking System-----" << endl;
		cout << " 1 - Add Student " << endl;
		cout << " 2 - List Students " << endl;
		cout << " 3 - Search for Students " << endl;
		cout << " 4 - Delete Student " << endl;
		cout << " 5 - Exit " << endl;
		cout << "Your Choice : ";
		cin >> option;
		cout << endl;
		switch (option) {
		case 1:
			addStudent(students);
			break;

		case 2:
			listStudent(students);
			break; 

		case 3: 
			searchStudent(students);
			break;
		
		case 4:
			deleteStudent(students);
			break;

		case 5:
			cout << "Exiting...";
			break;
		default:
			cout << "You Made the Wrong Choice!" << endl;
		}

	}
}

