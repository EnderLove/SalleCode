#include <ctime>
#include <iostream>
#include <vector>
#include "avllib.h"

typedef int tree_t;

int main(){
    AVL<tree_t> tree;
   
    //std::vector<int> values = {10, 4, 30, 6, 15, 1, 20, 45, 22};
    std::vector<int> values = {10, 4, 30, 6 };
    for (int val : values) tree.insert(val);
    

    tree.delNode(10);
    tree.delNode(4);
    tree.delNode(30);
    tree.delNode(6);

    auto levelVec = tree.levelOrder();
    auto sumT     = tree.sumLevel();

    std::cout << "\nLEVEL ORDER: \n";
    for (std::vector<int> &level : levelVec){
        for (auto val : level){
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nSUM LEVEL: ";
    for (auto it : sumT){
        std::cout << it << " ";}
    std::cout << "\n";

    int height = tree.height();
    std::cout << "height: " << height << std::endl;

    return 0;
}
