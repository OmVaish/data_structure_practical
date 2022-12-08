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

class StackEmpty : public RuntimeException{
    public:
    StackEmpty(const string &msg) : RuntimeException(msg) {}
};

class StackFull : public RuntimeException {
    public:
    StackFull(const string &msg) : RuntimeException(msg) {}
};

template <typename E>
class Stack{

        enum{Default_capacity = 100};
        E *S;
        int capacity;
        int t;

    public:

        Stack(int cap=Default_capacity){
            S= new E[cap];
            capacity=cap;
            t=-1;
        }
        Stack(Stack &arr1){
            capacity=arr1.capacity;
            t=arr1.t;
            S = new E[capacity];
            for(int i=0;i<= t;i++)
            {
                S[i]=arr1.S[i];
            }
        }
        int size() const{
            return (t+1);
        }
        bool empty() const{
            return (t<0);
        }
        const E &top(){
            if(empty()){
                throw StackEmpty("The Stack is Empty!");
            }
            else
             return S[t];
        }
        void clear(){
            if(empty())
                throw StackEmpty("Stack is Already Empty");
            t=-1;
            cout<<"The Stack is now Empty"<<endl;
        }
        void push(const E &e){
            if(size()==capacity)
                throw StackFull("The Stack is Full.");
            else
                S[++t]=e;
        }
        void pop(){
            if(empty())
                throw StackEmpty("Stack is Already Empty");
            else
                --t;
        }
        E get_Value(){
            E value;
            cin>>value;
            return value;

        }
        void display(){
            if(empty())
                throw StackEmpty("STACK EMPTY");
            int num=t;
            for(num;num>=0;num--){
                cout<<S[num]<<endl;
            }
        }
        void operator=(Stack &stack1)
        {
        capacity = stack1.capacity;
        t = stack1.t;
        S = new E[capacity];

        for (int i = 0; i <= t; i++)
        {
            S[i] = stack1.S[i];
        }
        }
        ~Stack()
        {
        S = nullptr;
        }
};



int main()
{
    int size,n;
    int choice;
    cout<<"Enter the Size : ";
    cin>>size;
    Stack <int> s1(size);
    Stack <int> s2(size);

    do
    {
    cout<<" ____MENU____"<<endl;
    cout<<"1.Size "<<endl;
    cout<<"2.Top "<<endl;
    cout<<"3.Is Empty ? "<<endl;
    cout<<"4.Push "<<endl;
    cout<<"5.Pop "<<endl;
    cout<<"6.Display "<<endl;
    cout<<"7.Clear "<<endl;
    cout<<"8.Create a Copy "<<endl;
    cout<<"9.Exit "<<endl;
    cout<<"_________________"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1: try
                {cout<<"The Size of the Stack is : "<<s1.size()<<endl;}
                catch (RuntimeException &e)
                {
                cout << e.getmssg()<<endl;
                }
                break;
        case 2: try
                {cout<<s1.top()<<endl;}
                catch (RuntimeException &e)
                {
                cout << e.getmssg()<<endl;
                }
                break;
        case 3: try{if(s1.empty())
                    cout<<"The Stack is Empty"<<endl;
                else
                    cout<<"The Stack is not Empty"<<endl;}
                catch (RuntimeException &e)
                {
                cout << e.getmssg()<<endl;
                }
                break;
        case 4: try{cout<<"Enter the value to be pushed : ";
                s1.push(s1.get_Value());}
                catch (RuntimeException &e)
                {
                cout << e.getmssg()<<endl;
                }
                break;
        case 5: try{s1.pop();}
                catch (RuntimeException &e)
                {
                cout << e.getmssg()<<endl;
                }
                break;
        case 6: try{s1.display();}
                catch (RuntimeException &e)
                {
                cout << e.getmssg()<<endl;
                }
                break;
        case 7: try{s1.clear();}
                catch (RuntimeException &e)
                {
                cout << e.getmssg()<<endl;
                }
                break;
        case 8: try{s2=s1;
                cout<<"Copied Stack : "<<endl;
                s2.display();}
                catch (RuntimeException &e)
                {
                cout << e.getmssg()<<endl;
                }
                break;
        case 9: cout<<"Exiting."<<endl;
                exit(0);
     }

    }while(choice!=9);

    return 0;
}