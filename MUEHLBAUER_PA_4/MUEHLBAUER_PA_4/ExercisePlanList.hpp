#pragma once

#include <iostream>
#include <string>
#include <ostream>

#include "ExercisePlan.hpp"

using std::cin; // cin >> 
using std::cout; // cout <<
using std::endl; // endl
using std::ifstream;
using std::string;
using std::ofstream;


struct Node {
	ExercisePlan record;
	Node* next;

	Node();

	Node(const ExercisePlan& newrecord);
};

class ExercisePlanList
{

private:
	Node* head;
public:
	// constructor - default constructor
	ExercisePlanList();

	//void insertAtHead(const DietPlan record);
	void insertAtHead(const ExercisePlan& record);

	bool print();

	void storeFile(ofstream& fileStream);

	void editNode(int spot);

	bool checkEmpty();
};
