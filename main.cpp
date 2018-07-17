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
#include "ArrayList.h"

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
bool testLRUCache();
bool testArrayList();

int main(int argc, char** argv) {
    
//    std::cout << testDoublyLinkedList() << std::endl; 
//    std::cout << testHashTable() << std::endl;
    // std::cout << testLRUCache() << std::endl;
    std::cout << testArrayList() << std::endl;

    return 0;
}

bool testArrayList() {
    ArrayList<int> arr(18);
    std::cout << ceil(123.2) << std::endl;
    std::cout << arr.Log() << " - " << arr.capacity() << std::endl;
    arr[1] = 1;
    arr[2] = 2;
    arr[6] = 9;
    for(int i = 0 ;i < 1; ++i)
        std::cout << arr[i] << std::endl;
}

bool testLRUCache() {
    LRUCache<int, Person > cache; // add objects to cache
    cache.setCacheSize(5);
    
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
    cache.display();

    cache.add(2,b);
    cache.display();

    cache.add(3,c);
    cache.display();

    cache.add(4,d);
    cache.display();

    cache.add(5,e);
    cache.display();

    cache.add(6,f);
    cache.display();

    cache.add(1,a);
    cache.display();
    
    cache.add(5,e);
    cache.display();

    Person tmp;
    cache.get(6, tmp);
    cache.display();
    std::cout << "info: " << tmp.age << " - " << tmp.name << std::endl;
    
    return true;
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



