#include <iostream>
#include <iterator>
#include <string>
#include <vector>

struct HashKey {
  int hash, key;
  HashKey(int hash, int key) {
    this->key = key;
    this->hash = hash;
  }
};

class HashTable {
private:
  std::vector<std::string> array[27];

  int preHash(std::string str) {
    char ch = str[0];
    int key = int(ch) % 26;
    if (key >= 13) {
      key -= 13;
    } 
    else {
      key += 14;
    }
    return abs(key);
  }

public:

  void insert(std::string str) {
    int key = preHash(str);
    array[key].push_back(str);
  }  

  bool contains(std::string str) {
    int key = preHash(str);
    for (std::string str2 : array[key]) {
      if (str2 == str) return true; 
    } 
    return false;
  }

  HashKey look(std::string str) {
    int hash = preHash(str), key = 0;
    for (std::string str2 : array[hash]) {
      if (str2 == str) return HashKey(hash, key);
      key++;
    }
    return HashKey(-1, -1);
  } 

  void remove(std::string str) {
    HashKey hashkey = look(str);
    int hash = hashkey.key, key = hashkey.hash;
    std::cout << hash << "\n" << key << std::endl;
    if (key >= 0 && hash >= 0) {
      array[hash].erase(array[hash].begin() + key);
    }
  }

  void print() {
    for (std::vector<std::string> element : array) {
      for (std::string str : element ) {
        std::cout << str << std::endl; 
      }
    } 
  }

};

int main() {

  HashTable hashTable;
   
  std::string names[26] = {
    "Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace",
    "Henry", "Ivy", "Jack", "Kelly", "Liam", "Mia", "Noah", "Olivia",
    "Peter", "Quinn", "Rachel", "Sam", "Tyler", "Uma", "Victor",
    "Wendy", "Xavier", "Yvonne", "Zach"
  }; 

  for (std::string name : names) {
    hashTable.insert(name);
  }

  HashKey hashkey = hashTable.look("liam");
  std::cout << hashkey.key << "\n" << hashkey.hash;

}
