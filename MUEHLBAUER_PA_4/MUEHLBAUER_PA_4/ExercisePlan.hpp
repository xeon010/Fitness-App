#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin; // cin >> 
using std::cout; // cout <<
using std::endl; // endl
using std::ifstream;
using std::ofstream;
using std::string;


class ExercisePlan
{
public:
	// member functions - methods
	// constructor - default constructor
	ExercisePlan(int newSteps = 0, string newName = "", string newDate = "");

	// copy constructor
	ExercisePlan(ExercisePlan& other);

	// destructor
	~ExercisePlan()
	{}

	// getters - accessors
	int getSteps();
	string getName();
	string getDate();

	// setters - mutators
	void setSteps(int newSteps);
	void setName(string newName);
	void setDate(string newDate);
	void editGoal();
private:

	int mGoalSteps;
	string mName;
	string mDate;
};

// overloaded operator - non-member
// output stream
std::ostream& operator<< (std::ostream& lhs, ExercisePlan& rhs);

// outfile stream
std::ofstream& operator<< (std::ofstream& lhs, ExercisePlan& rhs);

// infile stream
std::ifstream& operator>> (std::ifstream& lhs, ExercisePlan& rhs);