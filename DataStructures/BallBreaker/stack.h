#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack{
    protected:
        struct Node{
            T m_data;
            Node *m_next;
            Node(T data, Node *next) : m_data(data), m_next(next) {}
        };
        Node *m_top;

    public:
        Stack() : m_top(nullptr) {}

        ~Stack() { while (!isEmpty()) pop(); }

        void push(T data) { m_top = new Node(data, m_top); }

        void pop(){
            if (m_top){
                Node *temp = m_top;
                m_top = m_top->m_next;
                delete (temp);
            }
        }

        bool isEmpty() const { return m_top == nullptr; }
};

#endif //STACK_H!
