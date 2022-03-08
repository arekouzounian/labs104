#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(std::string name) {
	mName = name;
}

std::string Person::getName() {
	return mName;
}

Professor::Professor(std::string name, std::string department) : Person(name) {
	//mName = name;
}

std::string Professor::getDepartment() {
	return mDepartment;
}

Student::Student(std::string name, std::string major) : Person(name) {
	//mName = name;
	mMajor = major;
}

void Student::setGPA(double gpa) {
	mGpa = gpa;
}

std::string Student::getMajor() {
	return mMajor;
}

UscStudent::UscStudent(std::string name, std::string major, double gpa) : Student(name, major) {
	//mName = name;
	//mMajor = major;
	setGPA(gpa);
}

void UscStudent::printTranscript() {
	// TO DO: fill in
	cout << "----Student Transcript----" << endl;
	cout << "Name: " << mName << endl;
	cout << "GPA: " << mGpa << endl;
	cout << "Major: " << mMajor << endl;
	cout << "----End of Transcript----" << endl;
}