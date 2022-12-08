#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
#include <queue>
#include <deque>
#include <stack>

using namespace std;
using std::deque;
using std::list;
using std::queue;
using std::stack;
using std::vector;

int main()
{
    int ch;
    float n;
    vector<float> vec1;
    list<float> list1;
    queue<float> que1;
    deque<float> deq1;
    stack<float> stck1;

    do
    {
        system("CLS");
        cout << "\n****MAIN MENU****";
        cout << "\n1.Vectors";
        cout << "\n2.Lists";
        cout << "\n3.Queue";
        cout << "\n4.Dequeue";
        cout << "\n5.Stack";
        cout << "\n6.Exit";
        cout << "\nEnter Choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                system("CLS");
                do
                {
                    cout << "\n***VECTOR MENU***";
                    cout << "\n1.Determine the size";
                    cout << "\n2.Check for empty";
                    cout << "\n3.Resize";
                    cout << "\n4.Reserve";
                    cout << "\n5.Know the first element";
                    cout << "\n6.Know the last element";
                    cout << "\n7.Know the element at a given position";
                    cout << "\n8.Add an element at the end";
                    cout << "\n9.Remove an element from the end";
                    cout << "\n10.Display";
                    cout << "\n11.Back to main menu";
                    cout << "\nEnter Choice: ";
                    cin >> ch;

                    switch (ch)
                    {
                        case 1:
                            cout << "\nSize of the vector is: " << vec1.size();
                            break;
                        case 2:
                            if (vec1.empty())
                                cout << "\nThe vector is empty !";
                            else
                                cout << "\nThe vector is non - empty !";
                            break;
                        case 3:
                            cout << "Enter the size to be resized to: ";
                            cin >> n;
                            vec1.resize(n);
                            cout << "\nThe vector is Resized !";
                            cout << "\nThe size is: " << vec1.size();
                            cout << "\nThe capacity is: " << vec1.capacity();
                            break;
                        case 4:
                            cout << "Enter the size to be reserved: ";
                            cin >> n;
                            vec1.reserve(n);
                            cout << "\nThe size is: " << vec1.size();
                            cout << "\nThe capacity is: " << vec1.capacity();
                            break;
                        case 5:
                            if (!vec1.empty())
                                cout << "\nThe first element is: " << vec1.front();
                            else
                                cout << "\nThe vector is empty ! ";
                            break;
                        case 6:
                            if (!vec1.empty())
                                cout << "\nThe last element is: " << vec1.back();
                            else
                                cout << "\nThe vector is empty ! ";
                            break;
                        case 7:
                            cout << "Enter the position: ";
                            cin >> n;
                            cout << "\nElement at position " << n << " is: " << vec1.at(n);
                            break;
                        case 8:
                            cout << "Enter the element to be added: ";
                            cin >> n;
                            vec1.push_back(n);
                            cout << "\nElement pushed !";
                            break;
                        case 9:
                            if (!vec1.empty())
                            {
                                vec1.pop_back();
                                cout << "\nElement popped !";
                            }
                            else
                                cout << "\nThe vector is empty !";
                            break;
                        case 10:
                            if (!vec1.empty())
                            {
                                cout << "\nThe contents of the vector are:\n";
                                for (int i = 0; i < vec1.size(); i++)
                                    cout << vec1[i] << " ";
                            }
                            else
                                cout << "\nThe vector is empty !";
                            break;
                        case 11:
                            break;
                        default:
                            cout << "\nInvalid Option ! (1-11)";
                    }
                } while (ch != 11);
                break;
            case 2:
                system("CLS");
                do
                {
                    cout << "\n***LIST MENU***";
                    cout << "\n1.Determine the size";
                    cout << "\n2.Check for empty";
                    cout << "\n3.Know the first element";
                    cout << "\n4.Know the last element";
                    cout << "\n5.Add an element at the front";
                    cout << "\n6.Add an element at the end";
                    cout << "\n7.Remove an element from the front";
                    cout << "\n8.Remove an element from the end";
                    cout << "\n9.Display";
                    cout << "\n10.Back to main menu";
                    cout << "\nEnter Choice: ";
                    cin >> ch;

                    switch (ch)
                    {
                        case 1:
                            cout << "\nSize of the list is: " << list1.size();
                            break;
                        case 2:
                            if (list1.empty())
                                cout << "\nThe list is empty !";
                            else
                                cout << "\nThe list is non - empty !";
                            break;
                        case 3:
                            if (!list1.empty())
                                cout << "\nThe first element is: " << list1.front();
                            else
                                cout << "\nThe list is empty !";
                            break;
                        case 4:
                            if (!list1.empty())
                                cout << "\nThe last element is: " << list1.back();
                            else
                                cout << "\nThe list is empty !";
                            break;
                        case 5:
                            cout << "Enter the element to be added: ";
                            cin >> n;
                            list1.push_front(n);
                            cout << "\nElement pushed !";
                            break;
                        case 6:
                            cout << "Enter the element to be added: ";
                            cin >> n;
                            list1.push_back(n);
                            cout << "\nElement pushed !";
                            break;
                        case 7:
                            if (!list1.empty())
                            {
                                list1.pop_front();
                                cout << "\nElement popped !";
                            }
                            else
                                cout << "\nThe list is empty !";
                            break;
                        case 8:
                            if (!list1.empty())
                            {
                                list1.pop_back();
                                cout << "\nElement popped !";
                            }
                            else
                                cout << "\nThe list is empty !";
                            break;
                        case 9:
                            if (!list1.empty())
                            {
                                cout << "\nContents of the list are:\n";
                                list<float>::iterator it;
                                for (it = list1.begin(); it != list1.end(); ++it)
                                {
                                    cout << *it << " ";
                                }
                            }
                            else
                                cout << "\nThe list is empty !";
                            break;
                        case 10:
                            break;
                        default:
                            cout << "\nInvalid Option ! (1-10)";
                    }
                } while (ch != 10);
                break;
            case 3:
                system("CLS");
                do
                {
                    cout << "\n***QUEUE MENU***";
                    cout << "\n1.Determine the size";
                    cout << "\n2.Check for empty";
                    cout << "\n3.Know the first element";
                    cout << "\n4.Know the last element";
                    cout << "\n5.Add an element";
                    cout << "\n6.Remove an element";
                    cout << "\n7.Display";
                    cout << "\n8.Back to main menu";
                    cout << "\nEnter Choice: ";
                    cin >> ch;

                    switch (ch)
                    {
                        case 1:
                            cout << "\nSize of the queue is: " << que1.size();
                            break;
                        case 2:
                            if (que1.empty())
                                cout << "\nThe queue is empty !";
                            else
                                cout << "\nThe queue is non - empty !";
                            break;
                        case 3:
                            if (!que1.empty())
                                cout << "\nThe first element is: " << que1.front();
                            else
                                cout << "\nThe queue is empty !";
                            break;
                        case 4:
                            if (!que1.empty())
                                cout << "\nThe last element is: " << que1.back();
                            else
                                cout << "\nThe queue is empty !";
                            break;
                        case 5:
                            cout << "Enter the element to be added: ";
                            cin >> n;
                            que1.push(n);
                            cout << "\nElement pushed !";
                            break;
                        case 6:
                            if (!que1.empty())
                            {
                                que1.pop();
                                cout << "\nElement popped !";
                            }
                            else
                                cout << "\nThe queue is empty !";
                            break;
                        case 7:
                            if (!que1.empty())
                            {
                                queue<float> q = que1;
                                cout << "\nContents of the list are:\n";
                                while (!q.empty())
                                {
                                    cout << q.front() << " ";
                                    q.pop();
                                }
                            }
                            else
                                cout << "\nThe queue is empty !";
                            break;
                        case 8:
                            break;
                        default:
                            cout << "\nInvalid Option ! (1-8)";
                    }
                } while (ch != 8);
                break;
            case 4:
                system("CLS");
                do
                {
                    cout << "\n***DEQUEUE MENU***";
                    cout << "\n1.Determine the size";
                    cout << "\n2.Check for empty";
                    cout << "\n3.Know the first element";
                    cout << "\n4.Know the last element";
                    cout << "\n5.Add an element at front";
                    cout << "\n6.Add an element at back";
                    cout << "\n7.Remove an element from front";
                    cout << "\n8.Remove an element from back";
                    cout << "\n9.Display";
                    cout << "\n10.Back to main menu";
                    cout << "\nEnter Choice: ";
                    cin >> ch;

                    switch (ch)
                    {
                        case 1:
                            cout << "\nSize of the queue is: " << deq1.size();
                            break;
                        case 2:
                            if (deq1.empty())
                                cout << "\nThe dequeue is empty !";
                            else
                                cout << "\nThe dequeue is non - empty !";
                            break;
                        case 3:
                            if (!deq1.empty())
                                cout << "\nThe first element is: " << deq1.front();
                            else
                                cout << "\nThe dequeue is empty !";
                            break;
                        case 4:
                            if (!deq1.empty())
                                cout << "\nThe last element is: " << deq1.back();
                            else
                                cout << "\nThe dequeue is empty !";
                            break;
                        case 5:
                            cout << "Enter the element to be added: ";
                            cin >> n;
                            deq1.push_front(n);
                            cout << "\nElement pushed !";
                            break;
                        case 6:
                            cout << "Enter the element to be added: ";
                            cin >> n;
                            deq1.push_back(n);
                            cout << "\nElement pushed !";
                            break;
                        case 7:
                            if (!deq1.empty())
                            {
                                deq1.pop_front();
                                cout << "\nElement popped !";
                            }
                            else
                                cout << "\nThe Dequeue is empty !";
                            break;
                        case 8:
                            if (!deq1.empty())
                            {
                                deq1.pop_back();
                                cout << "\nElement popped !";
                            }
                            else
                                cout << "\nThe Dequeue is empty !";
                            break;
                        case 9:
                            if (!deq1.empty())
                            {
                                deque<float> q = deq1;
                                cout << "\nContents of the list are:\n";
                                while (!q.empty())
                                {
                                    cout << q.front() << " ";
                                    q.pop_front();
                                }
                            }
                            else
                                cout << "\nThe Dequeue is empty !";
                            break;
                        case 10:
                            break;
                        default:
                            cout << "\nInvalid Option ! (1-10)";
                    }
                } while (ch != 10);
                break;
            case 5:
                system("CLS");
                do
                {
                    cout << "\n***STACK MENU***";
                    cout << "\n1.Determine the size";
                    cout << "\n2.Check for empty";
                    cout << "\n3.Know the Top";
                    cout << "\n4.Push an element";
                    cout << "\n5.Pop an element";
                    cout << "\n6.Display";
                    cout << "\n7.Back to main menu";
                    cout << "\nEnter Choice: ";
                    cin >> ch;

                    switch (ch)
                    {
                        case 1:
                            cout << "\nSize of the stack is: " << stck1.size();
                            break;
                        case 2:
                            if (stck1.empty())
                                cout << "\nThe stack is empty !";
                            else
                                cout << "\nThe stack is non - empty !";
                            break;
                        case 3:
                            if (!stck1.empty())
                                cout << "\nThe Top is: " << stck1.top();
                            else
                                cout << "\nThe stack is empty !";
                            break;
                        case 4:
                            cout << "Enter the element to be added: ";
                            cin >> n;
                            stck1.push(n);
                            cout << "\nElement pushed !";
                            break;
                        case 5:
                            if (!stck1.empty())
                            {
                                stck1.pop();
                                cout << "\nElement popped !";
                            }
                            else
                                cout << "\nThe stack is empty !";
                            break;
                        case 6:
                            if (!stck1.empty())
                            {
                                stack<float> q = stck1;
                                cout << "\nContents of the list are:\n";
                                while (!q.empty())
                                {
                                    cout << q.top() << " ";
                                    q.pop();
                                }
                            }
                            else
                                cout << "\nThe stack is empty !";
                            break;
                        case 7:
                            break;
                        default:
                            cout << "\nInvalid Option ! (1-7)";
                    }
                } while (ch != 7);
                break;
            case 6:
                cout << "\nExiting";
                break;
            default:
                cout << "\nInvalid Choice !";
        }
    } while (ch != 6);
}