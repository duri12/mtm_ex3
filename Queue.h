#ifndef MTM_EX3_QUEUE_H
#define MTM_EX3_QUEUE_H
template <typename T>
class Queue{
    public:

    private:
    class Node{
        T* m_value;
        Node m_next;
    };
    Node m_Last;
    Node m_First;
    int Length;
};
#endif //MTM_EX3_QUEUE_H
