//
//  ArraySet.cpp
//  ArraySet
//
//

#include "Set.hpp"

Set::Set(){
    this->capacity = CAPACITY_DEFAULT;
    
    array = new std::string[this->capacity];
    
    this->quantity = 0;
    this->insertPosition = 0;
}

Set::Set(int initialCapacity){
    this->capacity = initialCapacity;
    
    array = new std::string[this->capacity];
    
    this->quantity = 0;
    this->insertPosition = 0;
}

Set::~Set(){
    delete [] array;
}

bool Set::add(std::string s){
    // Não permite duplicatas
    if (this->contains(s)) {
        return false;
    }

    // Aumenta capacidade se necessário
    if (this->quantity >= this->capacity) {
        int newCapacity = this->capacity * 2;
        std::string* newArray = new std::string[newCapacity];
        for (int i = 0; i < this->quantity; ++i) {
            newArray[i] = this->array[i];
        }
        delete [] this->array;
        this->array = newArray;
        this->capacity = newCapacity;
    }

    // Insere no final da região ocupada
    this->array[this->quantity] = s;
    this->quantity++;
    this->insertPosition = this->quantity; // mantém consistente

    return true;
}

bool Set::contains(std::string s){
    for( int i = 0; i < this->quantity; ++i ){
        if( array[i] == s ){
            return true;
        }
    }
    return false;
}

bool Set::remove(std::string s){
    for (int i = 0; i < this->quantity; ++i) {
        if (this->array[i] == s) {
            // Remove em O(1) substituindo pelo último
            this->array[i] = this->array[this->quantity - 1];
            this->quantity--;
            this->insertPosition = this->quantity;
            return true;
        }
    }
    return false;
}

int Set::size(){
    return this->quantity;
}

bool Set::isEmpty(){
    return this->quantity == 0;
}

void Set::clear(){
    this->quantity = 0;
    this->insertPosition = 0;
}
