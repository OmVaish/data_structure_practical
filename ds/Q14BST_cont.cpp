#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;
using std::queue;

template <class T>
class BSTNode
{
public:
    T key;
    BSTNode *left, *right;
    BSTNode()
    {
        left = right = 0;
    }
    BSTNode(const T &el, BSTNode *l = 0, BSTNode *r = 0)
    {
        key = el;
        left = l;
        right = r;
    }
};

template <class T>
class BST
{
    BSTNode<T> *root;

    T *search(BSTNode<T> *p, const T &el) const
    {
        while (p != 0)
        {
            if (el == p->key)
                return &p->key;
            else if (el < p->key)
                p = p->left;
            else
                p = p->right;
        }
        return 0;
    }

    void preorder(BSTNode<T> *p)
    {
        if (p != 0)
        {
            visit(p);
            preorder(p->left);
            preorder(p->right);
        }
    }

    void inorder(BSTNode<T> *p)
    {
        if (p != 0)
        {
            inorder(p->left);
            visit(p);
            inorder(p->right);
        }
    }

    void postorder(BSTNode<T> *p)

    {
        if (p != 0)
        {
            postorder(p->left);
            postorder(p->right);
            visit(p);
        }
    }

    void visit(BSTNode<T> *p)
    {
        cout << p->key << " ";
    }

    int count_leaf(BSTNode<T> *p)
    {
        if (p == 0)
            return 0;
        else if (p->left == 0 && p->right == 0)
            return 1;
        return count_leaf(p->left) + count_leaf(p->right);
    }

    int count_nonleaf(BSTNode<T> *p)
    {
        if (p == 0)
            return 0;
        else if (p->left == 0 && p->right == 0)
            return 0;
        else
            return count_nonleaf(p->left) + count_nonleaf(p->right) + 1;
    }

    int Tree_height(BSTNode<T> *p)
    {
        if (p == 0)
            return 0;
        else
            return max(Tree_height(p->left), Tree_height(p->right)) + 1;
    }

    void mirror(BSTNode<T> *p)
    {
        if (p != 0)
        {
            BSTNode<T> *temp = p->left;
            p->left = p->right;
            p->right = temp;
            mirror(p->left);
            mirror(p->right);
        }
    }

    void clear(BSTNode<T> *p)
    {
        if (p != 0)
        {
            clear(p->left);
            clear(p->right);
            delete p;
        }
    }

public:
    BST()
    {
        root = 0;
    }

    ~BST()
    {
        clear();
    }

    void clear()
    {
        clear(root);
        root = 0;
    }

    void preorder()
    {
        preorder(root);
    }

    void inorder()
    {
        inorder(root);
    }

    void postorder()
    {
        postorder(root);
    }

    void insert(const T &el)
    {

        BSTNode<T> *p = root, *prev = 0;
        while (p != 0)
        {
            prev = p;
            if (p->key < el)
                p = p->right;
            else
                p = p->left;
        }
        if (root == 0)
            root = new BSTNode<T>(el);
        else if (prev->key < el)
            prev->right = new BSTNode<T>(el);
        else
            prev->left = new BSTNode<T>(el);
    }

    void del_copy(BSTNode<T> *&node)
    {
        BSTNode<T> *previous, *temp = node;

        if (node->right == 0)
            node = node->left;
        else if (node->left == 0)
            node = node->right;
        else
        {
            temp = node->left;
            previous = node;
            while (temp->right != 0)
            {
                previous = temp;
                temp = temp->right;
            }
            node->key = temp->key;
            if (previous == node)
                previous->left = temp->left;
            else
                previous->right = temp->left;
        }
        delete temp;
    }

    void del_merge(BSTNode<T> *&node)
    {
        BSTNode<T> *temp = node;
        if (node != 0)
        {
            if (!node->right)
                node = node->left;
            else if (node->left == 0)
                node = node->right;
            else
            {
                temp = node->left;
                while (temp->right != 0)
                    temp = temp->right;
                temp->right = node->right;
                temp = node;
                node = node->left;
            }
            delete temp;
        }
    }

    void breadthFirst()
    {
        queue<BSTNode<T> *> quel;
        BSTNode<T> *p = root;
        if (p != 0)
        {

            quel.push(p);
            while (!quel.empty())
            {

                p = quel.front();
                quel.pop();
                visit(p);
                if (p->left != 0)
                    quel.push(p->left);
                if (p->right != 0)
                    quel.push(p->right);
            }
        }
    }
    int count_leaves()
    {
        return count_leaf(root);
    }

    int count_nonleaves()
    {
        return count_nonleaf(root);
    }

    int tree_height()
    {
        return Tree_height(root);
    }

    void mirror_image()
    {
        mirror(root);
    }
};

int main()
{
    BST<int> t1;
    int ch;
    int el, el2, val;
    do
    {
        cout << "\n~~~~~~~~~~~MENU~~~~~~~~~~~";
        cout << "\n1.Insert an element";
        cout << "\n2.Count leaves";
        cout << "\n3.Count non-leaves";
        cout << "\n4.Compute Height";
        cout << "\n5.Mirror image";
        cout << "\n6.Display Level by level";
        cout << "\n7.Display Depth First";
        cout << "\n8.Exit";
        cout << "\nEnter Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the element to be inserted: ";
            cin >> el;
            t1.insert(el);
            break;
        case 2:
            cout << "\nNumber of leaves are: " << t1.count_leaves();
            break;
        case 3:
            cout << "\nNumber of non-leaves are: " << t1.count_nonleaves();
            break;
        case 4:
            cout << "\nHeight of tree is: " << t1.tree_height();
            break;
        case 5:
            t1.mirror_image();
            cout << "\nMirror image created !";
            break;
        case 6:
            t1.breadthFirst();
            break;
        case 7:
            system("CLS");
            cout << "\n1.Inorder";
            cout << "\n2.Preorder";
            cout << "\n3.Postorder";
            cout << "\nEnter choice: ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                t1.inorder();
                break;
            case 2:
                t1.preorder();
                break;
            case 3:
                t1.postorder();
                break;
            default:
                cout << "\nInvalid display option !";
            }
            break;
        case 8:
            cout << "\nExiting..";
            break;
        default:
            cout << "\nInvalid Choice !";
        }
    } while (ch != 8);

    return 0;
}