#include<iostream>
using namespace std;

template<typename E> class SinglyLinkList{
    public:
        SinglyLinkList();
        int size() const;
        bool empty() const;
        const E& front() const;
        void addFront(const E& e);
        int removeFront();
        void clear();
        void display();
        SinglyLinkList<E> operator+(const SinglyLinkList& L);
        SinglyLinkList<E> operator=(const SinglyLinkList& L);
        void concat(const SinglyLinkList& L1,const SinglyLinkList& L2);
        ~SinglyLinkList();
    private:
        struct Node{
            E element;
            Node* next;
        };
        Node* head;
        int n;
};
template<typename E> SinglyLinkList<E>::SinglyLinkList(): head(NULL), n(0) {}
template<typename E> int SinglyLinkList<E>::size() const { return n; }
template<typename E> bool SinglyLinkList<E>::empty() const { return (n == 0); }
template<typename E> const E& SinglyLinkList<E>::front() const{
    if(empty()) {
        cout<<"Front of empty list"<<endl;
        exit(1);
    }
    else return head->element;
}
template<typename E> void SinglyLinkList<E>::addFront(const E& e){
    Node* v = new Node;
    v->element = e;
    v->next = head;
    head = v;
    n++;
}
template<typename E> int SinglyLinkList<E>::removeFront(){
    if(empty()) {
        cout<<"Remove front of empty list"<<endl;
        exit(1);
    }
    else {
        Node* old = head;
        head = old->next;
        delete old;
        n--;
    }
}
template<typename E> void SinglyLinkList<E>::clear(){
    while(!empty()) removeFront();
}
template<typename E> void SinglyLinkList<E>::display(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->element<<" ";
        temp = temp->next;
    }
}
template<typename E> SinglyLinkList<E>::~SinglyLinkList(){
    clear();
}
template<typename E> SinglyLinkList<E> SinglyLinkList<E>::operator+(const SinglyLinkList& L){
    SinglyLinkList<E> temp;
    Node* temp1 = head;
    Node* temp2 = L.head;
    while(temp1 != NULL){
        temp.addFront(temp1->element);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        temp.addFront(temp2->element);
        temp2 = temp2->next;
    }
    return temp;
}
template<typename E> SinglyLinkList<E> SinglyLinkList<E>::operator=(const SinglyLinkList& L){
    Node* p = new Node;
    SinglyLinkList<E> NewSList;
    clear();
    p = L.head;
    while (p != NULL)
    {
        this->addFront(p->element);
        p = p->next;
    }
    return (*this);
}
template<typename E> void SinglyLinkList<E>::concat(const SinglyLinkList& L1,const SinglyLinkList& L2){
    clear();
    Node* temp1 = L1.head;
    Node* temp2 = L2.head;
    while(temp1 != NULL){
        addFront(temp1->element);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        addFront(temp2->element);
        temp2 = temp2->next;
    }
}
int main()
{
    SinglyLinkList<int> L1;
    SinglyLinkList<int> L2,L4,L5;
    L1.addFront(1);
    L1.addFront(2);
    L1.addFront(3);
    L1.addFront(4);
    L2.addFront(5);
    L2.addFront(6);
    L2.addFront(7);
    L2.addFront(8);
    cout<<"Addition"<<endl;
    SinglyLinkList<int> L3 = L1 + L2;
    L3.display();
    cout<<endl;
    cout<<"Concatenation"<<endl;
    L4.concat(L1,L2);
    L4.display();
    cout<<endl;
    cout<<"Assignment"<<endl;
    L5 = L1;
    L5.display();
    cout<<endl;

    return 0;
}