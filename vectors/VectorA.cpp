#include <iostream>
using namespace std;

class OutOfBounds : exception
{
public:
    OutOfBounds(string err)
    {
        cout << "ERROR Index Out of Bounds: " << err << endl;
    }
};

typedef int Elem;
class ArrayVector
{
private:
    int capacity;
    int n;
    Elem *A;

public:
    ArrayVector();
    int size() const;
    bool empty() const;
    Elem &operator[](int i);
    Elem &at(int i);
    void erase(int i);
    void insert(int i, const Elem &e);
    void reserve(int N);

    void display() const;
    ArrayVector(ArrayVector &obj);
    ~ArrayVector();
    void operator=(ArrayVector &obj);
};

ArrayVector::ArrayVector() : capacity(0), n(0), A(NULL) {}
ArrayVector::ArrayVector(ArrayVector &obj) : capacity(obj.capacity), n(obj.n), A(obj.A) {}

ArrayVector::~ArrayVector()
{
    while (!empty())
        erase(0);
}

int ArrayVector::size() const
{
    return n;
}

bool ArrayVector::empty() const
{
    return (n == 0);
}

Elem &ArrayVector::operator[](int i)
{
    return A[i];
}

void ArrayVector::operator=(ArrayVector &obj)
{
    n = obj.n;
    capacity = obj.capacity;
    A = obj.A;
}

Elem &ArrayVector::at(int i)
{
    if (i < 0 || i > n)
        throw new OutOfBounds("Can't find the index from function at()");

    return A[i];
}

void ArrayVector::erase(int i)
{
    for (int j = i + 1; j < n; j++)
        A[j - 1] = A[j];

    n--;
}

void ArrayVector::insert(int i, const Elem &e)
{
    if (n >= capacity)
        reserve(max(1, 2 * capacity));

    for (int j = n - 1; j >= 1; j--)
        A[j + 1] = A[j];

    A[i] = e;
    n++;
}

void ArrayVector::reserve(int N)
{
    if (capacity == N)
        return;

    Elem *B = new Elem[N];

    for (int j = 0; j < n; j++)
        B[j] = A[j];

    if (A != NULL)
        delete[] A;

    A = B;
    capacity = N;
}

void ArrayVector::display() const
{
    if (empty())
    {
        cout << "The Array Vector is empty" << endl;
        return;
    }

    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "]" << endl;
}

int main()
{
    ArrayVector a;

    a.display();

    cout << "Inserting 3 elements: " << endl;
    a.insert(0, 1);
    a.insert(1, 2);
    a.insert(2, 3);
    a.display();

    cout << "first elem: " << a.at(0) << endl;

    cout << "Insert in between: " << endl;
    a.insert(1, 5);
    a.display();

    cout << "Remove an element: " << endl;
    a.erase(2);
    a.display();

    cout << "After using copy constructor: " << endl;
    ArrayVector b(a);
    b.display();

    cout << "After using assignement operator: " << endl;
    ArrayVector c;
    c = a;
    c.display();

    return 0;
}