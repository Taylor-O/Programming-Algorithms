/***************************************
Make A Hash Table
Author: Taylor Reeves-Chavez
Date Completed: 4/14/2025
Description: A program that makes a hash table
***************************************/

#include <iostream>
#include <sstream>
#include <array>
#include "LinkedList.hpp"
using std::array;
using std::string;
using std::pair;
using std::size_t;
using std::cout;

// Templated hash table data type definition
// Uses separate chaining for collision resolution
template <typename T, size_t TABLE_SIZE=11>
class HashTable
{
    // Note: Do not modify any code in the private section!
    private:

    // Array of linked lists to hold all data
    array<LinkedList<pair<string, T>>, TABLE_SIZE> table_;

    // Hashing function
    size_t hash(string const &key) const
    {
        size_t sum(0);
        for (char c : key)
        {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

    // Create alias for linked list iterator to make life easier ;)
    using listIter = typename LinkedList<pair<string, T>>::Iterator;

    public:

    // Retrieve pointer to value associated with key.
    // Will return null pointer if no matching key is found.  
    T* get(string const &key) {

        size_t index = hash(key);

        for (listIter iter = table_.at(index).generateIterator(); iter.hasNext(); iter.next()) {

            if (key == iter.current()->first) {

                return &iter.current()->second;

            }

        }

        return nullptr;

    }

    // Add new key/value entry in hash table.
    // Will return true if successfully added, will return
    // false if key value already exists.
    bool add(string const &key, T const &value) {

        size_t index = hash(key);

        if (get(key) != nullptr) {

            return false;

        } else {

            table_.at(index).pushFront(pair<string, T>(key, value));

            return true;

        }

    }

    // Remove entry with matching key from hash table.
    // Do nothing if no entry has matching key.
    void remove(string const &key) {

        size_t arrayIndex = hash(key);
        size_t index = 0;
        bool matchKey = false;

        for (listIter iter = table_.at(arrayIndex).generateIterator(); iter.hasNext(); iter.next()) {

            if (key == iter.current()->first) {

                matchKey = true;
                break;

            }

            index++;

        }

        if (matchKey = true) {

        table_.at(arrayIndex).removeAt(index);

        }
    }

    // Return the number of entries in hash table
    size_t size() {

        size_t htSize = 0;
        for (int i = 0; i < table_.size(); i++) {

            htSize = htSize + table_.at(i).size();

        }

        return htSize;

    }

    // Remove all entries from the hash table
    void clear() {

        for (int i = 0; i < table_.size(); i++) {

            table_.at(i).clear();

        }

    }
};


// Helper function for driver code in main
template <typename T>
string getHashTableValueHelper(HashTable<T> &ht, string const &key)
{
    T* retrievedValue = ht.get(key);
    if (retrievedValue != nullptr)
    {
        std::ostringstream oss;
        oss<<*retrievedValue;
        return oss.str();
    }
    
    return "null";
}

int main()
{
    HashTable<int> intHt;
    HashTable<string> stringHt;

    cout<<"Testing HashTable<int>:\n\nThe int hash table contains "<<intHt.size()<<" entries\n\n";

    cout<<"Adding key/value entries to the int hash table...\n\n";
    intHt.add("The Answer", 42);
    intHt.add("Negative", -123);
    intHt.add("Positive", 321);
    intHt.add("Prime Integer", 11);
    intHt.add("Kaprekar's Constant", 6174);

    cout<<"The int hash table contains "<<intHt.size()<<" entries\n\n";

    cout<<"The value at key \"Negative\" is "<<getHashTableValueHelper(intHt, "Negative")<<"\n";
    cout<<"The value at key \"Prime Integer\" is "<<getHashTableValueHelper(intHt, "Prime Integer")<<"\n";
    cout<<"The value at key \"Kaprekar's Constant\" is "<<getHashTableValueHelper(intHt, "Kaprekar's Constant")<<"\n";
    cout<<"The value at key \"Imaginary Number\" is "<<getHashTableValueHelper(intHt, "Imaginary Number")<<"\n\n";

    cout<<"Removing entry with key \"Negative\" from int hash table\n";
    intHt.remove("Negative");
    cout<<"Removing entry with key \"Kaprekar's Constant\" from int hash table\n\n";
    intHt.remove("Kaprekar's Constant");

    cout<<"The value at key \"Kaprekar's Constant\" is "<<getHashTableValueHelper(intHt, "Kaprekar's Constant")<<"\n\n";

    cout<<"The int hash table contains "<<intHt.size()<<" entries\n\n";

    cout<<"Clearing the int hash table...\n\n";
    intHt.clear();

    cout<<"The int hash table contains "<<intHt.size()<<" entries\n\n\n";


    cout<<"Testing HashTable<string>:\n\nAdding key/value entries to the string hash table...\n\n";
    stringHt.add("aspired", "A peaceful existence");
    stringHt.add("despair", "Losing the big game");
    stringHt.add("praised", "Obedient pets");
    stringHt.add("diapers", "Stinky");

    cout<<"The string hash table contains "<<stringHt.size()<<" entries\n\n";

    cout<<"The value at key \"praised\" is \""<<getHashTableValueHelper(stringHt, "praised")<<"\"\n";
    cout<<"The value at key \"aspired\" is \""<<getHashTableValueHelper(stringHt, "aspired")<<"\"\n\n";
    
    cout<<"Clearing the string hash table...\n\n";
    stringHt.clear();

    cout<<"The string hash table contains "<<stringHt.size()<<" entries\n";

    return 0;
}