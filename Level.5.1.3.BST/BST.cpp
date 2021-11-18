#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int data{ 0 };
	std::shared_ptr<node> left{ nullptr };
	std::shared_ptr<node> right{ nullptr };
};

void insert(std::shared_ptr<node>& root, int data);
std::shared_ptr<node> insertRecursive(std::shared_ptr<node>, int key);
std::shared_ptr<node> search(std::shared_ptr<node> root, int key);
std::shared_ptr<node> remove(std::shared_ptr<node> root, int key);

void printTreeLNR(std::shared_ptr<node> currNode);
void printTreeNLR(std::shared_ptr<node> currNode);
void printTreeLRN(std::shared_ptr<node> currNode);

int main()
{
	std::vector<int> forTree{ 20, 6, 18, 7, 2, 25 };
	/*			20
				/\
			   6  25
			  /\
			 2  18
				/\
			   7
			   */
	std::shared_ptr<node> root{ nullptr };
	for (auto item : forTree)
	{
		insert(root, item);
		//root = insertRecursive(root, item);
	}
	printTreeLNR(root);
	cout << "What number to you want to search for? ";
	int key;
	cin >> key;
	if (search(root, key) != nullptr)
	{
		cout << key << " was found!!";
	}
	else
	{
		cout << key << " was NOT found!!";
	}
	cout << endl << "Which number do you want to delete? ";
	cin >> key;
	root = remove(root, key);
	printTreeLNR(root);
	cout << endl;
	printTreeLRN(root);
	cout << endl;
	printTreeNLR(root);
	cout << endl;

	system("PAUSE");
	return 0;
}

void insert(std::shared_ptr<node>& root, int data)
{
	std::shared_ptr<node> temp{ std::make_shared<node>() };
	temp->data = data;
	if (root == nullptr)
	{
		root = temp;
	}
	else
	{
		std::shared_ptr<node> currNode{ root };
		while (currNode != nullptr)
		{
			if (temp->data < currNode->data)
			{
				if (currNode->left == nullptr)
				{
					currNode->left = temp;
					return;
				}
				else
				{
					currNode = currNode->left;
				}
			}
			else
			{
				if (currNode->right == nullptr)
				{
					currNode->right = temp;
					return;
				}
				else
				{
					currNode = currNode->right;
				}
			}
		}

	}
}
std::shared_ptr<node> insertRecursive(std::shared_ptr<node> currNode, int data)
{
	if (currNode == nullptr)
	{
		std::shared_ptr<node> temp{ std::make_shared<node>() };
		temp->data = data;
		temp->left = nullptr;
		temp->right = nullptr;
		return temp;
	}
	if (data < currNode->data)
	{
		currNode->left = insertRecursive(currNode->left, data);
	}
	else if (data > currNode->data)
	{
		currNode->right = insertRecursive(currNode->right, data);
	}
	return currNode;

}

std::shared_ptr<node> search(std::shared_ptr<node> root, int key)//, int& distance)
{
	std::shared_ptr<node> currNode{ root };
	while (currNode != nullptr)
	{
		if (key == currNode->data)
		{
			return currNode;
		}
		else if (key < currNode->data)
		{
			currNode = currNode->left;
		}
		else
		{
			currNode = currNode->right;
		}
	}
	return nullptr; //not found
}

std::shared_ptr<node> remove(std::shared_ptr<node> root, int key)
{
	std::shared_ptr<node> parent{ nullptr };
	std::shared_ptr<node> toRemove{ root };
	while (toRemove != nullptr)
	{
		if (toRemove->data == key)//if we found a match
		{
			if (toRemove->left == nullptr && toRemove->right == nullptr) //removing a leaf;
			{

				if (parent == nullptr)//if the root is to be romoved
				{
					root = nullptr;
				}
				else if (parent->left == toRemove)
				{
					parent->left == nullptr;
				}
				else
				{
					parent->right == nullptr;
				}
				return root;
			}
			else if (toRemove->left != nullptr && toRemove->right == nullptr) //remove node with only left node
			{
				if (parent == nullptr)
				{
					root = toRemove->left;
				}
				else if (parent->left == toRemove)
				{
					parent->left = toRemove->left;
				}
				else
				{
					parent->right = toRemove->left;
				}
				return root;
			}
			else if (toRemove->left == nullptr && toRemove->right != nullptr) //remove node with only right node
			{
				if (parent == nullptr)
				{
					root = toRemove->right;
				}
				else if (parent->left == toRemove)
				{
					parent->left = toRemove->right;
				}
				else
				{
					parent->right = toRemove->right;
				}
				return root;
			}
			else //removes node with two children
				//find successor (leftmost child of right subtree)
			{
				std::shared_ptr<node> successor{ toRemove->right };
				while (successor->left != nullptr)
				{
					successor = successor->left;
				}
				toRemove->data = successor->data;
				remove(toRemove->right, successor->data);
				return root;
			}
		}
		else if (toRemove->data < key)
		{
			parent = toRemove;
			toRemove = toRemove->right;
		}
		else
		{
			parent = toRemove;
			toRemove = toRemove->left;
		}
	}
	return root;
}

void printTreeLNR(std::shared_ptr<node> currNode)
{
	if (currNode == nullptr)
	{
		return;
	}
	printTreeLNR(currNode->left);
	cout << currNode->data << ", ";
	printTreeLNR(currNode->right);
}

void printTreeNLR(std::shared_ptr<node> currNode)
{
	if (currNode == nullptr)
	{
		return;
	}
	cout << currNode->data << ", ";
	printTreeNLR(currNode->left);
	printTreeNLR(currNode->right);
}

void printTreeLRN(std::shared_ptr<node> currNode)
{
	if (currNode == nullptr)
	{
		return;
	}
	printTreeLRN(currNode->left);
	printTreeLRN(currNode->right);
	cout << currNode->data << ", ";
}
