#include <iostream>
#include "bintree.h"


int main(){

    BTree<int> tree;
    auto root = tree.getRoot();

    root = tree.insert(root, 10);
    root = tree.insert(root, 4);
    root = tree.insert(root, 30);
    root = tree.insert(root, 6);
    root = tree.insert(root, 15);
    root = tree.insert(root, 1);
    root = tree.insert(root, 20);
    
    //tree.showTree(root);
    
    tree.inTravOrder(root);
    std::cout << "\n\n";
    tree.preOrder(root);
    std::cout << "\n\n";
    tree.postOrder(root);

    int &val = tree.path(root, "RLR");

    std::cout << "\n\n" << val << std::endl;

    return 0;
}
