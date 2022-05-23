#ifndef MTM_EX3_QUEUE_H
#define MTM_EX3_QUEUE_H
#include <iostream>
template <typename T>
class Queue{
    public:
    Queue();
    Queue(const Queue<T>&);
    ~Queue() = default;


    int size() const;
    void pushBack(T value);
    T& front();
    void popFirst();


    class EmptyQueue{};
    class Node
    {
        public:
        Node(T value);
        ~Node();
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


#endif //MTM_EX3_QUEUE_H
