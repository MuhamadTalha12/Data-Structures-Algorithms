#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> elements;
    int choice;
    string item;
    
    while(true)
    {
        cout << " 1. Add Element\n";
        cout << " 2. Remove Element\n";
        cout << " 3. Exit\n";
        cout << " Enter Option Number: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter Element you want to Add: ";
                cin.ignore();
                getline(cin, item);
                elements.push_back(item);
                cout << "Vector Size is: " << elements.size();
                cout << "\n Vector Capacity is: " << elements.capacity() << "\n";
                break;
                
            case 2:
                cout << "Enter Element you want to remove: ";
                cin.ignore();
                getline(cin, item);
                {
                    auto it = remove(elements.begin(), elements.end(), item);
                    if (it == elements.end()) {
                        cout << "Element not found!\n";
                        break;
                    }
                    elements.erase(it, elements.end());
                }
                cout << "Vector Size is: " << elements.size();
                cout << "\n Vector Capacity is: " << elements.capacity() << "\n";
                break;
            case 3:
                return 0;
                
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
    
    return 0;
}