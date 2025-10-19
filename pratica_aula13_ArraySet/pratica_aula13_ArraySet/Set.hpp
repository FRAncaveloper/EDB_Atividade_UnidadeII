//
//  Set.hpp
//  Set
//
//

#ifndef Set_hpp
#define Set_hpp

#include <string>

class Set {
private:
    int quantity;
    
    int capacity;
    
    unsigned int insertPosition;
    
    std::string *array;
    
    const int CAPACITY_DEFAULT = 17;
    
public:
    Set();
    Set(int);
    ~Set();
    bool add(std::string s);
    void clear();
    bool contains(std::string s);
    bool isEmpty();
    bool remove(std::string s);
    int size();
};

#endif /* Set_hpp */
