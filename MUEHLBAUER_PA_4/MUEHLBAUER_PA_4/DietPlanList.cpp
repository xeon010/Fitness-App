#include "DietPlanList.hpp"


Node1::Node1()
{

	next = nullptr;
}

Node1::Node1(const DietPlan& newrecord)
{

	this->record = newrecord;
	this->next = NULL;

}

DietPlanList::DietPlanList()
{

	head = NULL;

}

void DietPlanList::insertAtHead(const DietPlan& record)
{


	Node1* newNode = new Node1(record);

	if (head == NULL) {
		head = newNode;
		return;
	}

	newNode->next = this->head;
	this->head = newNode;

}

bool DietPlanList::print()
{

	Node1* temp = head;

	if (head == NULL)
	{
		cout << "List is empty." << endl;
		return 0;
	}

	cout << endl;
	int i = 7;

	while (temp != NULL)
	{
		cout << i << " " << temp->record << endl;
		temp = temp->next;
		i--;
	}
	return 1;
}

void DietPlanList::storeFile(ofstream& fileStream)
{
	Node1* temp = head;
	for (int i = 0; i < 7; i++)
	{
		fileStream << temp->record << endl;
		temp = temp->next;
	}
}

void DietPlanList::editNode(int spot)
{
	int index = 7;

	Node1* curr = head;

	while (spot != index && curr != NULL)
	{
		curr = curr->next;
		index--;
	}

	curr->record.editGoal();
}

bool DietPlanList::checkEmpty()
{
	
	Node1* curr = head;
	for (int i = 0; i < 7; i++)
	{
		if (curr == NULL) return 0;
		curr = curr->next;
	}

	return 1;
}
