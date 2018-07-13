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

/*
 * 
 */

bool testDoublyLinkedList();

int main(int argc, char** argv) {
    
    std::cout << testDoublyLinkedList() << std::endl; 
    
    return 0;
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

