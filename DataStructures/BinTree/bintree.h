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
        BTree() : root(nullptr){ }

        Node *insert(Node *node, int data){
            if (node == nullptr) { return new Node(data); }

            if (data < node->m_data){
                node->m_left = insert(node->m_left, data);
            } else if (data > node->m_data){
                node->m_right = insert(node->m_right, data);
            }
            return node;
        }

        Node *delNode(Node *node, T data){
            if (node == nullptr) return node;

            if (data < node->m_data){
                node->m_left = delNode(node->m_left, data);
            } else if (data > node->m_data){
                node->m_right = delNode(node->m_right, data);
            } else {
                if (node->m_left == nullptr){
                    Node *temp = node->m_right;
                    delete (node);
                    return temp;
                } else if (node->m_right){
                    Node *temp = node->m_left;
                    delete (node);
                    return temp;
                }
            }
        }

        Node *findMin(Node *node){
            while (node && node->m_left != nullptr){ node = node->m_left; }
            return node;
        }

        Node *searchNode(Node *node, T data){
            if (node == nullptr || node->m_data == data) return node;

            if (data < node->m_data){
                return searchNode(node->m_left, data);
            }
            return searchNode(node->m_right, data);
        }

        void inTravOrder(Node *node){
            if (node != nullptr){
                inTravOrder(node->m_left);
                std::cout << node->m_data << std::endl;
                inTravOrder(node->m_right);
            }
        }

        void showTree(Node* temp){
            if (temp == nullptr) return;
            
            if (temp != nullptr){
                std::cout << temp->m_data << std::endl;
                
                showTree(temp->m_left);
                showTree(temp->m_right);
            }        
        }


        Node *getRoot(){ return root; }
};

#endif // BIN_TREE_H!
