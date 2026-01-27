
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
