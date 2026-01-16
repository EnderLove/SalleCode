
class IntCell{
    private:
        int storedValue;

    public:
        IntCell(int initialValue = 0) : storedValue(initialValue){}

        int read() const { return storedValue; }

        void write(int x) { storedValue = x; }
};

int main(){

    IntCell test = 10; // POSSIBLE WITHOUT "EXPLICIT"!!!!
    
    IntCell obj;

    obj = test;

    return 0;
}
