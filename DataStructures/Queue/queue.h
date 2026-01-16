#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class QueuePrio{
    protected:
        struct Node{
            T     m_data;
            int   m_prio;
            Node *m_next;
            Node(T data, int prio, Node *next) : m_data(data), m_prio(prio), m_next(next) {}
        };
        Node *m_front;
        Node *m_rear;
        Node *m_maxPrio;
        
    public:
        QueuePrio() : m_front(nullptr), m_rear(nullptr) {} 
       
        int m_idxPrio = 0;

        void enqueue(T data, int prio){ 
            m_front = new Node(data, prio, m_front); 
           
            if (m_idxPrio < m_front->m_prio){

                m_idxPrio = m_front->m_prio;
                m_maxPrio = m_front;
            }
        }
        // RESTART DATA FORM IDX & MAXPRIO 

        void dequeue(){
            if (!isEmpty()){
                
                Node *temp = m_front;
                Node *hold = nullptr;

                while (temp->m_next != nullptr){
    
                    if (temp->m_next == m_maxPrio){
                        temp->m_next = temp->m_next->m_next;
                        break;
                    }
                    temp = temp->m_next;
                }

                // delete(temp);
            }
        }

        bool isEmpty() const { return m_front == nullptr; } 
};

#endif // QUEUE_H!
