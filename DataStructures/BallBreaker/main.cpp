#include <iostream>
#include <stdio.h>
#include "stack.h"

const int   DEFAULT_WALL_DENSITY = 10;
const int   DEFAULT_BALL_MASS    = 10;
const int   DEFAULT_STACK_SIZE   =  5;
const float GRAVITY = 9.8;

class Ball{
    private:
        float m_force;
        int   m_mass;

    public:
        Ball(int mass) : m_mass(mass), m_force((float)mass * GRAVITY){}
        Ball() : m_mass(DEFAULT_BALL_MASS), m_force(DEFAULT_BALL_MASS * GRAVITY){}

        int getForce() const { return m_force; }

        void setBallMass(int mass){
            m_mass  = mass;
            m_force = m_mass * GRAVITY;
        }

        void updateForce(int decrement){ m_force -= decrement; }
        void showBall(){ std::cout << "\n\t\t\t\t  _._\n\t\t\t\t.'--.`.\n\t\t\t\t|  .' |\n\t\t\t\t `--`'\n\n\n"; }
};

class WallStack : public Stack<int>{ 
    public:
        WallStack(int size){ 
            if (size < 0) size = DEFAULT_STACK_SIZE;
            for (int i = 0; i < size; i++) push(DEFAULT_WALL_DENSITY);
        }

        void showWall() const {
            Node *temp = m_top;
            int i = 1;
            while (temp != nullptr){
                printf("[POS %02d : DENSITY %3d] #######################################\n", i, temp->m_data);
                temp = temp->m_next;
                i++;
            }
        }
        
        int getWallDensity() const {
            return (isEmpty()) ? 0 : m_top->m_data; 
        }
};

int main(){
   
    int userInput = 0;
    int wallAmout = 0;
    int ballDensity  = 0;

    std::cout << "[0] DEFALUT\t[1] SET AMOUT WALLS\n";
    std::cin >> userInput; 

    if (userInput == 1){
        std::cout << "SET THE AMOUNT OF WALLS\n";
        std::cin >> wallAmout;
    } else {
        wallAmout = -1;
    }

    WallStack wallStack(wallAmout);
    Ball gordingo;

    while (!wallStack.isEmpty()){
        system("clear");

        gordingo.showBall();
        wallStack.showWall();

        std::cout << "[0] CONFIGURE WALLS\t[1] THROW BALL\t[2] EXIT\n";
        std::cin >> userInput;

        if (userInput == 0){
            std::cout << "[0] ADD WALL\t[1] DELL WALL\n";
            std::cin >> userInput;

            if (userInput == 0){
                std::cout << "[0] DEFAULT DENSITY\t[1] SET DENSITY\n";
                std::cin >> userInput;

                if (userInput == 1){
                    std::cout << "INSERT THE DENSITY: ";
                    std::cin >> ballDensity;
                    wallStack.push(ballDensity);
                } else {
                    wallStack.push(DEFAULT_WALL_DENSITY);
                }
            } else {
                wallStack.pop();
            }
        } 
        else if (userInput == 1){
            std::cout << "SET BALL MASS: \n";
            std::cin >> ballDensity;
            gordingo.setBallMass(ballDensity);
        
            float currentForce = gordingo.getForce();
            int wallDensity = wallStack.getWallDensity();
        
            while (currentForce > wallDensity && !wallStack.isEmpty()){
                
                std::cout << "CURRENT FORCE: " << currentForce << std::endl;

                wallStack.pop();

                gordingo.updateForce(wallDensity);
                currentForce = gordingo.getForce();
                wallDensity  = wallStack.getWallDensity();
            }
        } else break;
    }

    return 0;
}
