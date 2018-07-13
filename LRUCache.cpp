/* 
 * File:   RLUCache.cpp
 * Author: ducnt
 * 
 * Created on July 10, 2018, 5:59 PM
 */

#include "LRUCache.h"

template<class Tkey, class Tvalue>
void 
LRUCache<Tkey, Tvalue>::add(const Tkey& key, const Tvalue& value){
    if (this->_hashTable.find(key)){
        if (this->_list.size() == this->_cacheSize ) {// cache full
            Node<Tkey, Tvalue>* last = this->_list.getBack();
            this->_hashTable.remove(key);
            this->_list.popBack();
        }    
    } else {
        this->_hashTable.remove(key);
    }

    this->_list.pushFront(key, value);
    this->_hashTable.put(key,this->_list->getFront());
}


template <class Tkey, class Tvalue> 
bool 
LRUCache<Tkey, Tvalue>::find(const Tkey& key) {
    if (this->_hashTable.find(key) ) {
        return true;
    } else {
        return false;
    }
}

template<class Tkey, class Tvalue>
void 
LRUCache<Tkey, Tvalue>::get(const Tkey& key, Tvalue &value) {
    if (this->find(key)){
        Tvalue* addressData = NULL;
        this->_hashTable.get(key, addressData);
        if (addressData != NULL){
            value = addressData->value;
        }
    } else {
        value = NULL;
    }

}