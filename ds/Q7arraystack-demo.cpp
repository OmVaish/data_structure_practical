#include<bits/stdc++.h>
using namespace std;

template <typename E>
class Stack{
    public:
        int size() const;
        bool empty() const;
        const E& top() const;
        void push(const E& e);
        int pop();
        void clear();
        void display();
};


template <typename E>
class ArrayStack: public Stack<E>{
        enum { DEF_CAPACITY = 100 };
    public:
        ArrayStack(int cap = 100);
        ArrayStack(ArrayStack& s);
        ArrayStack operator=(ArrayStack& s){
            delete [] S;
            capacity = s.capacity;
            t = s.t;
            S = new E[capacity];
            for(int i=0; i<=t; i++){
                S[i] = s.S[i];
            }
        };
        int size() const;
        bool empty() const;
        const E& top() const;
        void push(const E& e);
        int pop();
        void clear();
        void display();
        ~ArrayStack();
    private:
        E* S;
        int capacity;
        int t;
};

template <typename E> ArrayStack<E>::ArrayStack(int cap): S(new E[cap]), capacity(cap), t(-1) {}

template <typename E> int ArrayStack<E>::size() const { return (t+1); }

template <typename E> bool ArrayStack<E>::empty() const { return (t < 0); }

template <typename E> const E& ArrayStack<E>::top() const{
    if(empty()) {
        cout<<"Top of empty stack"<<endl;
        exit(1);
    }
    else return S[t];
}

template <typename E> void ArrayStack<E>::push(const E& e){
    if(size() == capacity) {
        cout<<"Push to full stack"<<endl;
        return;
    }
    S[++t] = e;
}

template <typename E> int ArrayStack<E>::pop(){
    if(empty()) {
        cout<<"Pop from empty stack"<<endl;
        return 0;
    }
    return S[t--];
}

template <typename E> void ArrayStack<E>::clear(){
    delete [] S;
    S = new E[DEF_CAPACITY];
    capacity = DEF_CAPACITY;
    t = -1;
}

template <typename E> void ArrayStack<E>::display(){
    for(int i=0; i<=t; i++){
        cout<<S[i]<<" ";
    }
    cout<<endl;
}

template <typename E> ArrayStack<E>::ArrayStack(ArrayStack<E>& s){
    capacity = s.capacity;
    t = s.t;
    S = new E[capacity];
    for(int i=0; i<=t; i++){
        S[i] = s.S[i];
    }
}

template <typename E> ArrayStack<E>::~ArrayStack() { delete [] S; }

// int main(){
//     ArrayStack<int> S;
//     do{
//         int choice;
//         cout<<"Select any operation:\n1.size\n2.is-empty\n3.top\n4.push\n5.pop\n6.clear\n7.display-stack\n8.exit\n";
//         cin>>choice;
//         if(choice==8) break;
//         switch (choice)
//         {
//         case 1:
//             S.size();
//             break;
//         case 2:
//             S.empty();
//             break;
//         case 3:
//             S.top();
//             break;
//         case 4:
//             int x;
//             cout<<"Enter element to be pushed:";
//             cin>>x;
//             S.push(x);
//             break;
//         case 5:
//             S.pop();
//             break;
//         case 6:
//             S.clear();
//             break;
//         case 7:
//             S.display();
//             break;
//         default:
//             cout<<"Invalid choice";
//             break;
//         }
//         cout<<endl;
//     }while(1);
//     return 0;
// }