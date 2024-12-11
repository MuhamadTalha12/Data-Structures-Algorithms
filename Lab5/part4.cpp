#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// Function prototypes
void displayVector(vector<int> numbers);
void reverseVector(vector<int>& numbers);
void ascendingSort(vector<int>& numbers);
void removeDuplicates(vector<int>& numbers);

int main()
{
    vector<int> numbers1 = {1, 3, 5, 7, 9, 11, 13, 15};
    reverseVector(numbers1);
    cout << "Reversed Vector: ";
    displayVector(numbers1);
    
    vector<int> numbers2 = {16,12,4,235,73,324,24};
    ascendingSort(numbers2);
    cout << "\nSorted Vector: ";
    displayVector(numbers2);
    
    vector<int> numbers3 = {3, 6, 9, 12, 3, 15, 9, 21};
    removeDuplicates(numbers3);
    cout << "\nAfter Removing Duplicates: ";
    displayVector(numbers3);
}

void displayVector(vector<int> numbers)
{
    for(int z = 0; z < numbers.size(); z++)
    {
        cout << numbers[z] << " ";
    }
}

void reverseVector(vector<int>& numbers)
{
    for(int z = numbers.size() - 1; z >= numbers.size() / 2; z--)
    {
        int j = numbers.size() - 1 - z;
        int temp = numbers[j];
        numbers[j] = numbers[z];
        numbers[z] = temp;
    }
}

void ascendingSort(vector<int>& numbers)
{
    for(int z = 0; z < numbers.size() - 1; z++)
    {
        int minIndex = z;
        for(int j = z + 1; j < numbers.size(); j++)
        {
            if(numbers[j] < numbers[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = numbers[z];
        numbers[z] = numbers[minIndex];
        numbers[minIndex] = temp;
    }
}

void removeDuplicates(vector<int>& numbers)
{
    for(int z = 0; z < numbers.size() - 1; z++)
    {
        for(int j = z + 1; j < numbers.size(); j++)
        {
            if(numbers[z] == numbers[j])
            {
                numbers.erase(numbers.begin() + j); 
                break;
            }
        }        
    }
}