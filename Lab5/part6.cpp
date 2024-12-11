#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class AutoGrowingArray {
public:
    T* data;
    int size;
    int capacity;

    AutoGrowingArray() : size(0), capacity(1) {
        data = new T[capacity];
    }

    ~AutoGrowingArray() {
        delete[] data;
    }

    T operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void pushBack(T value) {
        if (size >= capacity) {
            capacity *= 2;
            T* newData = new T[capacity];
            for (int z = 0; z < size; z++) {
                newData[z] = data[z];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    friend ostream& operator<<(ostream& out, const AutoGrowingArray& array) {
        out << "[ ";
        for (int z = 0; z < array.size; ++z) {
            out << array.data[z];
            if (z < array.size - 1) {
                out << ", ";
            }
        }
        out << " ]";
        return out;
    }
};

int main() {
    AutoGrowingArray<int> array;

    array.pushBack(10);
    array.pushBack(20);
    array.pushBack(30);
    array.pushBack(40);
    array.pushBack(50);

    cout << "Array contents: " << array << endl;

    cout << "Element at index 2: " << array[2] << endl;

    array[2] = 100;
    cout << "Array contents after modification: " << array << endl;

    return 0;
}