/* 
 * File:   RLUCache.h
 * Author: cpu10664-local
 *
 * Created on July 10, 2018, 5:59 PM
 */

#ifndef RLUCACHE_H
#define	RLUCACHE_H

#include <iostream>

#include "DoublyLinkedList.h"
#include "HashTable.h"


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

