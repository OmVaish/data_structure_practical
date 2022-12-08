#include "DiagonalMatrix.h"
#include "UpperTri.h"
#include "LoweTri.h"
#include "TriDiagMatrix.h"
#include "SymmetricMatrix.h"
#include <iostream>
using namespace std;
int main()
{
    int size, i, j, val, choice, ch;

    cout << "Choose Any : " << endl;
    cout << "--------------------" << endl;
    cout << "1.Diagonal Matrix " << endl;
    cout << "2.Tri-Diagonal Matrix" << endl;
    cout << "3.Upper-Triangular Matrix" << endl;
    cout << "4.Lower-Triangular Matrix" << endl;
    cout << "5.Symmetric Matrix" << endl
         << endl;
    cout << "Enter Your Choice : ";
    cin >> ch;
    cout << endl;

    switch (ch)
    {
    case 1:
    {
        cout << "Enter the Size of the Matrix : ";
        cin >> size;
        diagonalMatrix<int> d1(size);
        try
        {
            d1.input();
        }
        catch (RuntimeException &e)
        {
            cout << e.getmssg();
            exit(0);
        }

        do
        {
            cout << "=======MENU======" << endl;
            cout << "1.Get Element at i,j " << endl;
            cout << "2.Set Element at i,j" << endl;
            cout << "3.Display" << endl;
            cout << "4.Exit" << endl;
            cout << "=================" << endl;

            cout << "Enter your Choice : ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                try
                {
                    cout << "\nElement at [" << i << "," << j << "] : " << d1.get(i, j) << endl;
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 2:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                cout << "Enter the Value to Set : ";
                cin >> val;
                cout << endl;
                try
                {
                    d1.set(i, j, val);
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 3:
                d1.display();
                cout << endl;
                break;
            case 4:
                cout << "Exiting" << endl;
                break;

            default:
                cout << "Enter Valid Choice!!!!" << endl;
                break;
            }
        } while (choice != 4);
    }

    break;
    case 2:
    {
        cout << "Enter the Size of the Matrix : ";
        cin >> size;
        triDiaogMatrix<int> t1(size);
        try
        {
            t1.input(size);
        }
        catch (RuntimeException &e)
        {
            cout << e.getmssg();
            exit(0);
        }

        do
        {
            cout << "=======MENU======" << endl;
            cout << "1.Get Element at i,j " << endl;
            cout << "2.Set Element at i,j" << endl;
            cout << "3.Display" << endl;
            cout << "4.Exit" << endl;
            cout << "=================" << endl;

            cout << "Enter your Choice : ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                try
                {
                    cout << "\nElement at [" << i << "," << j << "] : " << t1.get(i, j) << endl;
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 2:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                cout << "Enter the Value to Set : ";
                cin >> val;
                cout << endl;
                try
                {
                    t1.set(i, j, val);
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 3:
                t1.display();
                cout << endl;
                break;
            case 4:
                cout << "Exiting" << endl;
                break;

            default:
                cout << "Enter Valid Choice!!!!" << endl;
                break;
            }
        } while (choice != 4);
    }
    break;
    case 3:
    {
        cout << "Enter the Size of the Matrix : ";
        cin >> size;
        UpperTri<int> u1(size);
        try
        {
            u1.input(size);
        }
        catch (RuntimeException &e)
        {
            cout << e.getmssg();
            exit(0);
        }

        do
        {
            cout << "=======MENU======" << endl;
            cout << "1.Get Element at i,j " << endl;
            cout << "2.Set Element at i,j" << endl;
            cout << "3.Display" << endl;
            cout << "4.Exit" << endl;
            cout << "=================" << endl;

            cout << "Enter your Choice : ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                try
                {
                    cout << "\nElement at [" << i << "," << j << "] : " << u1.get(i, j) << endl;
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 2:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                cout << "Enter the Value to Set : ";
                cin >> val;
                cout << endl;
                try
                {
                    u1.set(i, j, val);
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 3:
                u1.display();
                cout << endl;
                break;
            case 4:
                cout << "Exiting" << endl;
                break;

            default:
                cout << "Enter Valid Choice!!!!" << endl;
                break;
            }
        } while (choice != 4);
    }
    break;
    case 4:
    {
        cout << "Enter the Size of the Matrix : ";
        cin >> size;
        LowerTri<int> l1(size);
        try
        {
            l1.input(size);
        }
        catch (RuntimeException &e)
        {
            cout << e.getmssg();
            exit(0);
        }

        do
        {
            cout << "=======MENU======" << endl;
            cout << "1.Get Element at i,j " << endl;
            cout << "2.Set Element at i,j" << endl;
            cout << "3.Display" << endl;
            cout << "4.Exit" << endl;
            cout << "=================" << endl;

            cout << "Enter your Choice : ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                try
                {
                    cout << "\nElement at [" << i << "," << j << "] : " << l1.get(i, j) << endl;
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 2:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                cout << "Enter the Value to Set : ";
                cin >> val;
                cout << endl;
                try
                {
                    l1.set(i, j, val);
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 3:
                l1.display();
                cout << endl;
                break;
            case 4:
                cout << "Exiting" << endl;
                break;

            default:
                cout << "Enter Valid Choice!!!!" << endl;
                break;
            }
        } while (choice != 4);
    }
    break;
    case 5:
    {
        cout << "Enter the Size of the Matrix : ";
        cin >> size;
        SymmetricMatrix<int> s1(size);
        try
        {
            s1.input(size);
        }
        catch (RuntimeException &e)
        {
            cout << e.getmssg();
            exit(0);
        }

        do
        {
            cout << "=======MENU======" << endl;
            cout << "1.Get Element at i,j " << endl;
            cout << "2.Set Element at i,j" << endl;
            cout << "3.Display" << endl;
            cout << "4.Exit" << endl;
            cout << "=================" << endl;

            cout << "Enter your Choice : ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                try
                {
                    cout << "\nElement at [" << i << "," << j << "] : " << s1.get(i, j) << endl;
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 2:
                cout << "Enter Value of i : ";
                cin >> i;
                cout << "Enter Value of j : ";
                cin >> j;
                cout << "Enter the Value to Set : ";
                cin >> val;
                cout << endl;
                try
                {
                    s1.set(i, j, val);
                }
                catch (RuntimeException &e)
                {
                    cout << e.getmssg();
                }
                cout << endl;
                break;
            case 3:
                s1.display();
                cout << endl;
                break;
            case 4:
                cout << "Exiting" << endl;
                break;

            default:
                cout << "Enter Valid Choice!!!!" << endl;
                break;
            }
        } while (choice != 4);
    }
    }
}
