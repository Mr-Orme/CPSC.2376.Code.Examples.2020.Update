#include <iostream>
using namespace std;

struct node
{
	int data{ 0 };
	std::shared_ptr<node> next{ nullptr };
	std::shared_ptr<node> prev{ nullptr };
};
//add item at certain place in list, returns pointer head;
//head is place = 0;
std::shared_ptr<node> addItem(std::shared_ptr<node>& head, std::shared_ptr<node>& tail, int place, int data);

//searches list for data and removes it. returns head.
std::shared_ptr<node> removeItem(std::shared_ptr<node>& head, std::shared_ptr<node>& tail, int data);


int main()
{
	std::shared_ptr<node> head{ std::make_shared<node>() };
	head->data = 0;

	std::shared_ptr<node> tail = head;

	for (int i = 1; i < 10; i++)
	{

		std::shared_ptr<node> temp{ std::make_shared<node>() };
		tail->next = temp;
		tail->next->prev = tail;;
		tail = tail->next;
		tail->data = i;
	}

	char command;
	do
	{
		//display list
		std::shared_ptr<node> currNode{ head };
		while (currNode != nullptr)
		{
			cout << currNode->data << endl;
			currNode = currNode->next;
		}

		cout << "(a)dd item or (r)emove item or (q)uit: ";
		cin >> command;
		int data = 0;
		int place = 0;
		switch (command)
		{
		case 'a':
			cout << endl << "What number do you want to add and where? ";
			cin >> data >> place;
			head = addItem(head, tail, place, data);
			break;

		case 'r':
			cout << endl << "What number do you want to remove? ";
			cin >> data;
			head = removeItem(head, tail, data);
			break;
		}
		system("CLS");
	} while (command != 'q');
	return 0;

}
std::shared_ptr<node> addItem(std::shared_ptr<node>& head, std::shared_ptr<node>& tail, int place, int data)
{
	if (head != nullptr)
	{
		std::shared_ptr<node> currNode{ head };

		//create node to insert
		std::shared_ptr<node> temp{ std::make_shared<node>() };
		temp->data = data;

		//head case
		if (place == 0)
		{

			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		else
		{
			int i = 0;
			// navigate to insertion point.
			while (currNode != nullptr && i != place)
			{
				currNode = currNode->next;
				i++;
			}
			if (i == place)
			{
				//insert before currNode
				temp->next = currNode;
				////tail case
				if (currNode == nullptr)
				{
					temp->prev = tail;
					tail->next = temp;
					tail = temp;
				}
				else
				{
					temp->prev = currNode->prev;
					currNode->prev->next = temp;
					currNode->prev = temp;
				}
			}
		}
	}
	return head;
}

std::shared_ptr<node> removeItem(std::shared_ptr<node>& head, std::shared_ptr<node>& tail, int data)
{

	//head
	//middle
	//tail
	//doesn't exist
	if (head != nullptr)
	{
		std::shared_ptr<node> currNode{ head };
		//head case
		if (head->data == data)
		{
			head = currNode->next;
			head->prev = nullptr;
		}
		else
		{
			//find the data
			while (currNode != nullptr && currNode->data != data)
			{
				currNode = currNode->next;
			}

			//if we found it
			if (currNode != nullptr && currNode->data == data)
			{
				//cut currNode out of the list
				currNode->prev->next = currNode->next;
				//!tail case
				if (currNode->next != nullptr)
				{

					currNode->next->prev = currNode->prev;
				}
				else
				{
					tail = currNode->prev;
				}
			}
		}
	}
	return head;
}