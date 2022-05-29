#ifndef MTM_EX3_QUEUE_H
#define MTM_EX3_QUEUE_H
#include <iostream>

template <class T>
class Queue{
    public:
    Queue();
    Queue(const Queue<T>&);
    Queue& operator=(const Queue<T>&);
    ~Queue() ;


    int size() const;
    void pushBack(const T& value);
    T& front();
    void popFront();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;
    class Iterator;
    Iterator begin();
    Iterator end();

    class EmptyQueue{};
    class Node;

private:
    Node* m_Last;
    Node* m_First;
    int m_Length;
    friend class Node;

};

template<class T>
class Queue<T>::Node
{
public:
    Node(const T& value);
    ~Node() = default;
    Node(const Node&);

private:
    T m_value;
    Node* m_next;
    friend class Queue;

};
template<class T>
class Queue<T>::Iterator {
    const Queue* m_q;
    Queue<T>::Node* m_element;
    Iterator(const Queue* q, Queue<T>::Node* index);
    friend class Queue;
public:
    class InvalidOperation{};
    const T& operator*() ;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator!=(const Iterator& it) ;
};

template<class T>
class Queue<T>::ConstIterator {
    const Queue* m_q;
    Queue<T>::Node* m_element;
    ConstIterator(const Queue* q,Queue<T>::Node* element);
    friend class Queue;
public:
    class InvalidOperation{};
    const T& operator*() ;
    const ConstIterator& operator++()  ;
    const ConstIterator & operator++(int) const;
    bool operator!=(const  ConstIterator& it) const ;
};

template<class T,class Condition>
Queue<T> filter(const Queue<T>& originalQueue , const Condition myCondition );
template<class T,class Transformer>
void transform(const Queue<T>& originalQueue , const Transformer myCondition );


template<typename T>
Queue<T>::Iterator::Iterator(const Queue* q,Queue<T>::Node* element) {
    m_q = q;
    m_element = element;
}

template<typename T>
const T& Queue<T>::Iterator::operator*() {
    if(this ->m_element == NULL)
    {
        throw(Queue<T>::Iterator::InvalidOperation());
    }

    return this->m_element->m_value;
}


template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    if(this ->m_element == NULL){
        throw(Queue<T>::Iterator::InvalidOperation());
    }
    this->m_element = this->m_element->m_next;
    return *this;
}


template<typename T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {

    Iterator result = *this;
    ++*this;
    return result;
}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) {
    if (it.m_q != this->m_q)
    {
        throw(Queue<T>::Iterator::InvalidOperation());
    }
    return this->m_element != it.m_element;
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::begin()  {
    return Iterator(this, this->m_First);
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::end()  {
    return Iterator(this,NULL);
}

template<class T>
Queue<T>::Queue()
{
    m_First = NULL;
    m_Length = 0;
    m_Last = NULL;

}
template<typename T>
Queue<T>::Queue(const Queue<T> &other)
{
    m_Length = 0;
    m_First = NULL;
    m_Last = NULL;
    Queue<T>::Node *thisCurr = other.m_First;
    for (int i = 0; i < other.size(); i++){
        pushBack(thisCurr->m_value);
        thisCurr = thisCurr->m_next;
    }
    m_Length = other.size();


}
template<typename T>
Queue<T>::~Queue()
{
    Node* temp;

    while( this->m_First != NULL)
    {
        temp = this->m_First;
        this->m_First = this->m_First->m_next;
        delete temp;
    }

}



template<typename T>
T& Queue<T>::front()
{
    if (this->m_Length == 0)
    {
        throw(EmptyQueue());
    }
    return this->m_First->m_value;
}



template<typename T>
Queue<T>::Node::Node(const T& value){
    m_value = value;
    m_next = NULL;
}


template<typename T>
Queue<T>::Node::Node(const Queue<T>::Node &other) {
    this->m_value = other.m_value;
    this->m_next = NULL;
}

template<typename T>
int Queue<T>::size() const {
    return m_Length;
}

template<typename T>
void Queue<T>::pushBack(const T &value) {
    Node *newNode = new Queue<T>::Node(value);
    if(this->m_Length == 0 )
    {
        this->m_First = newNode;
        this->m_Last = newNode;
    }
    else
    {
        this->m_Last->m_next = newNode;
        this->m_Last = newNode;
    }
    this->m_Length ++ ;
}

template<typename T>
void Queue<T>::popFront()
{
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
    delete this->m_First;
    this->m_First = temp;
    this->m_Length -- ;
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other) {
    delete this->m_First;
    for (int i = 0; i <other.m_Length; i++)
    {
        pushBack(other.m_Queue[i]);
    }
    this->m_Length = other.m_Length;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const {
    return ConstIterator(this,this->m_First);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const {
    return ConstIterator(this, NULL);
}

template<class T>
Queue<T>::ConstIterator::ConstIterator(const Queue *q, Queue<T>::Node* element){
    this->m_q = q;
    this->m_element = element;
}

template<class T>
const T& Queue<T>::ConstIterator::operator*() {
    if(this->m_element == NULL)
    {
        throw(Queue<T>::ConstIterator::InvalidOperation());
    }
    return this->m_element->m_value;
}

template<class T>
const typename Queue<T>::ConstIterator & Queue<T>::ConstIterator::operator++(int) const {
    ConstIterator result = *this;
    ++*this;
    return result;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const Queue<T>::ConstIterator &it) const {
    if (it.m_q != this->m_q )
    {
        throw(Queue<T>::ConstIterator::InvalidOperation());
    }
    return this->m_element != it.m_element;
}

template<class T>
const typename Queue<T>::ConstIterator &Queue<T>::ConstIterator::operator++() {
    if(this ->m_element == NULL){
        throw(Queue<T>::ConstIterator::InvalidOperation());

    }
    this->m_element= this->m_element->m_next ;
    return *this;
}

template<class T,class Condition>
Queue<T> filter(const Queue<T>& originalQueue , const Condition myCondition ){
    Queue<T> newQueue;
    if(originalQueue.size() ==0)
    {
        return newQueue;
    }
    for (typename Queue<T>::ConstIterator i = originalQueue.begin(); i != originalQueue.end(); ++i)
    {
        if(myCondition(*i) == true)
        {
            newQueue.pushBack(*i);
        }
    }
    return newQueue;
}
template<class T,class Transformer>
void transform(const Queue<T>& originalQueue ,const Transformer myCondition){
    for (typename Queue<T>::ConstIterator i = originalQueue.begin(); i != originalQueue.end(); ++i)
    {
        myCondition((int&)*i);
    }
}

#endif //MTM_EX3_QUEUE_H
