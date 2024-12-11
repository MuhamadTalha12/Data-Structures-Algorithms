#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

template <typename T>
class DynamicArray {
public:
    T* data;
    int length;
    int capacity;

    DynamicArray() : length(0), capacity(2) {
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void pushBack(T value) {
        if (length >= capacity) {
            capacity = static_cast<int>(capacity * 1.5);
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

void createRandomFile(const string& filename, int size, int maxRandomNumber = 100) {
    srand(static_cast<unsigned>(time(0))); 
    ofstream writer(filename);
    for (int z = 0; z < size * 1024 * 1024; z++) {
        writer << rand() % maxRandomNumber << " "; 
    }
}

void loadDataIntoArray(const string& filename, DynamicArray<int>& array) {
    ifstream reader(filename);
    int value;
    while (reader >> value) {
        array.pushBack(value);
    }
}

// int main() {
//     string filename = "InputArraylist.txt";
//     createRandomFile(filename, 2); 

//     time_t start = time(0); 

//     DynamicArray<int> array;
//     loadDataIntoArray(filename, array);

//     time_t end = time(0); 

//     ofstream output("OutputArraylist.txt");
//     output << array; 

//     double elapsed = difftime(end, start);
//     cout << "Time taken to load data into DynamicArray: " << elapsed << " seconds" << endl;

//     return 0;
// }


template <typename T>
class AutoGrowingArray {
public:
    T* elements;
    int length;
    int capacity;

    AutoGrowingArray() : length(0), capacity(1) {
        elements = new T[capacity];
    }

    ~AutoGrowingArray() {
        delete[] elements;
    }

    T operator[](int index) const {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    T& operator[](int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    void pushBack(T value) {
        if (length >= capacity) {
            capacity *= 2;
            T* newElements = new T[capacity];
            for (int z = 0; z < length; z++) {
                newElements[z] = elements[z];
            }
            delete[] elements;
            elements = newElements;
        }
        elements[length++] = value;
    }

    friend ostream& operator<<(ostream& out, const AutoGrowingArray& array) {
        out << "[ ";
        for (int z = 0; z < array.length; ++z) {
            out << array.elements[z];
            if (z < array.length - 1) {
                out << ", ";
            }
        }
        out << " ]";
        return out;
    }
};

void createRandomFile(const string& filename, int size, int maxRandomNumber = 100) {
    srand(static_cast<unsigned>(time(0))); 
    ofstream writer(filename);
    for (int z = 0; z < size * 1024 * 1024; z++) {
        writer << rand() % maxRandomNumber << " "; 
    }
}

void loadDataIntoArray(const string& filename, AutoGrowingArray<int>& array) {
    ifstream reader(filename);
    int value;
    while (reader >> value) {
        array.pushBack(value);
    }
}

// int main() {
//     string filename = "InputGA.txt";
//     createRandomFile(filename, 2); 

//     time_t start = time(0); 

//     AutoGrowingArray<int> array;
//     loadDataIntoArray(filename, array);

//     time_t end = time(0); 

//     ofstream output("OutputGA.txt");
//     output << array; 

//     double elapsed = difftime(end, start);
//     cout << "Time taken to load data into AutoGrowingArray: " << elapsed << " seconds" << endl;

//     return 0;
// }

template <typename T>
class DynamicArray {
public:
    T* elements;           
    int length;         
    int capacity;     

    DynamicArray() : length(0), capacity(2) {
        elements = new T[capacity]; 
    }

    ~DynamicArray() {
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

    friend ostream& operator<<(ostream& out, const DynamicArray& arr) {
        for (int z = 0; z < arr.length; z++) {
            out << arr[z] << " ";
        }
        return out; 
    }
};

void createRandomFile(const string& filename, int size, int maxRandomNumber = 100) {
    srand(static_cast<unsigned>(time(0))); 
    ofstream writer(filename);
    for (int z = 0; z < size * 1024 * 1024; z++) {
        writer << rand() % maxRandomNumber << " "; 
    }
}

void loadDataIntoArray(const string& filename, DynamicArray<int>& arr) {
    ifstream reader(filename);
    int value;
    while (reader >> value) {
        arr.pushBack(value);
    }
}

// int main() {
//     string filename = "InputArray.txt";
//     createRandomFile(filename, 2); 

//     time_t start = time(0); 

//     DynamicArray<int> arr;
//     loadDataIntoArray(filename, arr);

//     time_t end = time(0); 

//     ofstream output("OutputArray.txt");
//     output << arr; 

//     double elapsed = difftime(end, start);
//     cout << "Time taken to load data into DynamicArray: " << elapsed << " seconds" << endl;

//     return 0;
// }