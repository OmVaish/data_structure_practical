#include<iostream>
using namespace std;

class ExtendableArrayVector {
private:
    int *arr;
    int capacity;
    int size;
public: 
    ExtendableArrayVector() {
        arr = new int[1];
        capacity = 1;
        size = 0;
    }

    void push_back(int data) {
        if (size == capacity) {
            int *temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size] = data;
        size++;
    }

    int get(int index) {
        if (index < size) {
            return arr[index];
        }
        return -1;
    }

    void set(int index, int data) {
        if (index < size) {
            arr[index] = data;
        }
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    ExtendableArrayVector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.print();

    v.set(1, 100);

    v.print();

    cout << v.get(1) << endl;
    cout << v.getSize() << endl;

    return 0;
}