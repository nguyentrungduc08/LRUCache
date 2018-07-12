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
    Node<Tkey, Tvalue> *_rear;
    
    bool isEmpty() {
        return this->_rear == NULL;  
    }
    
public:
    LinkedList() : _front(NULL), _rear(NULL) {};
    
    void        
    addFront(Tkey key, Tvalue value) {
        Node<Tkey, Tvalue> *node = new Node<Tkey, Tvalue>(key, value);
        if (this->_front == NULL && this->_rear == NULL){
            this->_front = this->_rear = NULL;
        } else {
            node->n
        }
        
    }
    void        addEear(Tkey key, Tvalue value);
    void        getNode(Node<Tkey, Tvalue>*);
    void        removeNode(Node<Tkey, Tvalue>*);
    
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

