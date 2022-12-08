#include <iostream>
using namespace std;

class RuntimeException
{

    string msg;

public:
    RuntimeException(string err)
    {
        msg = err;
    }
    string getmssg()
    {
        return msg;
    }
};

class illegalParameterException : public RuntimeException
{
public:
    illegalParameterException(const string &msg) : RuntimeException(msg) {}
};

class matrixIndexOutOfBounds : public RuntimeException
{
public:
    matrixIndexOutOfBounds(const string &msg) : RuntimeException(msg) {}
};

template <typename T>
class diagonalMatrix
{
public:
    diagonalMatrix(int theN = 10)
    {
        if (theN < 1)
            throw illegalParameterException("Matrix Size Must be > 0\n");
        n = theN;
        element = new T[n];
    }

    ~diagonalMatrix()
    {
        delete[] element;
    }

    T get(int i, int j) const
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw matrixIndexOutOfBounds("Index Out Of Bounds\n");
        if (i == j)
        {
            return element[i-1];
        }
        else
        {
            return 0;
        }
    }

    void set(int i, int j, const T &newValue)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw matrixIndexOutOfBounds("Index Out Of Bounds\n");

        if (i == j)
            element[i - 1] = newValue;
        else
        {
            if (newValue != 0)
                throw illegalParameterException("Non-Diagonal Elements Must be 0\n");
        }
    }

    void input()
    {
        T val;
        for (int i = 1,j=1; i <= n; i++,j++)
        {

            cout << "Enter the Value of Element [" << i - 1 << "," << j - 1 << "] : ";
            cin >> val;
            set(i, j, val);
        }
    }

    void display()
    {
        cout << "\n  Diagonal Matrix\n";
        cout << "-------------------\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                T val = get(i, j);
                cout << val << "\t";
            }
            cout << "\n";
        }
    }

private:
    int n;
    T *element;
};
