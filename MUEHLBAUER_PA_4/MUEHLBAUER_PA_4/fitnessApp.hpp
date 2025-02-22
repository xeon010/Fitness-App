#pragma once



#include <iostream>
#include <string>
#include <ostream>

#include "DietPlan.hpp"
#include "ExercisePlan.hpp"
#include "DietPlanList.hpp"
#include "ExercisePlanList.hpp"


using std::cin; // cin >> 
using std::cout; // cout <<
using std::endl; // endl
using std::ifstream;
using std::string;
using std::ofstream;
using std::cerr;


class FitnessAppWrapper
{
public:
	FitnessAppWrapper() = default;
	~FitnessAppWrapper() {};


	void runApp();

	bool displayMenu(DietPlanList &dietplanlist, ExercisePlanList &exerciseplanlist);
	bool menu();


private:

	bool loadDailyPlan(ifstream& fileStream, DietPlan &plan);
	bool loadDailyPlan(ifstream& fileStream, ExercisePlan& plan);

	bool loadWeeklyPlan(ifstream& fileStream, DietPlanList& plan);
	bool loadWeeklyPlan(ifstream& fileStream, ExercisePlanList& plan);

	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);

	void displayWeeklyPlan(DietPlanList& plan);
	void displayWeeklyPlan(ExercisePlanList& plan);

	bool storeDailyPlan(ofstream& fileStream, DietPlan& plan);
	bool storeDailyPlan(ofstream& fileStream, ExercisePlan& plan);

	bool storeWeeklyPlan(ofstream& fileStream, DietPlanList& plan);
	bool storeWeeklyPlan(ofstream& fileStream, ExercisePlanList& plan);

};
