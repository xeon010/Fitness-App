#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using std::cin; // cin >> 
using std::cout; // cout <<
using std::endl; // endl
using std::ifstream;
using std::ofstream;
using std::string;




class DietPlan
{
public:
	// member functions - methods
	// constructor - default constructor
	DietPlan(int newCals = 0, string newName = "", string newDate = "");

	// copy constructor
	DietPlan(DietPlan& other);

	// destructor - invoked when DietPlan object goes out of scope
	~DietPlan()
	{}

	// getters - accessors
	int getCals();
	string getName();
	string getDate();

	// setters - mutators
	void setCals(int newCals);
	void setName(string newName);
	void setDate(string newDate);

	void editGoal();

private:
	// data members
	int mCalories;
	string mName;
	string mDate;

};

// overloaded operator - non-member

// output stream
std::ostream& operator<< (std::ostream& lhs, DietPlan& rhs);

// outfile stream
std::ofstream& operator<< (std::ofstream& lhs, DietPlan& rhs);

// infile stream
std::ifstream& operator>> (std::ifstream& lhs, DietPlan& rhs);