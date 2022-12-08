#include<bits/stdc++.h>
using namespace std;
template <class T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
        Node(T data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};
template <class T> class SinglyLinkedList{
    public:
        Node<T> *head;
        Node<T> *tail;
        SinglyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
        }
        ~SinglyLinkedList();
        bool isEmpty();
        void addHead(T data);
        void insertAt(T data, int index);
        void count();
        void addTail(T data);
        T deleteHead();
        void removeAt(int index);
        T deleteTail();
        void deleteNode(T data);
        bool search(T data);
        void concat2Lists(SinglyLinkedList<T> *list1, SinglyLinkedList<T> *list2);
        int countNode();
        void display();
        void reverse();
};
template <class T> SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T> *temp = head;
    while (temp != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }
}
template <class T> void SinglyLinkedList<T>::removeAt(int index) {
    Node<T> *temp = head;
    if (index == 0) {
        head = head->next;
        delete temp;
        return;
    }
    for (int i = 0; i < index - 2; i++) {
        temp = temp->next;
    }
    Node<T> *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
    if(index==countNode())
    {
        tail=temp;
    }
}
template <class T> void SinglyLinkedList<T>::concat2Lists(SinglyLinkedList<T> *list1, SinglyLinkedList<T> *list2) {
    Node<T> *temp = list1->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2->head;
    list2->head = NULL;
    delete list2;
}
template <class T> bool SinglyLinkedList<T>::isEmpty() {
    return (head == NULL);
}
template <class T> void SinglyLinkedList<T>::addHead(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}
template <class T> void SinglyLinkedList<T>::count() {
    Node<T> *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "Number of nodes: " << count << endl;
}
template <class T> void SinglyLinkedList<T>::insertAt(T data, int index) {
    if (index == 0) {
        addHead(data);
    } else {
        Node<T> *newNode = new Node<T>(data);
        Node<T> *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    if(index==countNode()-1)
    {
        tail=tail->next;
    }
}

template <class T> void SinglyLinkedList<T>::addTail(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
template <class T> T SinglyLinkedList<T>::deleteHead() {
    if (isEmpty()) {
        throw "List is empty"<<endl;
    }else if(head==tail)
    {
       T data = tail->data;
        Node<T> *temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return data;
    }
    else{
        Node<T> *temp = head;
        T data = head->data;
        head = head->next;
        delete temp;
        return data;
    }
}
template <class T> T SinglyLinkedList<T>::deleteTail() {
    if (isEmpty()) {
        cout<< "List is empty"<<endl;
        return -1;
    }
    else if(head==tail)
    {
        T data = tail->data;
        Node<T> *temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return data;
    }
    else{    
        Node<T> *temp = head;
        T data = tail->data;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
        
        
        return data;
    }
}
template <class T> void SinglyLinkedList<T>::deleteNode(T data) {
    if (isEmpty()) {
        cout<< "List is empty"<<endl;
        return;
    } 
    else if(head==tail)
    {
        Node<T> *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    else {
        Node<T> *temp = head;
        if (head->data == data) {
            head = head->next;
            delete temp;
            return;
        } else {
            while (temp->next != NULL && temp->next->data != data) {
                temp = temp->next;
            }
            if (temp->next != NULL) {
                Node<T> *temp2 = temp->next;
                temp->next = temp2->next;
                if(temp2==tail)
                {
                    tail=temp;
                }
                delete temp2;
                return;
            }
        }
    }
    cout<<"Node with given data is not present in linked list"<<endl;
}
template <class T> bool SinglyLinkedList<T>::search(T data) {
    if (isEmpty()) {
        throw "List is empty"<<endl;
    } else {
        Node<T> *temp = head;
        while (temp != NULL) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}
template <class T> int SinglyLinkedList<T>::countNode() {
    if (isEmpty()) {
        cout<< "List is empty"<<endl;
        return -1;
    } 
        int count = 0;
        Node<T> *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
}
template <class T> void SinglyLinkedList<T>::display() {
    if (isEmpty()) {
        cout<<"List is empty"<<endl;
    } else {
        Node<T> *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
template <class T> void SinglyLinkedList<T>::reverse() {
    if (isEmpty()) {
        throw "List is empty"<<endl;
    } else {
        Node<T> *temp = head;
        Node<T> *temp2 = NULL;
        while (temp != NULL) {
            temp2 = temp->next;
            temp->next = temp->prev;
            temp->prev = temp2;
            temp = temp2;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
}
int main(){
    SinglyLinkedList<int> list;
    do{
        cout<<" 1. Add head\t 2. Insert at\t 3. Count\t 4. Add tail\t 5. Delete head\t 6. Remove at\t 7. Delete tail\n 8. Delete node\t 9. Search\t 10. Concat 2 lists\t 11. Count node\t 12. Display\t 13. Reverse\t 14. Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        
    
        switch(choice){
            case 1: {
                cout<<"Enter data: ";
                int data;
                cin>>data;
                list.addHead(data);
                break;
            }
            case 2: {
                cout<<"Enter data: ";
                int data;
                cin>>data;
                cout<<"Enter index: ";
                int index;
                cin>>index;
                list.insertAt(data, index);
                break;
            }
            case 3: {
                list.count();
                break;
            }
            case 4: {
                cout<<"Enter data: ";
                int data;
                cin>>data;
                list.addTail(data);
                break;
            }
            case 5: {
                cout<<"Deleted data: "<<list.deleteHead()<<endl;
                break;
            }
            case 6: {
                cout<<"Enter index: ";
                int index;
                cin>>index;
                list.removeAt(index);
                break;
            }
            case 7: {
                int a=list.deleteTail();
                if(a!=-1)
                cout<<"Deleted data: "<<a<<endl;
                break;
            }
            case 8: {
                cout<<"Enter data: ";
                int data;
                cin>>data;
                list.deleteNode(data);
                break;
            }
            case 9: {
                cout<<"Enter data: ";
                int data;
                cin>>data;
                if (list.search(data)) {
                    cout<<"Found"<<endl;
                } else {
                    cout<<"Not found"<<endl;
                }
                break;
            }
            case 10: {
                SinglyLinkedList<int> *list1 = new SinglyLinkedList<int>();
                SinglyLinkedList<int> *list2 = new SinglyLinkedList<int>();
                list1->addHead(1);
                list1->addHead(2);
                list1->addHead(3);
                list2->addHead(4);
                list2->addHead(5);
                list2->addHead(6);
                list1->concat2Lists(list1, list2);
                list1->display();
                break;
            }
            case 11: {
                cout<<list.tail->data;
                int a=list.countNode();
                if(a!=-1)
                cout<<"Number of nodes: "<<a<<endl;
                break;
            }
            case 12: {
                list.display();
                break;
            }
            case 13: {
                list.reverse();
                break;
            }
            case 14: {
                exit(0);
            }
        }
    }while(1);
    return 0;
}

