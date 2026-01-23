#ifndef BST_LIB_H
#define BST_LIB_H

#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class BST{
    private: 
        struct Node{
            T     m_data;
            Node *m_left;
            Node *m_right;
            Node (T data, Node *leftNode = nullptr, Node *rightNode = nullptr) :
                m_data(data), m_left(leftNode), m_right(rightNode) {} 
        };
    
        Node *root;

        Node *insert(Node *node, T data){
            if (node == nullptr) { return new Node(data); }

            if      (data < node->m_data) node->m_left  = insert(node->m_left,  data);
            else if (data > node->m_data) node->m_right = insert(node->m_right, data);
            return node;
        }
        
        Node *delNode(Node *node, T data){
            if (node == nullptr) return nullptr;

            if      (data < node->m_data){ node->m_left  = delNode(node->m_left,  data); }
            else if (data > node->m_data){ node->m_right = delNode(node->m_right, data); }
            else {
                if (node->m_left == nullptr){
                    Node *temp = node->m_right;
                    delete (node);
                    return temp;
                } else if (node->m_right == nullptr){
                    Node *temp = node->m_left;
                    delete (node);
                    return temp;
                }
                
                Node *temp    = findMin(node->m_right);
                node->m_data  = temp->m_data;
                node->m_right = delNode(node->m_right, temp->m_data);
            }
            return node;
        } 

        void destroyer(Node *node){
            if (node == nullptr) return;
            destroyer(node->m_left);
            destroyer(node->m_right);
            delete (node);
        }

        T &pathR(Node *node, const std::string &path, int index){
            if (node == nullptr) throw std::runtime_error("EMPTY TREE");

            if (index >= path.length() || path[index] == '_') return node->m_data;

            if      (path[index] == 'R') return pathR(node->m_right, path, index + 1);
            else if (path[index] == 'L') return pathR(node->m_left , path, index + 1);

            return node->m_data;
        }

        T &pathL(Node *node, std::string path){
            if (root == nullptr) throw std::runtime_error("EMPTY TREE");

            Node *temp = root;
            for (char direction : path){
                if (direction == '_') break;

                if (direction == 'R'){
                    if (temp->m_left != nullptr) temp = temp->m_right;
                    else throw std::runtime_error("PATH LEADS TO NULL");
                } else if (direction == 'L'){
                    if (temp->m_left != nullptr) temp = temp->m_left;
                    else throw std::runtime_error("PATH LEADS TO NULL");
                }
            }
            return temp->m_data;
        }

        void levelOrderRec(Node *root, int level, std::vector<std::vector<int>> &res){
            if (root == nullptr) return;

            if (res.size() <= level) res.push_back({});

            res[level].push_back(root->m_data);

            levelOrderRec(root->m_left , level + 1, res);
            levelOrderRec(root->m_right, level + 1, res);
        }

        void sumLevelRec(Node *root, int level, std::vector<int> &sum){
            if (root == nullptr) return;

            if (sum.size() <= level) sum.push_back({});
    
            sum[level] += root->m_data;

            sumLevelRec(root->m_left , level + 1, sum);
            sumLevelRec(root->m_right, level + 1, sum);
        }


    public:
        BST() : root(nullptr){ }
        ~BST() { destroyer(root); }

        void insert (T data) { root = insert (root, data); } 
        void delNode(T data) { root = delNode(root, data); } 

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
       
        void preOrder(Node *node){
            if (node != nullptr){
                std::cout << node->m_data << std::endl;
                preOrder(node->m_left);
                preOrder(node->m_right);
            }
        }

        void postOrder(Node *node){
            if (node != nullptr){
                postOrder(node->m_left);
                postOrder(node->m_right);
                std::cout << node->m_data << std::endl;
            }
        }

        std::vector<std::vector<int>> levelOrder(){

            std::vector<std::vector<int>> res;

            levelOrderRec(root, 0, res);
            return res;
        }
       
        std::vector<int> sumLevel(){
            std::vector<int> sum;
           
            sumLevelRec(root, 0, sum);

            return sum;
        }
      
        T &pathR(std::string path){ return pathR(root, path, 0); }
        T &pathL(std::string path){ return pathL(root, path   ); }

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

#endif // BST_LIB_H!
