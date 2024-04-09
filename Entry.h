#ifndef _ENTRY
#define _ENTRY

template <class KeyType, class ItemType>
class Entry {
    private:
       ItemType item;
       KeyType searchKey;
   
    protected:
       void setKey(const KeyType& searchKey);
   
    public:
       Entry();
       Entry(ItemType newEntry, KeyType searchKey);
       ItemType getItem() const;
       KeyType getKey() const;
       void setItem(const ItemType& newEntry);
};

#include "Entry.cpp"
#endif
