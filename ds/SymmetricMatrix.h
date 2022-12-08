#include <iostream>
using namespace std;

template <typename T>
class SymmetricMatrix
{
public:
    SymmetricMatrix(int theN = 10)
    {
        if (theN < 1)
            throw illegalParameterException("Matrix Size Must be > 0\n");
        n = theN;
        element = new T[n];
    }

    ~SymmetricMatrix()
    {
        delete[] element;
    }

    T get(int i, int j) const
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw matrixIndexOutOfBounds("Index Out Of Bounds\n");
        if (i <= j)
            return element[j * (j - 1) / 2 + i - 1];
        else
            return element[i * (i - 1) / 2 + j - 1];
    }

    void set(int i, int j, const T &newValue)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw matrixIndexOutOfBounds("Index Out Of Bounds\n");

        if (i <= j)
            element[j * (j - 1) / 2 + i - 1] = newValue;
    }

    void input(int size)
    {
        T val;
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= i; j--)
            {
                cout << "Enter the Value of Element [" << i - 1 << "," << j - 1 << "] : ";
                cin >> val;
                set(i, j, val);
            }
        }
    }

    void display()
    {
        cout << "\nSymmetric Matrix\n";
        cout << "-------------------\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                T val = get(i, j);
                if (i <= j)
                    cout << get(j, i) << "\t";
                else
                    cout << val << "\t";
            }
            cout << "\n";
        }
    }

private:
    int n;
    T *element;
};
