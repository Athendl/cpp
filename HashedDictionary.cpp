#include "HashedDictionary.h"
#include <stdexcept>
#include <iostream>

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType &searchKey) const {
    int sum = 0;
    for (int i = 0; i < searchKey.length(); ++i) {
        sum += static_cast<int>(searchKey[i]);
    }
    return sum % hashTableSize;
}
template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary() : itemCount(0), hashTableSize(DEFAULT_SIZE) {
    hashTable = new HashedEntry<KeyType, ItemType> *[hashTableSize]();
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary() {
    clear();
    delete[] hashTable;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {
    return itemCount;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType &searchKey, const ItemType &newItem) {
    // Create entry to add to dictionary
    HashedEntry<KeyType, ItemType> *entryToAddPtr =
            new HashedEntry<KeyType, ItemType>(newItem, searchKey);

    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);

    // Add the entry to the chain at itemHashIndex
    if (hashTable[itemHashIndex] == nullptr) {
        hashTable[itemHashIndex] = entryToAddPtr;
    } else {
        entryToAddPtr->setNext(hashTable[itemHashIndex]);
        hashTable[itemHashIndex] = entryToAddPtr;
    }

    itemCount++;
    return true;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType &searchKey) {
    bool itemFound = false;

    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);
    if (hashTable[itemHashIndex] != nullptr) {
        // Special case - first node has target
        if (searchKey == hashTable[itemHashIndex]->getKey()) {
            HashedEntry<KeyType, ItemType> *entryToRemovePtr =
                    hashTable[itemHashIndex];
            hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
            delete entryToRemovePtr;

            itemCount--;
            itemFound = true;
        } else // Search the rest of the chain
        {
            HashedEntry<KeyType, ItemType> *prevPtr = hashTable[itemHashIndex];
            HashedEntry<KeyType, ItemType> *curPtr = prevPtr->getNext();
            while ((curPtr != nullptr) && !itemFound) {
                // Found item in chain so remove that node
                if (searchKey == curPtr->getKey()) {
                    prevPtr->setNext(curPtr->getNext());
                    delete curPtr;

                    itemCount--;
                    itemFound = true;
                } else // Look at next entry in chain
                {
                    prevPtr = curPtr;
                    curPtr = curPtr->getNext();
                }
            }
        }
    }

    return itemFound;
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    for (int i = 0; i < hashTableSize; ++i) {
        while (hashTable[i] != nullptr) {
            HashedEntry<KeyType, ItemType> *entryToRemovePtr = hashTable[i];
            hashTable[i] = hashTable[i]->getNext();
            delete entryToRemovePtr;
        }
    }
    itemCount = 0;
}

template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType &searchKey) const {
    int itemHashIndex = getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType> *curPtr = hashTable[itemHashIndex];
    while (curPtr != nullptr) {
        if (curPtr->getKey() == searchKey) {
            return curPtr->getItem();
        }
        curPtr = curPtr->getNext();
    }
    throw std::runtime_error("Item not found in dictionary.");
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType &searchKey) const {
    int itemHashIndex = getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType> *curPtr = hashTable[itemHashIndex];
    while (curPtr != nullptr) {
        if (curPtr->getKey() == searchKey) {
            return true;
        }
        curPtr = curPtr->getNext();
    }
    return false;
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::display() const {
    for (int i = 0; i < hashTableSize; ++i) {
        HashedEntry<KeyType, ItemType> *p = hashTable[i];
        std::cout << "\nH[" << i << "]:" << std::endl;
        while (p != nullptr) {
            std::cout << "key[" << p->getKey() << "]=" << p->getItem() << std::endl;
            p = p->getNext();
        }
        std::cout << std::endl;
    }
}
