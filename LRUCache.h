/* 
 * File:   RLUCache.h
 * Author: cpu10664-local
 *
 * Created on July 10, 2018, 5:59 PM
 */

#ifndef RLUCACHE_H
#define	RLUCACHE_H

#include <iostream>


template<class Tkey, class Tvalue>
class Node {
public :
    Tkey    _key;
    Tvalue  _value;
    Node    *_prev;
    Node    *_next;
    Node(Tkey k, Tvalue v): _key(k), _value(v), _prev(NULL), _next(NULL) {}
};  

template<class Tkey, class Tvalue>
class LinkedList {
private: 
    Node<Tkey, Tvalue> *_front;
    Node<Tkey, Tvalue> *_back;
    
    bool isEmpty() {
        return this->_back == NULL;  
    }
    
public:
    LinkedList() : _front(NULL), _back(NULL) {};
    
    /*
     Create new node with key and value
     @return address of node.
     */ 
    Node<Tkey, Tvalue>* 
    getNewNode(Tkey key, Tvalue value) {
        Node<Tkey, Tvalue> *newNode = new Node<Tkey, Tvalue>(key, value);
        return newNode;
    }
    
    /*
     Add new node to front of linked list. 
     @return address of new node.
     */
    Node<Tkey, Tvalue>*        
    pushFront(Tkey key, Tvalue value) {
        Node<Tkey, Tvalue> *node = this->getNewNode(key, value);
        if (this->_front == NULL && this->_back == NULL){
            this->_front = this->_back = node;
        } else {
            node->_next = this->_front;
            this->_front->_prev = node;
            this->_front = node;
        }
        return node;
    }
    
    /*
     Add new node to rear of linked list. 
     @return address of new node.
     */
    Node<Tkey, Tvalue>*
    pushBack(Tkey key, Tvalue value) {
        Node<Tkey, Tvalue> *node = this->getNewNode(key, value);
        if (this->_front == NULL && this->_back == NULL){
            this->_front = this->_back = node;
        } else {
            this->_back->_next = node;
            node->_prev = this->_back;
            this->_back = node;
        }
        return node;
    }
    
    void
    removeNode(Node<Tkey, Tvalue>* node) {
        if (node == NULL){
            return;
        }
        
        if (node == this->_front) {
            this->popFront();
            return;
        } 
        if (node == this->_back) {
            this->popBack();
            return;
        }
        
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;
        delete node;
    }
    
    /*
     remove first element in list
     @return None   
     */
    void 
    popFront() {
        if (this->isEmpty()) {
            return;
        }
        
        if (this->_front->_next != NULL) {
            Node<Tkey, Tvalue> *front = this->_front->_next;
            front->_prev = NULL;
            delete this->_front;
            this->_front = front;
        } else {
            delete this->_front;
            this->_front = this->_back = NULL;
        }
    }
    
    /*
     remove last element in list
     @return None   
     */
    void
    popBack() {
        if (this->isEmpty()) {
            return;
        }
        
        if (this->_back->_prev != NULL) {
            Node<Tkey, Tvalue> *back = this->_back->_prev;
            back->_next = NULL;
            delete this->_back;
            this->_back = back;
        } else {
            delete this->_back;
            this->_front = this->_back = NULL;
        }
    }
    
    Node<Tkey, Tvalue>* 
    find(Tkey key){
        Node<Tkey, Tvalue> *temp = this->_front;
        while (temp != NULL){
            if (temp->_key == key){
                return temp;
            } 
            temp = temp->_next;
        }
        return NULL;
    }
    
    void        
    displayList(){
        Node<Tkey, Tvalue>* temp = this->_front;
        std::cout << "Doubly Linked List\n";
        while (temp != NULL){
            std::cout << "Node: " << temp->_key << " - " << temp->_value << std::endl;
            temp = temp->_next;
        } 
        std::cout << std::endl;
    }
};

class LRUCache {
public:
    LRUCache();
    LRUCache(const LRUCache& orig);
    virtual ~LRUCache();
    

    
private:
    int     _capacity;
    
    void            refer(const int& key);

};

#endif	/* RLUCACHE_H */

