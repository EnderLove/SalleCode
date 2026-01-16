#include <iostream>
#include <stdio.h>

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

        void updateForce(int decrement){
            m_force -= decrement;
        }
        void showBall(){ std::cout << "\n\t\t\t\t  _._\n\t\t\t\t.'--.`.\n\t\t\t\t|  .' |\n\t\t\t\t `--`'\n\n\n"; }
};

class Wall{
    private:
        int m_density;
        Wall *m_next;

    public:
        Wall(int mass, Wall *next = nullptr) : m_next(next), m_density(mass) {}
        Wall() : m_next(nullptr), m_density(DEFAULT_WALL_DENSITY) {}
        
        int   getMass() const { return m_density; }
        Wall *getNext() const { return m_next;    }

        void setNext(Wall *next) { m_next    = next; }
        void setMass(int   mass) { m_density = mass; }
};

class WallStack{ 
    private:
        Wall *m_top;
        int   m_size;
        
    public:
        WallStack(int size) : m_top(nullptr){
            if (size < 0) size = DEFAULT_STACK_SIZE;
            for (int i = 0; i < size; i++){ pushWall(DEFAULT_WALL_DENSITY); }
        }

        WallStack() : m_top(nullptr) { for (int i = 0; i < DEFAULT_STACK_SIZE; i++) pushWall(DEFAULT_WALL_DENSITY); } 
        
        ~WallStack(){
            while (m_top != nullptr) popWall();
            std::cout << "\n\t======== GAME DESTROYED!! =========\n";
        }

        void pushWall(int density){ m_top = new Wall(density, m_top); }

        void popWall(){
            Wall *temp = m_top;
            m_top = m_top->getNext();
            delete(temp);
        }

        void showWall() const {
            Wall *temp = m_top;
            int i = 1;
            while (temp != nullptr){
                printf("[POS %02d : DENSITY %3d] #######################################\n", i, temp->getMass());
                temp = temp->getNext();
                i++;
            }
        }
        
        int getWallDensity() const {
            if (m_top == nullptr) return 0;
            else return m_top->getMass();
        }

        bool empty(){
            if (m_top == nullptr) return true;
            else return false;
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

    while (!wallStack.empty()){
        system("clear");

        gordingo.showBall();
        wallStack.showWall();

        std::cout << "[0] CONFIGURE WALLS\t[1] THROW BALL\t[2] EXIT\n";
        std::cin >> userInput;

        if (userInput == 0){
            std::cout << "[0] ADD WALL\t[1] DELL WALL\n";
            std::cin >> userInput;

            if (userInput == 0){
                std::cout << "[0] DEFAULT MASS\t[1] SET MASS\n";
                std::cin >> userInput;

                if (userInput == 1){
                    std::cout << "INSERT THE DENSITY: ";
                    std::cin >> ballDensity;
                    wallStack.pushWall(ballDensity);
                } else {
                    wallStack.pushWall(DEFAULT_WALL_DENSITY);
                }
            } else {
                wallStack.popWall();
            }
        } 
        else if (userInput == 1){
            std::cout << "SET BALL MASS: \n";
            std::cin >> ballDensity;
            gordingo.setBallMass(ballDensity);
        
            float currentForce = gordingo.getForce();
            int wallDensity = wallStack.getWallDensity();
        
            while (currentForce > wallDensity){
                if (wallStack.empty()) break;

                wallStack.popWall();

                gordingo.updateForce(wallDensity);
                currentForce = gordingo.getForce();
                wallDensity  = wallStack.getWallDensity();
            }
        } else break;
    }

    return 0;
}
