#include <iostream>
using namespace std;

template <typename T>
class LowerTri
{
public:
    LowerTri(int theN = 10)
    {
        if (theN < 1)
            throw illegalParameterException("Matrix Size Must be > 0\n");
        n = theN;
        element = new T[n];
    }

    ~LowerTri()
    {
        delete[] element;
    }

    T get(int i, int j) const
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw matrixIndexOutOfBounds("Index Out Of Bounds\n");
        if (i >= j)
            return element[i * (i - 1) / 2 + j - 1];
        else
            return 0;
    }

    void set(int i, int j, const T &newValue)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw matrixIndexOutOfBounds("Index Out Of Bounds\n");

        if (i >= j)
            element[i * (i - 1) / 2 + j - 1] = newValue;
        else if (newValue != 0)
            throw illegalParameterException("Upper Triangular Elements Must be 0\n");
    }

    void input(int size)
    {
        T val;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "Enter the Value of Element [" << i - 1 << "," << j - 1 << "] : ";
                cin >> val;
                set(i, j, val);
            }
        }
    }

    void display()
    {
        cout << "\nLower Triangular Matrix\n";
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
