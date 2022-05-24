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
    void popFirst();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;
    class Iterator;
    Iterator begin();
    Iterator end();

    class EmptyQueue{};
    class Node
    {
        public:
        Node(const T& value);
        ~Node() = default;
        Node(const Node&);

    private:
        T m_value;
        Node* m_next;
    };

private:
    Node* m_Last;
    Node* m_First;
    int m_Length;

};

template<class T>
class Queue<T>::Iterator {
    const Queue* m_q;
    int m_index;
    Iterator(const Queue* q, int index);
    friend class Queue;
public:
    class InvalidOperation{};
    const T& operator*() ;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator!=(const Iterator& it) ;
};
#endif //MTM_EX3_QUEUE_H
