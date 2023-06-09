#include "matrix.cxx"

vector<Matrix> Matrixes;
vector<Matrix> ResultMatrix;

class MatrixOperation
{
  public:
	void MatrixAddition(Matrix A, Matrix B)
	{
		if (A.GetCol() != B.GetCol() || A.GetRow() != B.GetRow())
		{
			return;
		}
		int row = A.GetRow();
		int col = A.GetCol();

		Matrix *Result = new Matrix(row, col);
		Result->initialize();

		float left, right, result;
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				left = A.Vector.GetData(A.GetIndex(j, i));
				right = B.Vector.GetData(B.GetIndex(j, i));
				result = left + right;
				Result->SetData(Result->GetIndex(j, i), result);
			}
		}
		ResultMatrix.push_back(*Result);
	}

	// Element wise multiplication
	void MatrixElementWiseMultiplication(Matrix A, Matrix B)
	{
		if (A.GetCol() != B.GetCol() || A.GetRow() != B.GetRow())
		{
			return;
		}
		int row = A.GetRow();
		int col = A.GetCol();

		Matrix *Result = new Matrix(row, col);
		Result->initialize();

		float left, right, result;
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				left = A.Vector.GetData(A.GetIndex(j, i));
				right = B.Vector.GetData(B.GetIndex(j, i));
				result = left * right;
				Result->SetData(Result->GetIndex(j, i), result);
				A.GetCurrentRow(i);
			}
		}
		ResultMatrix.push_back(*Result);
	}

	// Matrix subtraction
	void MatrixSubtraction(Matrix A, Matrix B)
	{
		if (A.GetCol() != B.GetCol() || A.GetRow() != B.GetRow())
		{
			return;
		}
		int row = A.GetRow();
		int col = A.GetCol();

		Matrix *Result = new Matrix(row, col);
		Result->initialize();

		double left, right, result;
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				left = A.Vector.GetData(A.GetIndex(j, i));
				right = B.Vector.GetData(B.GetIndex(j, i));
				result = left - right;
				Result->SetData(Result->GetIndex(j, i), result);
			}
		}
		ResultMatrix.push_back(*Result);
	}

	// Matrix subtraction
	void MatrixScalarMultiplication(Matrix A, double Scalar)
	{
		int row = A.GetRow();
		int col = A.GetCol();

		Matrix *Result = new Matrix(row, col);
		Result->initialize();

		double result;
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				result = Scalar * A.Vector.GetData(A.GetIndex(j, i));
				;
				Result->SetData(Result->GetIndex(j, i), result);
			}
		}
		ResultMatrix.push_back(*Result);
	}

	// Dot Product
	void MatrixDotProduct(Matrix A, Matrix B)
	{
		if (A.GetCol() != B.GetRow())
		{
			return;
		}
		int row = A.GetRow();
		int col = B.GetCol();

		Matrix *Result = new Matrix(row, col);
		Result->initialize();

		double result;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				node *a_curr_row = A.GetCurrentRow(i);
				node *b_curr_col = B.GetCurrentCol(j);

				for (int k = 0; k < A.GetCol(); k++)
				{
					double curr_result = 0;

					curr_result = a_curr_row->data * b_curr_col->data;
					a_curr_row = a_curr_row->next;

					for (int l = 0; l < B.GetCol(); l++)
					{
						if (b_curr_col->next != nullptr)
						{
							b_curr_col = b_curr_col->next;
						}
					}
					result = result + curr_result;
				}
				Result->SetData(Result->GetIndex(i, j), result);
				result = 0;
			}
		}
		ResultMatrix.push_back(*Result);
	}
	
	// Get determinant
	static double MatrixGetDeterminant(Matrix* A){
		if(A->GetCol() != A->GetRow()){
			return 1;
		}
		A = Matrix::UpperTriangular(A);
		double result = 1;
		for(int i = 0; i < A->GetRow();i++){
			result *= A->GetPivot(i)->data;
		}
		if(A->GetGaussSwap()){
			result *= -1;
		}
		return result;		
	}
				
};
int main()
{
	MatrixOperation O;

	Matrix* M = new Matrix(3, 3);
	Matrix *S = new Matrix(2, 3);
	
	Matrixes.push_back(*M);
	Matrixes.push_back(*S);
	
	string str = "[2,7,5,8,9,2]";
	Matrixes[0].ScanString(str);
	
	//S->ScanString("[-5,6,8,-2,8,9]");
	//O.MatrixDotProduct(Matrixes[0],Matrixes[1]);
	//double det = MatrixOperation::MatrixGetDeterminant(&Matrixes[0]);
	//ResultMatrix[0].Print();
}