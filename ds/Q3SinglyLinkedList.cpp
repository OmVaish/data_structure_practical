#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T info;
    node<T> *next;
    node(T el, node<T> *ptr = NULL)
    {
        info = el;
        next = ptr;
    }
};

template <class T>
class SList
{
private:
    node<T> *head, *tail;

public:
    SList() { head = tail = NULL; }
    ~SList();
    bool isEmpty();
    void add_head(T el);
    void add_tail(T el);
    T delete_head();
    T delete_tail();
    void delete_node(T el);
    bool search(T el);
    int count_node();
    void display();
    void reverse();
    void concat(SList<T> &S2);
    // SList<T> &operator=(const SList<T> &l);
};

template <class T>
bool SList<T>::isEmpty()
{
    return head == NULL;
}

template <class T>
SList<T>::~SList()
{
    node<T> *p;
    while (!isEmpty())
    {
        p = head->next;
        delete head;
        head = p;
    }
}

template <class T>
void SList<T>::add_head(T el)
{
    head = new node<T>(el, head);
    if (tail == NULL)
        tail = head;
}

template <class T>
void SList<T>::add_tail(T el)
{
    if (tail != NULL)
    {
        tail->next = new node<T>(el);
        tail = tail->next;
    }
    else
    {
        head = tail = new node<T>(el);
    }
}

template <class T>
T SList<T>::delete_head()
{
    T el = head->info;
    node<T> *temp = head;
    if (head == tail)
        head = tail = NULL;
    else
        head = head->next;
    delete temp;
    return el;
}

template <class T>
T SList<T>::delete_tail()
{
    T el = tail->info;
    if (head == tail)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        node<T> *temp;
        for (temp = head; temp->next != tail; temp = temp = temp->next)
            ;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    return el;
}

template <class T>
bool SList<T>::search(T el)
{
    node<T> *temp;
    for (temp = head; temp != NULL && !(temp->info == el); temp = temp->next)
        ;
    return temp != NULL;
}

template <class T>
void SList<T>::delete_node(T el)
{
    if (head != NULL)
    {
        if (head == tail && el == tail->info)
        {
            delete head;
            head = tail = NULL;
        }
        else if (el == head->info)
        {
            node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            node<T> *pred, *temp;
            for (pred = head, temp = head->next; (temp != NULL) && !(temp->info == el); pred = pred->next, temp = temp->next)
            {
            }
            if (temp != NULL)
            {
                pred->next = temp->next;
                if (temp == tail)
                    tail = pred;
                delete temp;
            }
        }
    }
}

template <class T>
int SList<T>::count_node()
{
    int count = 0;
    node<T> *temp;
    for (temp = head; temp != NULL; temp = temp->next)
        count++;
    return count;
}

template <class T>
void SList<T>::display()
{
    cout << "\n Linked List : ";
    if (!isEmpty())
    {
        node<T> *temp;
        for (temp = head; temp != NULL; temp = temp->next)
            if (temp != tail)
                cout << temp->info << "->";
            else
                cout << temp->info;
        cout << endl;
    }
    else
        cout << "Empty List\n";
}

template <class T>
void SList<T>::reverse()
{
    if (isEmpty())
        return;
    //  else
    node<T> *q, *r, *s;
    q = head;
    r = NULL;
    while (q != NULL)
    {
        s = r;
        r = q;
        q = q->next;
        r->next = s;
    }
    head = r;
    node<T> *p = head;
    while (p->next != NULL)
        p = p->next;
    tail = p;
}

template <class T>
void SList<T>::concat(SList<T> &S2)
{
    node<T> *temp1, *temp2;
    for (temp1 = head; temp1 != NULL; temp1 = temp1->next)
        temp1->next = S2.head;
    for (temp2 = S2.head; temp2 != NULL; temp2 = temp2->next)
        tail = temp2;
}

// template <class T>
// SList<T> &SList<T>::operator=(const SList<T> &l)
// {
//     node<T> *p;
//     T x;
//     while (!isEmpty())
//     {
//         p = head->next;
//         delete head;
//         head = p;
//     }
//     p = l.head;
//     while (p != NULL)
//     {
//         cout << "Inside while" << endl;
//         x = p->info;
//         add_tail(x);
//         p = p->next;
//     }
//     return *this;
// }

/*
    // when no tail is maintained , only head
    void add_tail(T el)
        if(head!=NULL){
            node<T> *temp = new node<T>(el);
            node<T> * n;
            for(n = head;n->next != NULL;n->next);
            n->next = temp;
        }
        else{
            head  = new node<T>(el);
        }
*/

int main()
{
    SList<int> list;
    // SList<int> list2;
    // list1.add_head(1);
    // list1.add_head(2);
    // list1.add_head(3);
    // list1.add_head(4);
    // list1.add_head(5);
    // cout << "original list 1 :" << endl;
    // list1.display();
    // list2.add_head(6);
    // list2.add_head(7);
    // list2.add_head(8);
    // list2.add_head(9);
    // list2.add_head(10);
    // cout << "list 2: " << endl;
    // list2.display();
    // cout << "After assigning" << endl;
    // list1 = list2;
    // list1.display();
    bool flag = true;
    int opr = 0;
    do
    {
        cout << "\n*****     MENU   *****\n"
             << endl;
        cout << "\n   Linked List Operations    \n"
             << endl;
        cout << "   1. Add to head" << endl;
        cout << "   2. Add to tail" << endl;
        cout << "   3. Delete Head" << endl;
        cout << "   4. Delete Tail" << endl;
        cout << "   5. Search Node " << endl;
        cout << "   6. Delete Node" << endl;
        cout << "   7. Reverse List" << endl;
        cout << "   8. Display List" << endl;
        cout << "   9. EXIT" << endl;
        cout << "\n --> Enter your operation : ";
        cin >> opr;
        int temp = 0;
        switch (opr)
        {
        case 1:
            cout << "Enter element to be added at head : ";
            cin >> temp;
            list.add_head(temp);
            break;
        case 2:
            cout << "Enter element to be added at tail : ";
            cin >> temp;
            list.add_tail(temp);
            break;
        case 3:
            if (!list.isEmpty())
            {
                cout << "Elemet deleted from head is :" << list.delete_head() << endl;
                list.display();
            }
            else
                list.display();
            break;
        case 4:
            if (!list.isEmpty())
            {
                cout << "Elemet deleted from tail is :" << list.delete_tail() << endl;
                list.display();
            }
            else
                list.display();
            break;
        case 5:
            cout << "Enter element to be searched : ";
            cin >> temp;
            if (list.search(temp))
                cout << temp << " is present in the list" << endl;
            else
                cout << "Element not found in the list" << endl;
            break;
        case 6:
            cout << "Enter element to be deleted :";
            cin >> temp;
            if (list.search(temp))
            {
                list.delete_node(temp);
                cout << "Element deleted" << endl;
            }
            else
                cout << "Element not present" << endl;
            list.display();
            break;
        case 7:
            cout << "List originally :";
            list.display();
            list.reverse();
            cout << "List after reversing : ";
            list.display();
            break;
        case 8:
            list.display();
            break;
        case 9:
            flag = false;
            break;
        default:
            cout << "Not a valid option " << endl;
            break;
        }
    } while (flag);
    return 0;
}