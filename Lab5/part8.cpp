#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DynamicList {
public:
    T* elements;
    int length;
    int capacity;

    DynamicList() : length(0), capacity(2) {
        elements = new T[capacity];
    }

    ~DynamicList() {
        delete[] elements;
    }

    void pushBack(T value) {
        if (length >= capacity) {
            capacity = static_cast<int>(capacity * 1.5);
            T* temp = new T[capacity];
            for (int z = 0; z < length; z++) {
                temp[z] = elements[z];
            }
            delete[] elements;
            elements = temp;
        }
        elements[length] = value;
        length++;
    }

    T& operator[](int index) {
        if (index >= length || index < 0) {
            throw out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    T operator[](int index) const {
        if (index >= length || index < 0) {
            throw out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    friend ostream& operator<<(ostream& out, const DynamicList& list) {
        for (int z = 0; z < list.length; z++) {
            out << list[z] << " ";
        }
        return out;
    }
};

int main() {
    DynamicList<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    cout << "DynamicList: " << list << endl;

    cout << "Element at index 1: " << list[1] << endl;

    list.pushBack(4);
    list.pushBack(5);
    cout << "DynamicList after adding more elements: " << list << endl;

    return 0;
}