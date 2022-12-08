
#include <iostream>

using namespace std;
template<class T>
class twoStacks
{
  T *arr;
  int size;
  int top1;
  int top2;
  public:
  twoStacks(int n)
  {
      arr=new T[n];
      top1=-1;
      top2=n;
      size=n;
  }
   void push1(T x)
    {
        // There is at least one empty space for new element
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        }
        else {
            cout << "Stack Overflow";
            exit(1);
        }
    }
 
    // Method to push an element x to stack2
    void push2(T x)
    {
        // There is at least one empty
        // space for new element
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        }
        else {
            cout << "Stack Overflow";
            exit(1);
        }
    }
 
    // Method to pop an element from first stack
    T pop1()
    {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
 
    // Method to pop an element from second stack
    T pop2()
    {
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
  void display1()
  {
      while(top1>=0)
      {
          cout<<arr[top1]<<" ";
          top1--;
      }
      cout<<endl;
  }
  void display2()
  {
      while(top2<size)
      {
          cout<<arr[top2]<<" ";
          top2++;
      }
      cout<<endl;
  }
};

int main()
{
    twoStacks<int> ts(10);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    cout<<"\nElements of stack1:";
    ts.display1();
    cout<<"Elements of stack1:";
    ts.display2();
    return 0;
}