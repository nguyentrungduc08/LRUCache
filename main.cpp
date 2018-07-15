/* 
 * File:   main.cpp
 * Author: ducnt
 *
 * Created on July 10, 2018, 5:59 PM
 */

#include <cstdlib>
#include <string>

#include "LRUCache.h"

using namespace std;

class Person {
public:
    std::string name;
    int         age;
};

typedef Node<int, Person>* pNode;

bool testDoublyLinkedList();
bool testHashTable();

int main(int argc, char** argv) {
    
//    std::cout << testDoublyLinkedList() << std::endl; 
    std::cout << testHashTable() << std::endl;
    
    LRUCache<int, Person > cache; // add objects to cache
    
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



