#include<iostream>
using namespace std;

template<typename E> class LinkListStack{
    public:
        LinkListStack();
        int size() const;
        bool empty() const;
        const E& top() const;
        void push(const E& e);
        int pop();
        void clear();
        void display();
        ~LinkListStack();
    private:
        struct Node{
            E element;
            Node* next;
        };
        Node* head;
        int n;
};
template<typename E> LinkListStack<E>::LinkListStack(): head(NULL), n(0) {}
template<typename E> int LinkListStack<E>::size() const { return n; }
template<typename E> bool LinkListStack<E>::empty() const { return (n == 0); }
template<typename E> const E& LinkListStack<E>::top() const{
    if(empty()) {
        cout<<"Top of empty stack"<<endl;
        exit(1);
    }
    else return head->element;
}
template<typename E> void LinkListStack<E>::push(const E& e){
    Node* v = new Node;
    v->element = e;
    v->next = head;
    head = v;
    n++;
}
template<typename E> int LinkListStack<E>::pop(){
    if(empty()) {
        cout<<"Pop of empty stack"<<endl;
        exit(1);
    }
    else {
        Node* old = head;
        head = old->next;
        delete old;
        n--;
    }
}
template<typename E> void LinkListStack<E>::clear(){
    while(!empty()) pop();
}
template<typename E> void LinkListStack<E>::display(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->element<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
template<typename E> LinkListStack<E>::~LinkListStack(){
    clear();
}


int main()
{
    LinkListStack<int> s;
    do{
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Top"<<endl;
        cout<<"4. Size"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Clear"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to push: ";
                int element;
                cin>>element;
                s.push(element);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout<<"Top element is: "<<s.top()<<endl;
                break;
            case 4:
                cout<<"Size of stack is: "<<s.size()<<endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.clear();
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(1);
    return 0;
}