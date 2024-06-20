class Class {
    private:
        int value;
        mutable int mutValue;
    public:
        Class(int val): value(val), mutValue(val) {}
        void Increment() { 
            value+=1;
            mutValue+=1;
        }
        void Increment() const {
            // value+=1; // [컴파일 에러]
            mutValue+=1;
        }
};
