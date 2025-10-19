
#include "Sequence.h"
#include "string.h"


Sequence::Sequence()
{
    first = NULL;
    this->quantity = 0;
}

Sequence::~Sequence()
{
    Node<std::string>* curr = first;
    while(curr!=NULL)
    {
        Node<std::string>* aux = curr;
        curr = curr->getNext();
        delete aux;
    }
}

/**
 Returns the i-th element in this sequence.
 */
std::string Sequence::get(int i)
{
    Node<std::string>* curr = first;
    int counter = 1;
    
    while( curr!= NULL && counter < i )
    {
        curr = curr->getNext();
        counter++;
    }
    
    return curr->getValue();
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, std::string element)
{
    if (i <= 1) {
        insertBegin(element);
        return;
    }
    if (i > this->quantity) {
        insertEnd(element);
        return;
    }

    Node<std::string>* prev = this->first;
    int pos = 1;
    while (prev != NULL && pos < i - 1) {
        prev = prev->getNext();
        pos++;
    }

    Node<std::string>* node = new Node<std::string>(element);
    node->setNext(prev->getNext());
    prev->setNext(node);
    this->quantity++;
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(std::string element)
{
    Node<std::string>* node = new Node<std::string>(element);
    
    if( first != NULL )
    {
        node->setNext( first );
    }
    
    first = node;
    
    this->quantity++;
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(std::string element)
{
    Node<std::string>* node = new Node<std::string>(element);
    this->quantity++;
    
    if(first == NULL)
    {
        first = node;
        return;
    }
    
    Node<std::string>* curr = first;
    
    while( curr->getNext()!= NULL )
    {
        curr = curr->getNext();
    }
    
    curr->setNext(node);
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
std::string Sequence::remove(int i)
{
    if (this->first == NULL) {
        return "";
    }
    if (i <= 1) {
        return removeBegin();
    }

    Node<std::string>* prev = this->first;
    int pos = 1;
    while (prev != NULL && pos < i - 1) {
        prev = prev->getNext();
        pos++;
    }

    Node<std::string>* target = (prev ? prev->getNext() : NULL);
    if (target == NULL) {
        return removeEnd();
    }

    prev->setNext(target->getNext());
    std::string result = target->getValue();
    delete target;
    this->quantity--;
    return result;
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
std::string Sequence::removeBegin()
{
    Node<std::string>* toDelete = first;
    
    first = first->getNext();
    
    std::string result = toDelete->getValue();
    delete toDelete;
    this->quantity--;
    return result;
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
std::string Sequence::removeEnd()
{
    if(first == NULL)
    {
        return "";
    }
    
    Node<std::string>* curr = first;
    Node<std::string>* prev = NULL;
    
    while( curr->getNext()!= NULL )
    {
        prev = curr;
        curr = curr->getNext();
    }
    
    if(prev == NULL)
    {
        return removeBegin();
    }
    
    prev->setNext(NULL);
    
    std::string result = curr->getValue();
    delete curr;
    this->quantity--;
    return result;
}

Node<std::string>* Sequence::getFirst()
{
    return this->first;
}

void Sequence::print(void)
{
    Node<std::string> *n = this->first;
    while(n!=nullptr)
    {
        std::cout << n->getValue() << " ";
        n = n->getNext();
    }
    std::cout << std::endl;
}


bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
