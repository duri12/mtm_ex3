#include "Queue.h"

template<typename T>
Queue<T>::Iterator::Iterator(const Queue* q, Node* currNode) {
    m_q = q;
    assert(currNode!=NULL);
    m_currNode = currNode;
}

template<typename T>
const T& Queue<T>::Iterator::operator*() {
    assert(currNode!=NULL);
    return currNode->m_value;
}

template<typename T>
Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    m_currNode = m_currNode->m_next;
    return this;
}
template<typename T>
Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {
    Iterator result = *this;
    ++*this;
    return result;
}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator it) {
    assert(it.m_q == m_q);
    if(it.m_currNode == this->m_currNode) {
        return false;
    }
    return true;
}

template<typename T>
Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(this, m_First);
}

template<typename T>
Queue<T>::Iterator Queue<T>:end() const {
    return Iterator(this, m_Last);
}

template<typename T>
Queue<T>::Queue() {
    m_First = NULL;
    m_Length = 0;
    m_Last = NULL;

}
template<typename T>
Queue<T>::getFirst() {
    return this->m_First;
}
template<typename T>
Queue<T>::Queue(const Queue &other) {
    m_Length = other.size();
    m_First = NULL;
    m_Last = NULL;
    Queue<T>::Node *thisCurr = NULL;
    Queue<T>::Node *otherCurr = NULL;
    if(other.size()>0) {
        m_First = new Queue<T>::Node(other.getFirst());
        thisCurr = m_First;
        otherCurr = other.m_First->m_next;

    }
    for(int i=1; i<other.size(); i++) {
        thisCurr->m_next = new Queue<T>::Node(otherCurr);
        thisCurr = thisCurr->m_next;
        otherCurr = otherCurr->m_next;
    }
}
template<typename T>
Queue<T>::~Queue() {
    delete m_Length;
    Node* curr = m_First;
    if(this->m_First!=NULL) {
        m_First = m_First->m_next;

        while(this->m_First!=NULL) {
            m_First = m_First->m_next;
            delete curr;
            curr = m_First;
        }
    }
    if(this->m_Last!=NULL) {
        delete this->m_Last;
    }
}
template<typename T>
Queue<T>::pushback(T value) {
    Node* cpy = new Queue<T>::Node(value);
    cpy->m_next = m_Last;
    m_Last = cpy;
    if(m_Length==0) {
        m_First = m_Last;
    }
    m_Length++;

}
template<typename T>
Queue<T>::front() {
    return m_First->m_value;
}
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
