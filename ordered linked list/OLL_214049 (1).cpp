/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <iostream>
using namespace std;


class OLL
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head, *ptr, *temp, *tail;

  public:
  
	
	OLL()
	{
		head = NULL;
	}
	
	
	~OLL()
	{
		ptr = head;
		while (ptr != NULL)
		{
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}
	}

	
	bool is_empty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}

	
	void insert_node(int data)
	{
		temp = new node;
		temp->data = data;
		temp->next = NULL;
		if (is_empty())
		{
			head = temp;
			tail = head;
		}
		else
		{
			struct node *temp1;
			if (temp->data < head->data)
			{
				temp->next = head;
				head = temp;
			}
			else if (temp->data > tail->data)
			{
				tail->next = temp;
				tail = temp;
			}
			else
			{
				ptr = head;
				while (ptr != NULL)
				{
					temp1 = ptr;
					ptr = ptr->next;
					if ((temp->data >= temp1->data) && (temp->data < ptr->data))
					{
						temp->next = ptr;
						temp1->next = temp;
					}
				}
			}
		}
	}
	

	void delete_node(int data)
	{
		bool contains;
		if (!is_empty())
		{
			if (head->data == data)
			{
				if (head == tail)
				{
					delete tail;
					head = NULL;
				}
				else
				{
					temp = head;
					head = head->next;
					delete temp;
				}
			}
			else
			{
				ptr = head;
				while (ptr != NULL)
				{
					if (ptr->data == data)
					{
						contains = true;
						if (ptr == tail)
						{
							delete ptr;
							temp->next = NULL;
							tail = temp;
						}
						else
						{
							temp -> next = ptr->next;
							delete ptr;
							break;
						}
					}
					else
						contains = false;
					temp = ptr;
					ptr = ptr->next;
				}
				if(!contains)
					cout << "\nList doesn't have this node already!";
			}
		}
	}
	

	OLL merge(OLL &list)
	{
		OLL list1;
		list1 = *this;
		ptr = list.head;
		while (ptr != NULL)
		{
			list1.insert_node(ptr->data);
			ptr = ptr->next;
		}
		return list1;
	}
	
	
	void print_list()
	{
		cout << "\n\t";
		if (head == NULL)
			cout << "Linked list is empty";
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr != head)
				cout << " -> ";
			cout << ptr->data;
			ptr = ptr->next;
		}
		cout << endl;
	}
};


void create_list(OLL &list)
{
	char ch1;
	int data;
	do
	{
		cout << "\nEnter node data to be inserted: ";
		cin >> data;
		list.insert_node(data);

		cout << "Want to insert more nodes? y/n: ";
		cin >> ch1;
	} while (ch1 == 'y');
}

void del(OLL &list)
{
	char ch1;
	int data;
	do
	{
		if (!list.is_empty())
		{
			cout << "\nEnter node data to be deleted: ";
			cin >> data;
			list.delete_node(data);

			cout << "\nWant to delete more nodes? y/n: ";
			cin >> ch1;
		}
	} while (ch1 == 'y');
}


int main()
{
	OLL list;
	char ch;
	int choice;
	cout << "\nOrdered Linked list demonstration:\n";
	do
	{
		cout << "\n1. Insert\n2. Delete\n3. Merge with another list\n\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			create_list(list);
			list.print_list();
			break;
		case 2:
			del(list);
			list.print_list();
			break;
		case 3:
			OLL new_list;
			cout << "\nCreating (new) list to be merged...";
			create_list(new_list);
			list = list.merge(new_list);
			list.print_list();
			break;
		}
		cout << "\nWant to operate more? y/n : ";
		cin >> ch;
	} while (ch == 'y');
	return 0;
}