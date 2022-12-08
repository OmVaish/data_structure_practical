#include <iostream>
using namespace std;

template <typename T>
class triDiaogMatrix
{
public:
    triDiaogMatrix(int theN = 10)
    {
        if (theN < 1)
            throw illegalParameterException("Matrix Size Must be > 0\n");
        n = theN;
        element = new T[n];
    }

    ~triDiaogMatrix()
    {
        delete[] element;
    }

    T get(int i, int j) const
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw matrixIndexOutOfBounds("Index Out Of Bounds\n");
        switch (i - j)
        {
        case 1:
            return element[i - 2];
        case 0:
            return element[n + i - 2];
        case -1:
            return element[2 * n + i - 2];
        default:
            return 0;
        }
    }

    void set(int i, int j, const T &newValue)
    {
        if (i < 1 || j < 1 || i > n || j > n)
            throw matrixIndexOutOfBounds("Index Out Of Bounds\n");

        else
        {
            switch (i - j)
            {
            case 1:
                element[i - 2] = newValue;
                break;
            case 0:
                element[n + i - 2] = newValue;
                break;
            case -1:
                element[2 * n + i - 2] = newValue;
                break;
            default:
                if (newValue != 0)
                    throw illegalParameterException("Non-Tri-Diagonal Elements Must be 0\n");
            }
        }
    }

    void input(int size)
    {
        T val;
        //main diagonal
        for (int i = 1,j=1; i <=size; i++,j++)
        {

            cout << "Enter the Value of Element [" << i - 1 << "," << j - 1 << "] : ";
            cin >> val;
            set(i, j, val);
        }
        //lower diagonal 
        for (int i = 2,j=1; j <= size-1; i++,j++)
        {

            cout << "Enter the Value of Element [" << i - 1 << "," << j - 1 << "] : ";
            cin >> val;
            set(i, j, val);
        }
        //upper diagonal
        for (int i = 1,j=2; i <= size-1; i++,j++)
        {

            cout << "Enter the Value of Element [" << i - 1 << "," << j - 1 << "] : ";
            cin >> val;
            set(i, j, val);
        }
    }

    void display()
    {
        cout << "\nTri-Diagonal Matrix\n";
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
