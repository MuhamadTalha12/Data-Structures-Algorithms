#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
public:
    T* data;           
    int length;         
    int capacity;     

    DynamicArray() : length(0), capacity(1) {
        data = new T[capacity]; 
    }

    ~DynamicArray() {
        delete[] data;
    }

    void pushBack(T value) {
        if (length >= capacity) {
            capacity *= 2; 
            T* temp = new T[capacity]; 
            for (int z = 0; z < length; z++) {
                temp[z] = data[z];
            }
            delete[] data;   
            data = temp; 
        }
        data[length] = value;
        length++;
    }

    T& operator[](int index) {
        if (index >= length || index < 0) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    T operator[](int index) const {
        if (index >= length || index < 0) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    friend ostream& operator<<(ostream& out, const DynamicArray& arr) {
        for (int z = 0; z < arr.length; z++) {
            out << arr[z] << " ";
        }
        return out;
    }
};

int main() {
    DynamicArray<int> arr;
    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);
    cout << "Array: " << arr << endl;
    cout << "Element at index 1: " << arr[1] << endl;
    arr.pushBack(40);
    arr.pushBack(50);
    cout << "Array after adding more elements: " << arr << endl;

    return 0;
}