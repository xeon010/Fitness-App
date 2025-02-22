#include "ExercisePlan.hpp"

ExercisePlan::ExercisePlan(int newSteps, string newName, string newDate)
{
	// if newSteps populated, update mGoalSteps, otherwise mGoalSteps = 0
	if (newSteps != NULL)
	{
		mGoalSteps = newSteps;
	}
	else
	{
		mGoalSteps = 0;
	}

	// if newname populated, update newname, otherwise newname set empty
	if (!newName.empty())
	{
		mName = newName;
	}
	else
	{
		mName = '\0';
	}

	// if newdate populated, update newdate, otherwise newdate set empty
	if (!newDate.empty())
	{
		mDate = newDate;
	}
	else
	{
		mDate = '\0';
	}
}

ExercisePlan::ExercisePlan(ExercisePlan& other)
{
	this->mGoalSteps = other.mGoalSteps;
	this->mDate = other.mDate;
	this->mName = other.mName;
}


int ExercisePlan::getSteps()
{
	return mGoalSteps;
}

string ExercisePlan::getName()
{
	return mName;
}

string ExercisePlan::getDate()
{
	return mDate;
}


void ExercisePlan::setSteps(int newSteps)
{
	// data validation
	if (newSteps >= 0)
	{
		mGoalSteps = newSteps;
	}
}


void ExercisePlan::setName(string newName)
{
	mName = newName;
}

void ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}

void ExercisePlan::editGoal()
{
	cout << "Enter new steps goal:" << endl;
	cin >> mGoalSteps;
	cin.get();
	cout << "Enter new plan name:" << endl;
	cin >> mName;
	cin.get();
	cout << "Enter date:" << endl;
	cin >> mDate;
	cin.get();
}

// overloaded operator - non-member
// cout
std::ostream& operator<< (std::ostream& lhs, ExercisePlan& rhs)
{
	lhs << "Name: " << rhs.getName() << " Steps: " << rhs.getSteps() << " Date: " << rhs.getDate();

	return lhs;
}

std::ofstream& operator<<(std::ofstream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getSteps() << endl << rhs.getName() << endl << rhs.getDate() << endl;
	return lhs;
}

// outfile
std::ifstream& operator>> (std::ifstream& lhs, ExercisePlan& rhs)
{

	string name;
	getline(lhs, name);
	rhs.setName(name);

	int steps;
	lhs >> steps;
	rhs.setSteps(steps);
	lhs.ignore();

	string date;
	getline(lhs, date);
	rhs.setDate(date);
	lhs.ignore();

	return lhs;
}
