#include <iostream>
#include <vector>
#include <memory>


struct node
{
	int data{ 0 };
	std::unique_ptr<node> next{ nullptr };
};
//add item at certain place in list, returns pointer head;
//head is place = 0;
void addItem(std::unique_ptr<node>& head, int place, int data);

//searches list for data and removes it. returns head.
void removeItem(std::unique_ptr<node>& head, int data);


int main()
{
	std::unique_ptr<node> head{ std::make_unique<node>() };
	head->data = 0;

	node* currNode = head.get();
	for (int i = 1; i < 10; i++)
	{
		while (currNode->next != nullptr)
		{
			currNode = currNode->next.get();
		}
		std::unique_ptr<node> temp{ std::make_unique<node>() };
		currNode->next = std::move(temp);
		currNode = currNode->next.get();
		currNode->data = i;
	}

	char command;
	do
	{
		//display list:
		currNode = head.get();
		while (currNode->next != nullptr)
		{
			std::cout << currNode->data << std::endl;
			currNode = currNode->next.get();
		}
		std::cout << currNode->data << std::endl;

		std::cout << "(a)dd item or (r)emove item or (q)uit: ";
		std::cin >> command;
		int data = 0;
		int place = 0;
		switch (command)
		{
		case 'a':
			std::cout << std::endl << "What number do you want to add and where? ";
			std::cin >> data >> place;
			addItem(head, place, data);
			break;

		case 'r':
			std::cout << std::endl << "What number do you want to remove? ";
			std::cin >> data;
			removeItem(head, data);
			break;
		}
		system("CLS");
	} while (command != 'q');

	return 0;

}
void addItem(std::unique_ptr<node>& head, int place, int data)
{
	if (head != nullptr)
	{
		node* currNode = head.get();

		std::unique_ptr<node> temp{ std::make_unique<node>() };
		temp->data = data;
		temp->next = nullptr;

		if (place == 0)
		{

			temp->next = std::move(head);
			head = std::move(temp);
		}
		else
		{
			int i = 0;
			while (currNode->next != nullptr && i != place)
			{
				currNode = currNode->next.get();
				i++;
			}
			if (i == place)
			{
				temp->next = std::move(currNode->next);
				currNode->next = std::move(temp);
			}
		}
	}
}

void removeItem(std::unique_ptr<node>& head, int data)
{

	//head
	//middle
	//tail
	//doesn't exist
	if (head != nullptr)
	{
		node* currNode{ nullptr };
		if (head->data == data)
		{
			head = std::move(currNode->next);
		}
		else
		{
			node* prevnode{ head.get()};
			currNode = head->next.get();
			while (currNode != nullptr && currNode->data != data)
			{
				prevnode = currNode;
				currNode = currNode->next.get();
			}

			if (currNode != nullptr && currNode->data == data)
			{
				prevnode->next = std::move(currNode->next);
			}
		}
	}
}