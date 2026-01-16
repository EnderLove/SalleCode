#ifndef PRIO_QUEUE_H
#define PRIO_QUEUE_H

template<typename T, typename P>
class QueuePrio{
    protected:
        struct Node{
            T     m_data;
            P     m_prio;
            Node *m_next;
            Node(T data, P prio, Node *next) : m_data(data), m_prio(prio), m_next(next) {}
        };
        Node *m_front;
        Node *m_rear;
        Node *m_maxPrio;
        
    public:
        QueuePrio() : m_front(nullptr), m_rear(nullptr) {} 
    
        void enqueue(T data, int prio){ 
            m_front = new Node(data, prio, m_front); 
        }

        void dequeue(){
            if (!isEmpty()){
                
                Node *maxPrioNode = getMaxPrio();
                Node *temp = m_front;
                
                if (maxPrioNode == m_front){
                    m_front = m_front->m_next;
                    delete (maxPrioNode);
                    return;
                }

                while (temp->m_next != nullptr && temp->m_next != maxPrioNode){
                    temp = temp->m_next;
                } 

                if (temp->m_next == maxPrioNode){
                    temp->m_next = maxPrioNode->m_next;
                    delete (maxPrioNode);
                }
            }
        }

        Node *getMaxPrio(){
            if (isEmpty()) return nullptr;
            
            Node *temp        = m_front;
            Node *prioNode    = m_front;
            P     highestPrio = m_front->m_prio;

            while (temp != nullptr){
                if (temp->m_prio > highestPrio || temp->m_prio == highestPrio){
                    highestPrio = temp->m_prio;
                    prioNode    = temp;
                } 
                temp = temp->m_next;
            } 
            return prioNode;
        }

        Node const *getFront() const { return m_front; }

        bool isEmpty() const { return m_front == nullptr; } 
};

#endif // PRIO_QUEUE_H!
