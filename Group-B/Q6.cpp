/*
Aledutron
SPPU 2019 SE DSAL Lab
SPPU Computer Engineering Second Year (SE) Data Structures &amp; Algorithms (DSA) Lab Assignments (2019 Pattern)
Youtube DSAL Playlist Link: https://www.youtube.com/playlist?list=PLlShVH4JA0ov8DstIyTidJhSmW4WIGa7V

Problem Statement:
Group-B/Q6.cpp
Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every
node
v. Search a value

Explaination Video Link: https://www.youtube.com/watch?v=y7Ckft2iHls&list=PLlShVH4JA0ov8DstIyTidJhSmW4WIGa7V&index=1&pp=iAQB
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
	int data = 0;
	Node *left = NULL;
	Node *right = NULL;
};

class BST
{
public:
	Node *root = NULL;

	void insert(int val)
	{
		Node *temp = new Node();
		temp->data = val;

		if (this->root == NULL)
		{
			this->root = temp;
		}
		else
		{

			Node *cur = this->root;
			while (true)
			{
				if (val > cur->data)
				{
					if (cur->right == NULL)
					{
						cur->right = temp;
						break;
					}
					cur = cur->right;
				}
				else
				{
					if (cur->left == NULL)
					{
						cur->left = temp;
						break;
					}
					cur = cur->left;
				}
			}
		}
	}

	void inorder(Node *node)
	{
		if (node == NULL)
		{
			return;
		}

		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}

	bool search(int val, Node *node)
	{
		if (node == NULL)
		{
			return false;
		}
		bool ans = false;

		ans |= search(val, node->left);
		if (node->data == val)
		{
			return true;
		}
		ans |= search(val, node->right);

		return ans;
	}

	int minValue(Node *node)
	{
		if (node->left == NULL)
		{
			return node->data;
		}
		minValue(node->left);
	}

	int maxValue(Node *node)
	{
		if (node->right == NULL)
		{
			return node->data;
		}
		maxValue(node->right);
	}

	int calHeight(Node *node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return max(1 + calHeight(node->left), 1 + calHeight(node->right));
	}

	void swapTree(Node *node)
	{
		if (node == NULL)
		{
			return;
		}

		swapTree(node->left);
		swapTree(node->right);

		Node *temp = node->right;
		node->right = node->left;
		node->left = temp;
	}
};

int main()
{
	BST t;

	t.insert(10);
	t.insert(-1);
	t.insert(15);
	t.insert(3);
	t.insert(10);
	t.insert(1);
	t.insert(15);
	t.insert(3);

	cout << "Inorder: ";
	t.inorder(t.root);
	cout << endl;

	cout << t.search(11, t.root) << endl;

	cout << t.minValue(t.root) << endl;

	cout << t.maxValue(t.root) << endl;

	cout << t.calHeight(t.root) << endl;

	t.swapTree(t.root);

	cout << "Inorder: ";
	t.inorder(t.root);
	cout << endl;
}