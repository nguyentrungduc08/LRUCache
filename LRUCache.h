/* 
 * File:   RLUCache.h
 * Author: ducnt
 *
 * Created on July 10, 2018, 5:59 PM
 */

#ifndef RLUCACHE_H
#define	RLUCACHE_H

#include <iostream>

#include "DoublyLinkedList.h"
#include "HashTable.h"


template<class Tkey, class Tvalue>
class LRUCache {
public:
    LRUCache() {
        this->_cacheSize = HashTableSize;
    }
    
    virtual ~LRUCache(){
        
    }
    
    void add(const Tkey&, const Tvalue&);
    void get(const Tkey&, Tvalue&);
    bool find(const Tkey &key);
    
private:
    LinkedList<Tkey, Tvalue>    _list;
    HashTable<Tkey, Tvalue*>    _hashTable;
    unsigned int                _cacheSize;
};

#endif	/* RLUCACHE_H */

