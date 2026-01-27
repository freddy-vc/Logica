#include "list.cpp" 

using namespace std; 

int main() { 
    List<string> list; 

    list.insert(0, "nestor"); 
    list.insert(1, "victor"); 
    list.insert(2, "Maria"); 
    list.insert(3, "juan");
    list.insert(4, "pedro"); 
    
    cout << "\nSize: " << list.size() << endl; 
    list.print();

    list.reverse();
    list.print();

    return 0; 
}