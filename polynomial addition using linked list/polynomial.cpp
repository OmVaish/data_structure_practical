#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void addLast(int data){
        Node* nn = new Node(data);
        if(head == NULL){
            head = nn;
            tail = nn;
        }
        else{
            tail->next = nn;
            tail = nn;
        }
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"";
    }
    int size(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    void addFirst(int data){
        Node* nn = new Node(data);
        if(head == NULL){
            head = nn;
            tail = nn;
        }
        else{
            nn->next = head;
            head = nn;
        }
    }
    void addAt(int data, int idx){
        if(idx < 0 || idx > size()){
            cout<<"Invalid arguments";
        }
        else if(idx == 0){
            addFirst(data);
        }
        else if(idx == size()){
            addLast(data);
        }
        else{
            Node* nn = new Node(data);
            Node* temp = head;
            for(int i = 0; i < idx - 1; i++){
                temp = temp->next;
            }
            nn->next = temp->next;
            temp->next = nn;
        }
    }
    int getFirst(){
        if(head == NULL){
            cout<<"List is empty";
            return -1;
        }
        else{
            return head->data;
        }
    }
    int getLast(){
        if(head == NULL){
            cout<<"List is empty";
            return -1;
        }
        else{
            return tail->data;
        }
    }
    int getAt(int idx){
        if(head == NULL){
            cout<<"List is empty";
            return -1;
        }
        else if(idx < 0 || idx >= size()){
            cout<<"Invalid arguments";
            return -1;
        }
        else{
            Node* temp = head;
            for(int i = 0; i < idx; i++){
                temp = temp->next;
            }
            return temp->data;
        }
    }
    void removeFirst(){
        if(head == NULL){
            cout<<"List is empty";
        }
        else if(head == tail){
            head = NULL;
            tail = NULL;
        }
        else{
            head = head->next;
        }
    }
    void removeLast(){
        if(head == NULL){
            cout<<"List is empty";
        }
        else if(head == tail){
            head = NULL;
            tail = NULL;
        }
        else{
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
        }
    }
};
class Polynomial{
public:
    LinkedList* list;
    Polynomial(){
        list = new LinkedList();
    }
    void addTerm(int coeff, int exp){
        list->addLast(coeff);
        list->addLast(exp);
    }
    void display(){
        Node* temp = list->head;
        while(temp != NULL){
            cout<<temp->data<<"x^"<<temp->next->data;
            temp = temp->next->next;
            if(temp != NULL){
                cout<<" + ";
            }
        }
        cout<<"";
        cout<<endl;
    }
    Polynomial* add(Polynomial* p){
        Polynomial* res = new Polynomial();
        Node* temp1 = list->head;
        Node* temp2 = p->list->head;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->next->data == temp2->next->data){
                int coeff = temp1->data + temp2->data;
                int exp = temp1->next->data;
                res->addTerm(coeff, exp);
                temp1 = temp1->next->next;
                temp2 = temp2->next->next;
            }
            else if(temp1->next->data > temp2->next->data){
                int coeff = temp1->data;
                int exp = temp1->next->data;
                res->addTerm(coeff, exp);
                temp1 = temp1->next->next;
            }
            else{
                int coeff = temp2->data;
                int exp = temp2->next->data;
                res->addTerm(coeff, exp);
                temp2 = temp2->next->next;
            }
        }
        while(temp1 != NULL){
            int coeff = temp1->data;
            int exp = temp1->next->data;
            res->addTerm(coeff, exp);
            temp1 = temp1->next->next;
        }
        while(temp2 != NULL){
            int coeff = temp2->data;
            int exp = temp2->next->data;
            res->addTerm(coeff, exp);
            temp2 = temp2->next->next;
        }
        return res;
    }
};
int main()
{
    Polynomial p1;
    p1.addTerm(1, 2);
    p1.addTerm(2, 1);
    p1.addTerm(3, 0);
    p1.display();
    Polynomial p2;
    p2.addTerm(3, 2);
    p2.addTerm(2, 1);
    p2.addTerm(1, 0);
    p2.display();
    Polynomial* p3 = p1.add(&p2);
    p3->display();
    return 0;
}