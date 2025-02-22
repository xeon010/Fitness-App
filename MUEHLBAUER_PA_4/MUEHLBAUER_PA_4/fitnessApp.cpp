#pragma once

#include "fitnessApp.hpp"

void FitnessAppWrapper::runApp()
{

	/*
	utilized two linked lists for data
	*/

	DietPlanList dietplanlist;
	ExercisePlanList exerciseplanlist;

	// runs until exit case
	while (displayMenu(dietplanlist, exerciseplanlist))
	{}

}

bool FitnessAppWrapper::displayMenu(DietPlanList& dietplanlist, ExercisePlanList& exerciseplanlist)
{
	int choice = 0;

	system("cls");

	while (choice < 1 || choice > 9)
	{
		cout << "FITNESS TRACKER\n\n";
		cout << "Please select one of the following options\n";
		cout << "1. Load weekly diet plan from file\n";
		cout << "2. Load weekly exercise plan from file\n";
		cout << "3. Store weekly diet plan to file\n";
		cout << "4. Store weekly exercise plan to file\n";
		cout << "5. Display weekly diet plan to screen\n";
		cout << "6. Display weekly exercise plan to screen\n";
		cout << "7. Edit daily diet plan\n";
		cout << "8. Edit daily exercise plan\n";
		cout << "9. Exit\n"; // write most recent weekly plans to files

		cin >> choice;

		// if user enters a char instead of int
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("cls");
			cerr << "Invalid selection.\n";
		}

		// if user enters int outside of bounds
		if (choice < 1 || choice > 9)
		{
			system("cls");
			cerr << "Invalid selection.\n";
		}
		
	}


	// switch statement- each case matches unique option selection
	switch (choice)
	{
	case 1:
	{
		// check if data has already been loaded in
		if (dietplanlist.checkEmpty())
		{
			cout << "Already loaded in data!\n";
			system("Pause");
			break;
		}

		ifstream fileStream("dietPlans.txt");
		if (fileStream.is_open())
		{
			loadWeeklyPlan(fileStream, dietplanlist);
			cout << "Sucessfully loaded data from file!\n";
		}
		else
		{
			cerr << "Failed to open file!\n";
		}
		fileStream.close();
		system("Pause");
		break;
	}
	case 2:
	{
		// check if data has already been loaded in
		if (exerciseplanlist.checkEmpty())
		{
			cout << "Already loaded in data!\n";
			system("Pause");
			break;
		}

		ifstream fileStream("exercisePlans.txt");
		if (fileStream.is_open())
		{
			loadWeeklyPlan(fileStream, exerciseplanlist);
			cout << "Sucessfully loaded data from file!\n";
		}
		else
		{
			cerr << "Failed to open file!\n";
		}
		fileStream.close();
		system("Pause");
		break;
	}
	case 3:
	{
		ofstream fileStream("dietPlansOut.txt");
		if (fileStream.is_open())
		{
			storeWeeklyPlan(fileStream, dietplanlist);
			cout << "Sucessfully stored data to file!\n";
		}
		else
		{
			cerr << "Failed to open file!\n";
		}
		fileStream.close();
		system("Pause");
		break;
	}
	case 4:
	{
		ofstream fileStream("exercisePlansOut.txt");
		if (fileStream.is_open())
		{
			if (storeWeeklyPlan(fileStream, exerciseplanlist))
			{
				cout << "Sucessfully stored data to file!\n";
			}
			else
			{
				cerr << "Failed to store data to file!\n";
			}
		}
		else
		{
			cerr << "Failed to open file!\n";
		}
		fileStream.close();
		system("Pause");
		break;
	}
	case 5:
	{
		displayWeeklyPlan(dietplanlist);
		system("Pause");
		break;
	}
	case 6:
		displayWeeklyPlan(exerciseplanlist);
		system("Pause");
		break;
	case 7:
	{
		cout << "Which entry would you like to edit?\n";
		if (!dietplanlist.print())
		{
			system("Pause");
			break;
		}

		int entry = 0;
		cin >> entry;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("cls");
			cerr << "Invalid selection.\n";
		}

		if (entry < 1 || entry > 7)
		{
			system("cls");
			cerr << "Invalid selection.\n";
			system("Pause");
			entry = 0;
			break;
		}

		dietplanlist.editNode(entry);

		break;
	}
	case 8:
	{
		cout << "Which entry would you like to edit?\n";
		if (!exerciseplanlist.print())
		{
			system("Pause");
			break;
		}

		int entry = 0;
		cin >> entry;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("cls");
			cerr << "Invalid selection.\n";
		}

		if (entry < 1 || entry > 7)
		{
			system("cls");
			cerr << "Invalid selection.\n";
			system("Pause");
			entry = 0;
			break;
		}

		exerciseplanlist.editNode(entry);

		break;
	}
	case 9:
	{
		if (!dietplanlist.checkEmpty())
		{
			if (!exerciseplanlist.checkEmpty())
			{
				cerr << "Failed to print to diet and exercise plan outfiles. Exiting application...\n";
				system("Pause");
				return 0;
			}
			else
			{
				cerr << "Failed to print to diet plan outfile.\n"; // print just the exercise plan

				ofstream fileStream1("exercisePlansOut.txt");
				storeWeeklyPlan(fileStream1, exerciseplanlist);
				fileStream1.close();

				cout << "Stored data to exercise plan outfile. Exiting application...\n";

				system("Pause");
				return 0;
			}
		}
		if (!exerciseplanlist.checkEmpty())
		{
			cerr << "Failed to print to exercise plan outfile.\n";

			ofstream fileStream2("dietPlansOut.txt");
			storeWeeklyPlan(fileStream2, dietplanlist);
			fileStream2.close();

			cout << "Stored data to diet plan outfile. Exiting application...\n";

			system("Pause");
			return 0;
		}
		ofstream fileStream1("exercisePlansOut.txt");
		ofstream fileStream2("dietPlansOut.txt");

		storeWeeklyPlan(fileStream1, exerciseplanlist);
		storeWeeklyPlan(fileStream2, dietplanlist);

		fileStream1.close();
		fileStream2.close();

		cout << "Exiting application and writing to outfiles...\n";

		system("Pause");
		return 0;
	}
	}

	return 1;
}

bool FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
	return 1;
}

bool FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
	return 1;
}

bool FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, DietPlanList& plan)
{
	for (int i = 0; i < 7; i++)
	{
		DietPlan diet;
		fileStream >> diet;
		plan.insertAtHead(diet);
	}
	return 1;
}

bool FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, ExercisePlanList& plan)
{
	for (int i = 0; i < 7; i++)
	{
		ExercisePlan exercise;
		fileStream >> exercise;
		plan.insertAtHead(exercise);
	}
	return 1;
}

void FitnessAppWrapper::displayDailyPlan(DietPlan& plan)
{
	cout << plan;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlanList& plan)
{
	plan.print();
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlanList& plan)
{
	plan.print();
}

bool FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, DietPlan& plan)
{
	if (fileStream.is_open())
	{
		fileStream << plan << endl;
	}
	return 1;
}

bool FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, ExercisePlan& plan)
{
	if (fileStream.is_open())
	{
		fileStream << plan << endl;
	}
	return 1;
}

bool FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, DietPlanList& plan)
{
	plan.storeFile(fileStream);
	return 1;
}

bool FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, ExercisePlanList& plan)
{
	plan.storeFile(fileStream);
	return 1;
}


