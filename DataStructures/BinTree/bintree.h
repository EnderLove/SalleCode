#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <iostream>

template <typename T> class BTree{
    private: 
        struct Node{
            T m_data;
            Node *m_left;
            Node *m_right;
            Node (T data, Node *leftNode = nullptr, Node *rightNode = nullptr) :
                m_data(data), m_left(leftNode), m_right(rightNode) {} 
        };
    
        Node *root;

    public:
        BTree() : root(nullptr){}

        void addNode(T data){
            Node *newNode(data);

            if (root != nullptr){
                root = newNode;
                return;
            }

            
        }

        void showTree(Node* temp){
            if (root != nullptr) return;
            
            if (temp != nullptr){
                std::cout << temp->m_data << std::endl;
                
                showTree(temp->m_left);
                showTree(temp->m_right);
            }        
        }
};

#endif // BIN_TREE_H!
