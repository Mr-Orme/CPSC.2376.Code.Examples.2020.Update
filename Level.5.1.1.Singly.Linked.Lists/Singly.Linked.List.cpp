#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct node
{
	int data{ 0 };
	std::shared_ptr<node> next{ nullptr };
};
//add item at certain place in list, returns pointer head;
//head is place = 0;
std::shared_ptr<node> addItem(std::shared_ptr<node> head, int place, int data);

//searches list for data and removes it. returns head.
std::shared_ptr<node> removeItem(std::shared_ptr<node> head, int data);


int main()
{
	std::shared_ptr<node> head{ std::make_shared<node>() };
	head->data = 0;

	std::shared_ptr<node> currNode = head;
	for (int i = 1; i < 10; i++)
	{
		while (currNode->next != nullptr)
		{
			currNode = currNode->next;
		}
		std::shared_ptr<node> temp{ std::make_shared<node>() };
		currNode->next = temp;
		currNode = currNode->next;
		currNode->data = i;
	}

	char command;
	do
	{
		//display list:
		currNode = head;
		while (currNode->next != nullptr)
		{
			cout << currNode->data << endl;
			currNode = currNode->next;
		}
		cout << currNode->data << endl;

		cout << "(a)dd item or (r)emove item or (q)uit: ";
		cin >> command;
		int data = 0;
		int place = 0;
		switch (command)
		{
		case 'a':
			cout << endl << "What number do you want to add and where? ";
			cin >> data >> place;
			head = addItem(head, place, data);
			break;

		case 'r':
			cout << endl << "What number do you want to remove? ";
			cin >> data;
			head = removeItem(head, data);
			break;
		}
		system("CLS");
	} while (command != 'q');

	return 0;

}
std::shared_ptr<node> addItem(std::shared_ptr<node> head, int place, int data)
{
	if (head != nullptr)
	{
		std::shared_ptr<node> currNode = head;

		std::shared_ptr<node> temp{ std::make_shared<node>() };
		temp->data = data;
		temp->next = nullptr;

		if (place == 0)
		{

			temp->next = head;
			head = temp;
		}
		else
		{
			int i = 0;
			while (currNode->next != nullptr && i != place)
			{
				currNode = currNode->next;
				i++;
			}
			if (i == place)
			{
				temp->next = currNode->next;
				currNode->next = temp;
			}
		}
	}
	return head;
}

std::shared_ptr<node> removeItem(std::shared_ptr<node> head, int data)
{

	//head
	//middle
	//tail
	//doesn't exist
	if (head != nullptr)
	{
		std::shared_ptr<node> currNode{ nullptr };
		if (head->data == data)
		{
			currNode = head;
			head = currNode->next;
		}
		else
		{
			std::shared_ptr<node> prevnode{ head };
			currNode = head->next;
			while (currNode != nullptr && currNode->data != data)
			{
				prevnode = currNode;
				currNode = currNode->next;
			}

			if (currNode != nullptr && currNode->data == data)
			{
				prevnode->next = currNode->next;
			}
		}
	}
	return head;
}