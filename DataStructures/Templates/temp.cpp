#include <iostream>

template <typename A, typename B> class Pair{
    private:
        A m_x;
        B m_y;
    public:
        Pair(A val1, B val2) : m_x(val1), m_y(val2) {} 
        Pair(){}

        A first()  { return m_x; }
        B second() { return m_y; }

        void first(A val)  { m_x = val; }
        void second(B val) { m_y = val; }

        bool equal(Pair one, Pair two){
            if (one.first() == two.first() && one.second() == two.second()) return true;
            else return false;
        }

        void showPair(){ std::cout << "[" << m_x << " : " << m_y << "]" << std::endl; }
};

int main(){
    
    Pair<int, int> test(10, 20);
    Pair<int, int> sec(30, 20);
    
    test.first(30);
    
    std::cout << test.first() << " : " << test.second() << std::endl; 
        
    test.showPair();

    

    return 0;
}
