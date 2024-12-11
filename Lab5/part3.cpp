#include<iostream>
#include<vector>
using namespace std;
void findValue(vector<int>vec,int value);

int main()
{
    vector<int> numbers = {100, 25, 43, 111, 133, 156, 79};
    int target = 156;
    findValue(numbers, target);
}

void findValue(vector<int> numbers, int target)
{
    bool flag = false;
    for(int z = 0; z < numbers.size(); z++)
    {
        if(numbers[z] == target)
        {
            cout << "Your number found at index: " << z << "\n";
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << "Number not found\n";
}