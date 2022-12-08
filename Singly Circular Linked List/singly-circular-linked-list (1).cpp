#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class SinglyCircularLinkedList{
    public:
        Node *head;
        SinglyCircularLinkedList(){
            head = NULL;
        }
        void insertAtHead(int data){
            Node *newNode = new Node(data);
            if(head == NULL){
                head = newNode;
                newNode->next = head;
            }
            else{
                Node *temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
                head = newNode;
            }
        }

        void insertAfter(int data, int after){
            Node *newNode = new Node(data);
            Node *temp = head;
            while(temp->data != after){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void insertAtTail(int data){
            Node *newNode = new Node(data);
            Node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }

        void deleteAtTail(){
            Node *temp = head;
            while(temp->next->next != head){
                temp = temp->next;
            }
            temp->next = head;
        }

        void deleteAtHead(){
            Node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
        }

        void remove(int data){
            Node *temp = head;
            while(temp->next->data != data){
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }

        Node *search(int data){
            Node *temp = head;
            while(temp->data != data){
                temp = temp->next;
            }
            return temp;
        }

        void concatinate(SinglyCircularLinkedList *list){
            Node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = list->head;
            Node *temp2 = list->head;
            while(temp2->next != list->head){
                temp2 = temp2->next;
            }
            temp2->next = head;
        }

        void reverse(){
            Node *prev = NULL;
            Node *current = head;
            Node *next = NULL;
            do{
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }while(current != head);
            head = prev;
        }

        void display(){
            Node *temp = head;
            while(temp->next != head){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<endl;
        }

        int countNodes(){
            int count = 0;
            Node *temp = head;
            do{
                count++;
                temp = temp->next;
            }while(temp != head);
            return count;
        }

        void removeElement(int data){
            Node *temp = head;
            while(temp->next->data != data){
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }     
};

int main()
{
    SinglyCircularLinkedList l1,l2;

    while(1){
        cout<<"1. Insert at head"<<endl;
        cout<<"2. Insert after"<<endl;
        cout<<"3. Insert at tail"<<endl;
        cout<<"4. Delete at head"<<endl;
        cout<<"5. Delete at tail"<<endl;
        cout<<"6. Remove"<<endl;
        cout<<"7. Search"<<endl;
        cout<<"8. Concatinate"<<endl;
        cout<<"9. Reverse"<<endl;
        cout<<"10. Display"<<endl;
        cout<<"11. Count Nodes"<<endl;
        cout<<"12. Remove Element"<<endl;
        cout<<"13. Exit"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                int data;
                cout<<"Enter data: ";
                cin>>data;
                l1.insertAtHead(data);
                break;
            case 2:
                int data1, after;
                cout<<"Enter data: ";
                cin>>data1;
                cout<<"Enter after: ";
                cin>>after;
                l1.insertAfter(data1, after);
                break;
            case 3:
                int data2;
                cout<<"Enter data: ";
                cin>>data2;
                l1.insertAtTail(data2);
                break;
            case 4:
                l1.deleteAtHead();
                break;
            case 5:
                l1.deleteAtTail();
                break;
            case 6:
                int data3;
                cout<<"Enter data: ";
                cin>>data3;
                l1.remove(data3);
                break;
            case 7:
                int data4;
                cout<<"Enter data: ";
                cin>>data4;
                Node *temp = l1.search(data4);
                cout<<"Data found at "<<temp<<endl;
                break;
            case 8:
                int data5;
                cout<<"Enter data: ";
                cin>>data5;
                l2.insertAtHead(data5);
                l1.concatinate(&l2);
                break;
            case 9:
                l1.reverse();
                break;
            case 10:
                l1.display();
                break;
            case 11:
                cout<<"Number of nodes: "<<l1.countNodes()<<endl;
                break;
            case 12:
                int data6;
                cout<<"Enter data: ";
                cin>>data6;
                l1.removeElement(data6);
                break;
            case 13:
                exit(0);
    }
    }
    return 0;
}