#include <ctime>
#include <iostream>
#include "bintree.h"

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

    return 0;
}
