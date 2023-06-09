#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
typedef struct node
{
	double data;
	node *next;
};
class LinkedList
{
  private:
	node *head;
	static int ObjCount;
	static int NodeCount;

  public:
	LinkedList()
	{
		this->head = nullptr;
		ObjCount++;
	}

	/*~LinkedList()
	{
		while (head != nullptr)
		{
			node *temp = head;
			head = head->next;
			delete temp;
		}
	}*/
	// Node data getter
	double GetData(node *node)
	{
		return node->data;
	}
	// return number of all initiated instance
	int GetObjCount()
	{
		return ObjCount;
	}
	//Return number of all node initialized
	int GetNodeCount()
	{
		return NodeCount;
	}
	// Setter Head
	void SetHead(node *node)
	{
		if (node == nullptr)
		{
			return;
		}
		this->head = node;
	}
	// Add data at the end of list
	void Add(double data)
	{
		node *newnode = new node;
		newnode->data = data;
		if (this->head == nullptr)
		{
			this->head = newnode;
		}
		else
		{
			node *curr = this->head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = newnode;
		}
		NodeCount++;
		newnode = nullptr;
		delete newnode;
	}

	// return adress of head node
	node *GetHeadPtr()
	{
		return this->head;
	}
	// return adress of tail nodes
	node *GetTailPtr()
	{
		if (this->head == nullptr)
		{
			return this->head;
		}
		else
		{
			node *curr = this->head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
				
			}
			return curr;
		}
	}
	//return adress of node at index of i
	node *GetNodePtr(int index)
	{
		if (index < 0)
		{
			return nullptr;
		}
		if (head == nullptr)
		{
			return nullptr;
		}
		if (index == 0)
		{
			return this->head;
		}
		else
		{
			node *curr = this->head;
			for (int i = 0; i < index; i++)
			{
				if (curr->next == nullptr)
				{
					return nullptr;
				}
				curr = curr->next;
			}
			return curr;
		}
	}
	// Modify data of indexed node
	void ChangeData(int index, double data)
	{
		if (index < 0)
		{
			return;
		}
		if (this->head == nullptr)
		{
			return;
		}
		node *curr = this->head;
		for (int i = 0; i < index; i++)
		{
			if (curr->next == nullptr)
			{
				return;
			}
			curr = curr->next;
		}
		curr->data = data;
	}
	// modify data of node by reference
	void ChangeDataPtr(node *node, double newdata)
	{
		node->data = newdata;
	}
	// Return lenght of LinkedList
	int GetLength()
	{
		int lenght = 0;
		node *curr = this->head;
		if (head == nullptr)
		{
			return 0;
		}
		else
		{
			while (curr != nullptr)
			{
				lenght++;
				curr = curr->next;
			}
		}
		return lenght;
	}

	// return string containing all data separated by delimiter
	string GetAllData(string delimiter = ",", int precision = 0)
	{
		string text;
		node *curr = head;
		if (head == nullptr)
		{
			return "";
		}
		else
		{
			while (curr != nullptr)
			{
				stringstream ss;
				ss << fixed << setprecision(precision) << curr->data;
				string strdata = ss.str();
				text = text + strdata + delimiter;
				curr = curr->next;
			}
			text.erase(text.length() - 1);
			return text;
		}
	}

	// convert an return to a vector format
	vector<double> ToVector()
	{
		node *curr = this->head;
		if (this->head == nullptr)
		{
			return vector<double>();
		}
		else
		{
			vector<double> myVector;
			while (curr != nullptr)
			{
				myVector.push_back(curr->data);
				curr = curr->next;
			}
			return myVector;
		}
	}
	// print all data
	void Print()
	{
		node *curr = this->head;
		if (head == nullptr)
		{
			cout << "Linked list empty";
			return;
		}
		else
		{
			while (curr != nullptr)
			{
				cout << curr->data << endl;
				curr = curr->next;
			}
		}
	}

	//Print Adress of each node
	void PrintMemory()
	{
		node *curr = this->head;
		int count = 1;
		if (head == nullptr)
		{
			cout << "Linked list empty";
			return;
		}
		else
		{
			while (curr != nullptr)
			{
				cout << count  << " " << curr  << endl;
				count++;
				curr = curr->next;
			}
		}
	}

	// delete node at given index
	void Delete(int index)
	{
		if (index < 0)
		{
			return;
		}
		if (head == nullptr)
		{
			return;
		}
		if (index == 0)
		{
			if (this->head->next == nullptr)
			{
				node *selected_node = head;
				this->head = nullptr;
				delete selected_node;
				NodeCount--;
				return;
			}
			else
			{
				node *selected_node = this->head;
				this->head = selected_node->next;
				selected_node = nullptr;
				delete selected_node;
				NodeCount--;
				return;
			}
		}
		else
		{
			node *prev = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				if (prev->next == nullptr)
				{
					return;
				}

				prev = prev->next;
			}
			node *selected_node = prev->next;
			prev->next = selected_node->next;
			selected_node = nullptr;
			delete selected_node;
			NodeCount--;
		}
	}

	//Swap nodes
	void SwapData(node *node_a, node *node_b)
	{
		if (node_a == nullptr || node_b == nullptr)
		{
			return;
		}
		double temp = node_a->data;
		node_a->data = node_b->data;
		node_b->data = temp;
	}

	// Traverse
	static node *Traverse(node *curr, int loop)
	{
		for (int i = 0; i < loop; i++)
		{
			if (curr->next != nullptr)
			{
				curr = curr->next;
			}
		}
		return curr;
	}
	// return node data at given index
	double GetData(int index)
	{
		if (index < 0)
		{
			return 0;
		}
		node *curr = this->head;
		if (curr == nullptr)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				if (curr->next == nullptr)
				{
					break;
					return 0;
				}
				curr = curr->next;
			}
			return curr->data;
		}
	}

	// Destroy all node of the class
	void Destroy()
	{
		while (head != nullptr)
		{
			node *temp = head;
			head = head->next;
			temp->next = nullptr;
			delete temp;
		}
	}

	// function to allocate nodes of n number
	void Allocate(int num_of_node)
	{
		if (num_of_node <= 0)
		{
			return;
		}
		node *tail = this->GetTailPtr();
		if (tail == nullptr)
		{
			this->head = new node;
		}
		else
		{
			tail->next = new node;
		}
		NodeCount++;
		Allocate(num_of_node - 1);
		
	}

	//set all node to given value
	void SetAll(double newdata = 0)
	{
		if (this->head == nullptr)
		{
			return;
		}
		node *curr = this->head;

		while (curr != nullptr)
		{
			curr->data = newdata;
			curr = curr->next;
		}
	}
	// reverse linked list
	void Reverse()
	{
		node *current = head;
		node *prev = nullptr;
		while (current != nullptr)
		{
			node *next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	// Copy existing linkedlist
	void Copy(node *list_selected)
	{
		if (list_selected == nullptr)
		{
			return;
		}
		if (this->head == nullptr)
		{
			this->head = new node;
		}
		node *curr = this->head;
		while (list_selected != nullptr)
		{
			curr->data = list_selected->data;
			if (list_selected->next != nullptr)
			{
				node *next_node = new node;

				curr->next = next_node;
				curr = curr->next;
			}
			list_selected = list_selected->next;
		}
	}

	// Copy existing linkedlist
	static node *StaticCopy(node *list_selected)
	{
		if (list_selected == nullptr)
		{
			return nullptr;
		}
		node *copied = nullptr;
		node *ptr = nullptr;
		node *next_node = new node;
		if (ptr == nullptr)
		{
			ptr = next_node;
			copied = ptr;
		}
		while (list_selected != nullptr)
		{
			node *next_node = new node;

			copied->data = list_selected->data;

			if (list_selected->next != nullptr)
			{
				copied->next = next_node;
				copied = copied->next;
			}
			list_selected = list_selected->next;
		}
		return ptr;
	}
};
int LinkedList::ObjCount = 0;
int LinkedList::NodeCount = 0;
