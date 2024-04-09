#include "Entry.h"

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry() {}

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(ItemType newEntry, KeyType searchKey) : item(newEntry), searchKey(searchKey) {}

template<class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const {
    return item;
}

template<class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const {
    return searchKey;
}

template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType &newEntry) {
    item = newEntry;
}

template<class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setKey(const KeyType &searchKey) {
    this->searchKey = searchKey;
}
