#pragma once

#include <iostream>
#include <string>
#include <ostream>

#include "DietPlan.hpp"

using std::cin; // cin >> 
using std::cout; // cout <<
using std::endl; // endl
using std::ifstream;
using std::string;
using std::ofstream;


struct Node1 {


	DietPlan record;
	Node1* next;

	Node1();

	Node1(const DietPlan& newrecord);
};


class DietPlanList
{

private:
	Node1* head;
public:
	// constructor - default constructor
	DietPlanList();

	//void insertAtHead(const DietPlan record);
	void insertAtHead(const DietPlan& record);

	bool print();

	void storeFile(ofstream& fileStream);

	void editNode(int spot);

	bool checkEmpty();
};
