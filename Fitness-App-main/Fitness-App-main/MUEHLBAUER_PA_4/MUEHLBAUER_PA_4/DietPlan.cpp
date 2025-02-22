#pragma once
#include "DietPlan.hpp"

DietPlan::DietPlan(int newCals, string newName, string newDate)
{
	// if newCals populated, update mCals, otherwise mCals = 0
	if (newCals != NULL)
	{
		mCalories = newCals;
	}
	else
	{
		mCalories = 0;
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

DietPlan::DietPlan(DietPlan& other)
{
	this->mCalories = other.mCalories;
	this->mDate = other.mDate;
	this->mName = other.mName;
}


int DietPlan::getCals()
{
	return mCalories;
}

string DietPlan::getName()
{
	return mName;
}

string DietPlan::getDate()
{
	return mDate;
}


void DietPlan::setCals(int newCals)
{
	// data validation
	if (newCals >= 0)
	{
		mCalories = newCals;
	}
}


void DietPlan::setName(string newName)
{
	mName = newName;
}

void DietPlan::setDate(string newDate)
{
	mDate = newDate;
}

void DietPlan::editGoal()
{
	cout << "Enter new calorie goal:" << endl;
	cin >> mCalories;
	cin.get();
	cout << "Enter new plan name:" << endl;
	cin >> mName;
	cin.get();
	cout << "Enter date:" << endl;
	cin >> mDate;
	cin.get();
}

// overloaded operator - non-member
std::ostream& operator<< (std::ostream& lhs, DietPlan &rhs)
{
	lhs << "Name: " << rhs.getName() << " Calories: " << rhs.getCals() << " Date: " << rhs.getDate();

	return lhs;
}

std::ofstream& operator<<(std::ofstream& lhs, DietPlan& rhs)
{
	lhs << rhs.getCals() << endl << rhs.getName() << endl << rhs.getDate() << endl;
	return lhs;
}

std::ifstream& operator>> (std::ifstream& lhs, DietPlan& rhs)
{
	//lhs.ignore();
	string name;
	getline(lhs, name);
	rhs.setName(name);

	int cals;
	lhs >> cals;
	rhs.setCals(cals);
	lhs.ignore();

	string date;
	getline(lhs, date);
	rhs.setDate(date);
	lhs.ignore();

return lhs;
}