#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector<int> numbers;
    for (int z = 0; z < 100; z++)
    {
        numbers.push_back(z);
        cout << "After Adding element " << z << "\n";
        cout << "Vector Size: " << numbers.size() << "\n";
        cout << "Vector Capacity: " << numbers.capacity() << "\n";
    }
}