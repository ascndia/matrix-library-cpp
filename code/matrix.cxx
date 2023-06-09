#include "linkedlist.cxx"
#include <chrono>
#include <string>
#include <iomanip>
class Matrix
{
  public:
	LinkedList Vector;

  private:
	int row;
	int col;
	int area;
	bool Gauss_is_Swapped;

  public:
	Matrix(int row, int col)
	{
		this->row = row;
		this->col = col;
		this->area = row * col;
		this->Gauss_is_Swapped = 0;
	}
	// Getter
	bool GetGaussSwap()
	{
		return Gauss_is_Swapped;
	}
	int GetRow()
	{
		return this->row;
	}
	int GetCol()
	{
		return this->col;
	}
	int GetArea()
	{
		return this->area;
	}

	// Indexization
	node *GetIndex(int xrow, int xcol)
	{
		if (xrow < 0 || xrow < 0 || xrow > this->GetRow() || xcol > this->GetCol())
		{
			return nullptr;
		}
		node *curr = this->Vector.GetHeadPtr();

		for (int i = 0; i < this->col * xrow; i++)
		{
			curr = curr->next;
		}
		for (int i = 0; i < xcol; i++)
		{
			curr = curr->next;
		}
		return curr;
	}

	// Set value of node at linkedlist
	void SetData(node *input, double data)
	{
		input->data = data;
	}

	//Auto fill demo value
	void AutoFill()
	{
		for (int i = 0; i < this->GetArea(); i++)
		{
			this->Vector.ChangeData(i, i + 1);
		}
	}

	//Destroy matrix linkedlist
	void DestroyMatrix()
	{
		this->Vector.Destroy();
		this->col = 0;
		this->row = 0;
		this->area = 0;
	}
	// get current row head (index start at 0)
	node *GetCurrentRow(int x_index)
	{
		if (this->Vector.GetHeadPtr() == nullptr || x_index > this->row || x_index < 0)
		{
			return nullptr;
		}
		node *curr = this->Vector.GetHeadPtr();
		for (int i = 0; i < x_index * this->col; i++)
		{
			curr = curr->next;
		}
		return curr;
	}

	// get current column head (index start at 0)
	node *GetCurrentCol(int y_index)
	{
		if (this->Vector.GetHeadPtr() == nullptr || y_index > this->col || y_index < 0)
		{
			return nullptr;
		}
		node *curr = this->Vector.GetHeadPtr();
		for (int i = 0; i < y_index; i++)
		{
			curr = curr->next;
		}
		return curr;
	}

	//Print matrix v1
	void Print(string delimiter = "\t")
	{
		if (this->Vector.GetHeadPtr() == nullptr)
		{
			return;
		}
		else
		{
			for (int i = 0; i < this->GetRow(); i++)
			{
				for (int j = 0; j < this->GetCol(); j++)
				{
					cout << this->GetIndex(i, j)->data;
					if (j < this->GetCol() - 1)
					{
						cout << delimiter;
					}
				}
				cout << endl
					 << endl;
			}
		}
	}

	// Return head node of Transposed linkedlist
	// Dont forget to swap row and col after using this method
	static Matrix *GetTranspose(Matrix *A)
	{
		int row_after = A->col;
		int col_after = A->row;

		//cout<<A->row;
		Matrix *B = new Matrix(row_after, col_after);
		B->initialize();

		LinkedList *after = new LinkedList;
		after->Allocate(row_after * col_after);

		node *curr = A->Vector.GetHeadPtr();
		node *top_row = A->Vector.GetHeadPtr();
		int i = 0;
		while (i < after->GetLength() - 1)
		{
			for (int j = 0; j < A->GetCol(); j++)
			{
				curr = top_row;

				for (int k = 0; k < A->GetRow(); k++)
				{
					after->ChangeData(i, curr->data);
					i++;
					for (int l = 0; l < A->GetCol(); l++)
					{
						if (curr->next != nullptr)
						{
							curr = curr->next;
						}
					}
				}
				top_row = top_row->next;
			}
		}
		B->Vector.SetHead(after->GetHeadPtr());
		return B;
	}

	// Transpose
	void Transpose()
	{
		int row_after = this->col;
		int col_after = this->row;

		LinkedList *after = new LinkedList;

		after->Allocate(row_after * col_after);

		node *curr = this->Vector.GetHeadPtr();
		node *top_row = this->Vector.GetHeadPtr();
		int i = 0;

		while (i < after->GetLength() - 1)
		{
			for (int j = 0; j < this->col; j++)
			{
				curr = top_row;

				for (int k = 0; k < this->row; k++)
				{
					after->ChangeData(i, curr->data);
					i++;
					for (int l = 0; l < this->col; l++)
					{
						if (curr->next != nullptr)
						{
							curr = curr->next;
						}
					}
				}
				top_row = top_row->next;
			}
		}
		this->col = col_after;
		this->row = row_after;
		this->area = col * row;

		this->Vector.Destroy();

		this->Vector.SetHead(after->GetHeadPtr());
	}

	// return node of pivot at given row. only for diagonal matrix
	node *GetPivot(int param_row)
	{
		if (this->row != this->col || param_row >= this->col || param_row < 0)
		{
			return nullptr;
		}
		int x = 0;
		node *curr = this->Vector.GetHeadPtr();
		for (int i = 0; i < param_row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				curr = curr->next;
			}
			x++;
		}
		for (int i = 0; i < x; i++)
		{
			curr = curr->next;
		}
		return curr;
	}

	// Set Matrix data;
	void InputData()
	{
		if (this->Vector.GetHeadPtr() == nullptr)
		{
			cout << "LinkedList not initialized" << endl;
		}
		node *curr = this->Vector.GetHeadPtr();
		int thisrow = 0;
		int thiscol = 0;
		while (curr != nullptr)
		{
			this->Print();
			cout << endl;
			cout << "Input data at Row " << thisrow << " Col " << thiscol << " : ";
			cin >> curr->data;
			system("clear");
			thiscol++;
			if (thiscol == this->col)
			{
				thiscol = 0;
				thisrow++;
			}
			curr = curr->next;
		}
		system("clear");
	}

	//Initialize and allocate memory of LinkedList
	void initialize()
	{
		this->Vector.Allocate(area);
	}

	// Get Upper triagular form of given matrix
	static Matrix *UpperTriangular(Matrix *A)
	{
		if (A->col != A->row)
		{
			return nullptr;
		}
		Matrix *Result = new Matrix(A->row, A->col);
		LinkedList *after = new LinkedList;
		after->Copy(A->Vector.GetHeadPtr());
		Result->Vector.SetHead(after->GetHeadPtr());
		for (int i = 0; i < Result->col - 1; i++)
		{
			node *pivot = Result->GetPivot(i);
			for (int j = 1; j < Result->row - i; j++)
			{
				node *curr = Result->GetCurrentRow(j);
				if (pivot->data == 0)
				{
					int curr_row = i;
					bool is_found = false;
					node *below = pivot;
					for (int a = 0; a < Result->row - j; a++)
					{
						node *b = LinkedList::Traverse(below, Result->row);
						curr_row++;
						below = b;
						if (b->data != 0)
						{
							is_found = true;
							break;
						}
					}
					if (is_found) // Swap row if found;
					{
						node *row1 = Result->GetCurrentRow(i);
						node *row2 = Result->GetCurrentRow(curr_row);
						for (int ab = 0; ab < Result->col; ab++)
						{
							double temp = row1->data;
							row1->data = row2->data;
							row2->data = temp;
							row1 = row1->next;
							row2 = row2->next;
						}
						Result->Gauss_is_Swapped = true;
					}
				}
				for (int k = 0; k < i + i * Result->col; k++)
				{
					if (curr->next != nullptr)
					{
						curr = curr->next;
					}
				}
				if (curr->data == 0)
				{
					continue;
				}
				double temp = curr->data / pivot->data;
				node *top = pivot;
				for (int l = i; l < Result->col; l++)
				{
					curr->data = curr->data - (top->data * temp);
					if (curr->next != nullptr)
					{
						curr = curr->next;
						top = top->next;
					}
				}
			}
		}
		return Result;
	}

	// Return reusable string of matrix vector
	static string GetUniversalString(Matrix *A)
	{
		return A->Vector.GetAllData(",", 8);
	}

	// Set matrix to identity matrix
	void SetIdentityMatrix()
	{
		if (this->col != this->row)
		{
			return;
		}

		if (this->Vector.GetHeadPtr() == nullptr)
		{
			this->initialize();
		}

		node *curr = this->Vector.GetHeadPtr();

		for (int i = 0; i < this->col; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				if (j == i)
				{
					curr->data = 1;
				}
				else
				{
					curr->data = 0;
				}
				if (curr->next != nullptr)
				{
					curr = curr->next;
				}
			}
		}
	}

	// Receive string of number and Assign to the matrix
	void ScanString(string str, char delimiter = ',')
	{
		string token;

		size_t start = str.find("[");

		if (start == string::npos)
		{
			return;
		}
		size_t end = str.find("]");
		if (end == string::npos)
		{
			return;
		}
		if (end < start)
		{
			return;
		}

		++start;

		str = str.substr(start, end - start);
		
		

		istringstream iss(str);

		LinkedList *newlist = new LinkedList;

		while (getline(iss, token, delimiter))
		{
			double number = stod(token);
			newlist->Add(number);
		}

		if (newlist->GetLength() != this->area)
		{
			return;
		}		
		this->Vector.SetHead(newlist->GetHeadPtr());
		
	}
};


/*
int main(){
	Matrix* A = new Matrix(3,3);
	string str = "[1,3,5,7,8,5,3,6,1]";
	A->ScanString(str);
	A->Print();
}
*/


