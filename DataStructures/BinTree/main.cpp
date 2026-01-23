#include <ctime>
#include <iostream>
#include "bstlib.h"

typedef int tree_t;

int main(){
    BST<tree_t> tree;

    tree.insert(10);
    tree.insert(4);
    tree.insert(30);
    tree.insert(6);
    tree.insert(15);
    tree.insert(1);
    tree.insert(20);
    
    //tree.showTree(root);
    
    //tree.inTravOrder(root);
    //std::cout << "\n\n";
    //tree.preOrder(root);
    //std::cout << "\n\n";
    //tree.postOrder(root);

    tree_t &val = tree.pathR("RLR");

    std::cout << "\n\n" << val << std::endl;

    auto vecT = tree.levelOrder();
    auto sumT = tree.sumLevel();

    for (std::vector<int> &level : vecT){
        for (auto val : level){
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    for (auto it : sumT){
        std::cout << it << " ";
    }

    return 0;
}
