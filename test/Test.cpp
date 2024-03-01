#include <iostream>

#include "../src/Stack.cpp"

signed main() {
    stack::Stack <int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    
    stack::Stack <int> c(b);
     
    std::cout << "c:\n";
    while (c.getSize()) {
        std::cout << c.top() << " ";
        c.pop();
    }
    std::cout << "\n";
    
    c.push(4);
    c.push(5);
    c.push(6);
    
    stack::Stack <int> d = c;
    
    d.pop();
    d.push(7);
    
    std::cout << "b:\n";
    while (b.getSize()) {
        std::cout << b.top() << " ";
        b.pop();
    }
    std::cout << "\n";
     
    std::cout << "c:\n";
    while (c.getSize()) {
        std::cout << c.top() << " ";
        c.pop();
    }
    std::cout << "\n";
     
    std::cout << "d:\n";
    while (d.getSize()) {
        std::cout << d.top() << " ";
        d.pop();
    }
    std::cout << "\n";
    
}
