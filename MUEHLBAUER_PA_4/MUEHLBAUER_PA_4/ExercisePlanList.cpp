#include "ExercisePlanList.hpp"


Node::Node()
{

	next = nullptr;
}

Node::Node(const ExercisePlan& newrecord)
{

	this->record = newrecord;
	this->next = NULL;

}

ExercisePlanList::ExercisePlanList()
{

	head = NULL;

}

void ExercisePlanList::insertAtHead(const ExercisePlan& record)
{


	Node* newNode = new Node(record);

	if (head == NULL) {
		head = newNode;
		return;
	}

	newNode->next = this->head;
	this->head = newNode;

}

bool ExercisePlanList::print()
{

	Node* temp = head;

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

void ExercisePlanList::storeFile(ofstream& fileStream)
{
	Node* temp = head;
	for (int i = 0; i < 7; i++)
	{
		fileStream << temp->record << endl;
		temp = temp->next;
	}
}

void ExercisePlanList::editNode(int spot)
{
	int index = 7;

	Node* curr = head;

	while (spot != index && curr != NULL)
	{
		curr = curr->next;
		index--;
	}

	curr->record.editGoal();
}

bool ExercisePlanList::checkEmpty()
{
	Node* curr = head;
	for (int i = 0; i < 7; i++)
	{
		if (curr == NULL) return 0;
		curr = curr->next;
	}

	return 1;
}
