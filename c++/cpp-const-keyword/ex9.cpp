class Class {
    private:
        int value;
        mutable int mutValue;
    public:
        // ...
        void ConstMethod() const { 
            // value += 1; // [컴파일 에러]
            mutValue += 1;
        }
};

// void InvalidConstFunc(int val) const {  // [컴파일 에러]
//     val += 10;
// }
