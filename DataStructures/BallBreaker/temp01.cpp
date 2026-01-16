#include <iostream>
#include <string>
#include "stack.h"

struct Image{
    std::string fileName;
    int xPixel;
    int yPixel;
};

class Galery : public Stack<Image>{
    public:

        void showGalery(){
            if (!m_top) return;
            
            int format = m_top->m_data.fileName.length();

            Node *temp = m_top;
            while (temp != nullptr){

                printf("IMAGE_NAME: %*s || PIXEL_XY: [%d, %d]\n",
                        format, temp->m_data.fileName.c_str(), temp->m_data.xPixel, temp->m_data.yPixel);

                temp = temp->m_next;
            }
        }
};

int main(){

    Galery galery;

    std::string imageName;
    int pixelsX = 0;
    int pixelsY = 0;
    int input   = 0;
    
    while (true){
        system("clear");
        galery.showGalery();
        
        std::cout << "[0] ADD IMAGE\t[1] DEL IMAGE\n";
        std::cin >> input;

        if (input == 0){
            std::cout << "INSERT THE IMAGE NAME: \n";
            std::cin >> imageName;
            std::cout << "INSERT X DIMENSION (PIXEL): \n";
            std::cin >> pixelsX;
            std::cout << "INSERT Y DIMENSION (PIXEL): \n";
            std::cin >> pixelsY;

            galery.push({imageName, pixelsX, pixelsY});
        } else {
            galery.pop();
        }
    }
    return 0;
}
