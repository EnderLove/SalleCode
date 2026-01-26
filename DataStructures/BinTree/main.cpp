#include <ctime>
#include <iostream>
#include <vector>
#include "bstlib.h"

typedef int tree_t;

int main(){
    BST<tree_t> tree;
   
    std::vector<int> values = {10, 4, 30, 6, 15, 1, 20};

    for (int val : values) tree.insert(val);
    
    std::string path = "RLRR";
    //tree_t &val = tree.pathR(path);

//    std::cout << "\n" << path << ": " << val << "\n"; 

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
    for (auto it : sumT){ std::cout << it << " "; }

    std::cout << "\n";

    int height = tree.height();
    std::cout << "height: " << height << std::endl;


    tree.destroyer(tree.getRoot());

    levelVec = tree.levelOrder();
    std::cout << "\nLEVEL ORDER: \n";
    for (std::vector<int> &level : levelVec){
        for (auto val : level){
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
