/*
Find the first non-repeating character from a stream of characters
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

typedef struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
}Node;

Node* InsertIntoDLL(Node** head, char n)
{
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->left = NULL;
	newNode->right = NULL;
	if( *head == NULL )
	{	
		*head = newNode;
		return *head;
	}
	else
	{
		Node* temp = *head;
		while( temp->right != NULL)
		{
			temp = temp->right;
		}
		temp->right = newNode;
		newNode->left = temp;
		return newNode;
	}
		
}

void DeleteFromDLL(Node** head, Node* temp)
{
	if( !(*head) )
	{
		return;
	}

	if( temp == *head)
	{
		if(temp->right == NULL)
		{
			free(temp);
			*head = NULL;
			return;
		}
		else
		{
			*head = (*head)->right;
			free(temp);
			(*head)->left = NULL;
			return;
		}
	}
	else
	{
		if(temp->right == NULL)
		{
			temp->left->right = NULL;
			free(temp);
			return;
		}
		else
		{
			temp->left->right = temp->right;
			temp->right->left = temp->left;
			free(temp);
			return;
		}
	}


}

void PrintDLL(Node* head)
{
	if( !head )
	{
		cout << "DLL empty" << endl;
		return;
	}
	
	cout << endl << "List : ";
	while( head->right != NULL )
	{
		cout << "\t" << head->data;
	}
	cout << endl;
}

int main()
{
	map<char, pair<int, Node*> > m;
	map<char, pair<int, Node*> >::iterator it;
	Node* head = NULL;

	char n;

	cin >> n;

	while( n != 'z' )
	{
		it = m.find(n);

		if( it == m.end() )
		{
			Node* newNode = InsertIntoDLL(&head, n);
			m[n].first = 1;
			m[n].second = newNode;
		}
		else
		{
			if(m[n].first == 1 ) 
			{
				DeleteFromDLL(&head, m[n].second);
			}
			m[n].first++;
		}

		cout << "First Non-Repeating Character of Stream is: ";
		
		//PrintDLL(head);

		if( head )
		{
			cout << head->data << endl;
		}
		else
		{
			cout << "NULL" << endl;
		}
		
		cin >> n;
	}

	return 0;
}
