/* 
 * File:   HashTable.h
 * Author: ducnt
 *
 * Created on July 13, 2018, 10:51 AM
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#define HashTableSize 1000000

template<class Tkey, class Tvalue>
class HashNode {
public:
    HashNode(const Tkey &key, const Tvalue &value) : _key(key), _value(value), _next(NULL) {
        
    }
    
    Tkey 
    getKey() {
        return this->_key;
    }
    
    Tvalue 
    getValue() {
        return this->_value;
    }
    
    void 
    setValue(Tvalue value) {
        this->_value = value;
    }
    
    HashNode* 
    getNext() {
        return this->_next;
    }
    
    void
    setNext(HashNode *next) {
        this->_next = next;
    }
    
private:
    Tkey _key;
    Tvalue _value;  
    HashNode<Tkey, Tvalue> *_next;
};

/*
 hash function 
 @return key 
 */
template <class Tkey>
struct KeyHash {
    unsigned int operator() (const Tkey& key) const {
        return reinterpret_cast<unsigned int>(key) % HashTableSize;
    }
};

template <class Tkey, class Tvalue, class HF = KeyHash<Tkey> >
class HashTable {
private:
    HashNode<Tkey, Tvalue>  **_hashTable;
    HF                      _hashFunction;
public:
    /*
     construct zero initialized hash table of size
     */
    HashTable() {
        this->_hashTable = new HashNode<Tkey, Tvalue> *[HashTableSize]();
    }
    
    /*
     release hashtable
     */
    ~HashTable() {
        for(int i = 0; i < HashTableSize; ++i) {
            HashNode<Tkey, Tvalue> *bucket = this->_hashTable[i];
            while (bucket != NULL){
                HashNode<Tkey, Tvalue> *node = bucket;
                bucket = bucket->getNext();
                delete node;
            }
            this->_hashTable[i] = NULL;
        }
        delete [] this->_hashTable;    
    }
    
    void 
    put(const Tkey &key, const Tvalue &value) {
        unsigned int hashValue = this->_hashFunction(key);
        HashNode<Tkey, Tvalue> *prevBucket = NULL;
        HashNode<Tkey, Tvalue> *bucket = this->_hashTable[hashValue];
        
        while (bucket != NULL && bucket->getKey() != key ){
            prevBucket = bucket;
            bucket = bucket->getNext();
        } 
        
        if (bucket == NULL) {
            bucket = new HashNode<Tkey, Tvalue>(key, value);
            if (prevBucket == NULL) {
                this->_hashTable[hashValue] = bucket;
            } else {
                prevBucket->setNext(bucket);
            }
        } else { // overide hash value
            bucket->setValue(value);
        }
    }
    
    void 
    remove(const Tkey &key) {
        unsigned int hashValue = this->_hashFunction(key);
        HashNode<Tkey, Tvalue> *prevBucket = NULL;
        HashNode<Tkey, Tvalue> *bucket = this->_hashTable[hashValue];
        
        while (bucket != NULL && bucket->getKey() != key) {
            prevBucket = bucket;
            bucket = bucket->getNext();
        }
        
        if (bucket == NULL) {
            // key no exist
            return;
        } else {
            if (prevBucket == NULL){
                this->_hashTable[hashValue] = bucket->getNext();
            } else {
                prevBucket->setNext(bucket->getNext()); 
            }
            delete bucket;
        } 
    }
    
    bool 
    get(const Tkey &key, Tvalue &value) {
        unsigned int hashValue = this->_hashFunction(key);
        HashNode<Tkey, Tvalue> *bucket = this->_hashTable[hashValue];   
        
        while (bucket != NULL) {
            if (bucket->getKey() == key) {
                value = bucket->getValue();
                return true;
            }
            bucket = bucket->getNext();
        }
        return false;
    }
     
};




#endif	/* HASHTABLE_H */

