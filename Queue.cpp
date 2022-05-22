#include "Queue.h"



template<typename T>
Queue<T>::Node::Node(T value){
    m_value = new T(value);
    m_next = NULL;
}

template<typename T>
Queue<T>::Node::~Node(){
    delete m_value;
    if(this->m_next != NULL){
        delete this->m_next;
    }
}

template<typename T>
Queue<T>::Node::Node(const Queue::Node &other) {
    this->m_value = new T(other.m_value);
    this->m_next = new Queue<T>::Node(other.m_next);
}

template<typename T>
int Queue<T>::size() const {
    return m_Length;
}
