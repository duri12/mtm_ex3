#include "Queue.h"



template<typename T>
Queue<T>::Node::Node(T value) : m_value(value)
{
    m_next = NULL;
}

template<typename T>
Queue<T>::Node::~Node(){
    delete m_value;
    if(this->m_next != NULL)
    {
        delete this->m_next;
    }
}

template<typename T>
Queue<T>::Node::Node(const Queue<T>::Node &other) : m_value(other.m_value){
    this->m_next = new Queue<T>::Node(other.m_next);
}

template<typename T>
int Queue<T>::size() const {
    return m_Length;
}

template<typename T>
void Queue<T>::pushBack(T value) {
    Node *newNode = new Queue<T>::Node(value);
    if(this->m_Length == 0 )
    {
        this->m_First = newNode;
        this->m_Last = newNode;
    }
    else
    {
        m_Last->m_next = newNode;
        m_Last = newNode;
    }
    m_Length ++ ;
}

template<typename T>
T& Queue<T>::front() {
    return  *this->m_First->m_value;
}

template<typename T>
void Queue<T>::popFirst() {
    if(this->m_Length == 0)
    {
        throw(EmptyQueue());
    }
    if(this->m_Length == 1)
    {
        this->m_Last = NULL;
        this->m_First = NULL;
        this->m_Length = 0;
        return;
    }
    Node* temp = this->m_First->m_next;
    Node toDelete = this->m_First;
    toDelete->m_next = NULL;
    this->m_First = temp;
    delete toDelete;
    this->m_Length -- ;
}

template<typename T>
Queue<T>::Queue(const Queue<T> &) {

}

template<typename T>
Queue<T>::Queue() {

}

