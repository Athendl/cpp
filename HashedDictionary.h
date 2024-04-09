#ifndef _HASHED_DICTIONARY
#define _HASHED_DICTIONARY

#include "DictionaryInterface.h"
#include "HashedEntry.h"

template<class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType> **hashTable; // Array of pointers to entries
    int itemCount; // Count of dictionary entries
    int hashTableSize; // Table size must be prime
    static const int DEFAULT_SIZE = 101;

    int getHashIndex(const KeyType &searchKey) const;

public:
    HashedDictionary();

    virtual ~HashedDictionary();

    bool isEmpty() const override;

    int getNumberOfItems() const override;

    bool add(const KeyType &searchKey, const ItemType &newItem) override;

    bool remove(const KeyType &searchKey) override;

    void clear() override;

    ItemType getItem(const KeyType &searchKey) const override;

    bool contains(const KeyType &searchKey) const override;

    // Add any additional member functions as necessary
    void display() const;
};

#endif
