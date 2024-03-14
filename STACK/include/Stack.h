#ifndef CPP_STACK
#define CPP_STACK


namespace stack
{

template<class T>
class Stack {

public:
    Stack();
    explicit Stack(int n);
    ~Stack();

    Stack(const Stack& other);
    Stack(Stack&& other);
    
    Stack<T>& operator=(const Stack& other);
    Stack<T>& operator=(Stack&& other);
    
    void push(const T& element);
    void pop();
    T top();
    
    int getSize();
        
private: 
    T* ptr = nullptr;
    int size = 0;
    int end = 0;
    
    void resize(int newSize);
    void swap(Stack& first, Stack& second);

};

}

#endif //CPP_STACK
