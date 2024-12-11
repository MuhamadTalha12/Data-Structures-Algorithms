#include<iostream>
using namespace std;

class hashingTable{
    int size;
    string* table;

    int hash(string s){
        int sum=0;
        for(char c:s){
            sum += c;
        }
        return sum % 21;
    }
    public:
        hashingTable(int size){
            this->size = size;
            table = string[size];
            for(int i=0;i<size;i++){
                table[i] = "";
            }
        }


        void insert(string s){
            int index = hash(s);
            int i =0;
            while(table[index] !=""){
                i++;
                if(i==size){
                    cout << "Hash Table is full";
                    return;
                }
                index = (index+i*i)%21
            }
            table[index] = s;
            print_table();
            
        }

        void print_table() {
        cout << "\nCurrent state of the hash table:\n";
            for (int i = 0; i < size; i++) {
                if (table[i] == "") {
                    cout << " "  << endl;
                } 
                } else {
                    cout << i  << " " << table[i] << endl;
                }
            cout << endl;
            }
        }

        int main() {
    hashingTable qpht(21);  // Size of 21 for hashing mod 21

    // Insert some elements
    qpht.insert("apple");
    qpht.insert("banana");
    qpht.insert("cherry");
    return 0;
}