#ifndef __HASHEDENTRY_CPP
#define __HASHEDENTRY_CPP
#include "HashedEntry.h"

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry() : nextPtr(nullptr) {}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType searchKey) :
        Entry<KeyType, ItemType>(newEntry, searchKey), nextPtr(nullptr) {}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType searchKey,
                                             HashedEntry<KeyType, ItemType> *nextEntryPtr) :
        Entry<KeyType, ItemType>(newEntry, searchKey), nextPtr(nextEntryPtr) {}

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType> *nextEntryPtr) {
    nextPtr = nextEntryPtr;
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType> *HashedEntry<KeyType, ItemType>::getNext() const {
    return nextPtr;
}
#endif
