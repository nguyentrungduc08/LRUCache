/* 
 * File:   main.cpp
 * Author: ducnt
 *
 * Created on July 10, 2018, 5:59 PM
 */

#include <cstdlib>
#include <string>

#include "LRUCache.h"
#include "LRUCache.cpp"

using namespace std;

class Person {
public:
    std::string name;
    int         age;
    friend ostream& operator<<(ostream& os, const Person& dt);  
};

ostream& operator<<(ostream& os, const Person& dt)  
{  
    os << dt.name << " - " << dt.age;  
    return os;  
}  

typedef Node<int, Person>* pNode;

bool testDoublyLinkedList();
bool testHashTable();

int main(int argc, char** argv) {
    
//    std::cout << testDoublyLinkedList() << std::endl; 
//    std::cout << testHashTable() << std::endl;
    
    LRUCache<int, Person > cache; // add objects to cache
    cache.setCacheSize(4);
    
    Person a,b,c,d,e,f;
    a.name = "aaa";
    a.age = 1;
    b.name = "bbb";
    b.age = 2;
    c.name = "ccc";
    c.age = 3;
    d.name = "ddd";
    d.age = 4;
    e.name = "eee";
    e.age = 5;
    f.name = "fff";
    f.age = 6;
    
    cache.add(1,a);
    cache.add(2,b);
    cache.add(3,c);
    cache.add(4,c);
    cache.add(5,c);
    cache.add(6,c);
    cache.add(1,a);
    cache.display();
    return 0;
}



bool testHashTable() {
    HashTable<unsigned int, std::string> hashTable;
    
    hashTable.put(1,"asdf");
    hashTable.put(2,"asdasdf");
    hashTable.put(3,"asdffffff");
    
    std::string result;
    
    std::cout << hashTable.get(1,result) << " - " << result << std::endl;
    std::cout << hashTable.get(9,result) << " - " << result << std::endl;
    std::cout << hashTable.get(3,result) << " - " << result << std::endl;
    
    hashTable.remove(2);
    std::cout << hashTable.get(2,result) << " - " << result << std::endl;
    
    std::cout << "hash size: " << hashTable.size() << std::endl;
} 

bool testDoublyLinkedList() {
    LinkedList<int, std::string> list;
    list.pushFront(1,"asdfad");
    list.pushFront(2,"asdfad");   
    list.pushBack(4,"adfasdf");
    list.pushFront(3,"asdfad");
    list.pushBack(5,"azzzzdfasdf");
    
    list.displayList();
    
    list.popFront();
    list.displayList();
    list.popBack();
    list.displayList();
    
    list.pushFront(0,"azzzzdfasdf");
    list.pushBack(6,"azzzzdfasdf");
    Node<int, std::string> *node = list.find(1);
    list.removeNode(node);
    list.displayList(); 
    return true;
}



