#include <iostream>


struct node
{
	int data{ 0 };
	node* next{ nullptr };
};
//add item at certain place in list, returns pointer head;
//head is place = 0;
node* addItem(node* head, int place, int data);

//searches list for data and removes it. returns head.
node* removeItem(node* head, int data);


int main()
{
	node* head{ new node };

	head->data = 0;

	int numNodes{ 10 };

	node* currNode{ head };
	for (int i = 1; i < numNodes; i++)
	{

		while (currNode->next != nullptr)
		{
			currNode = currNode->next;
		}
		
		node* temp{ new node };
		temp->next = nullptr;

		currNode->next = temp;
		currNode = currNode->next;
		currNode->data = i;
	}

	char command;
	do
	{
		//display list:
		currNode = head;
		while (currNode != nullptr)
		{
			std::cout << currNode->data << std::endl;
			currNode = currNode->next;
		}
		//cout << currNode->data << endl;

		std::cout << "(a)dd item or (r)emove item or (q)uit: ";
		std::cin >> command;
		int data = 0;
		int place = 0;
		switch (command)
		{
		case 'a':
			std::cout << std::endl << "What number do you want to add and where? ";
			std::cin >> data >> place;
			head = addItem(head, place, data);
			break;

		case 'r':
			std::cout << std::endl << "What number do you want to remove? ";
			std::cin >> data;
			head = removeItem(head, data);
			break;
		}
		system("CLS");
	} while (command != 'q');

	delete head;

	return 0;

}
node* addItem(node* head, int place, int data)
{
	if (head != nullptr)
	{
		node* currNode{ head };

		node* temp = new node;
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

node* removeItem(node* head, int data)
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
			currNode = head;
			head = currNode->next;
		}
		else
		{
			node* prevnode{ head };
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


		delete currNode;
	}
	return head;
}