#include <iostream>

#include "../src/Stack.cpp"

signed main() {
    {
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
        
        stack::Stack <int> e(std::move(d));
        
        e.push(1);
        e.push(2);
        e.push(3);
        
         
        std::cout << "e:\n";
        while (e.getSize()) {
            std::cout << e.top() << " ";
            e.pop();
        }
        std::cout << "\n";
        
        e.push(4);
        e.push(5);
        e.push(6);
        
        stack::Stack <int> f = (std::move(e));
        
        std::cout << "f:\n";
        while (f.getSize()) {
            std::cout << f.top() << " ";
            f.pop();
        }
        std::cout << "\n";
    }    
    
    std::cout << "\n";
    
    //////////////////////////////////////
    
    {
        stack::Stack <double> g;
        
        g.push(0.5);
        g.push(1.5);
        
        std::cout << "g:\n";
        while (g.getSize()) {
            std::cout << g.top() << " ";
            g.pop();
        }
        std::cout << "\n";
    }
    
    std::cout << "\n";
    
    //////////////////////////////////////
    
    {
        stack::Stack <int> a;

        a.push(1);
        a.push(2);
        a.push(3);

        stack::Stack <int> b;
        b.push(4);
        b.push(5);
        b.push(6);
        
        b = a;
        
        stack::Stack <int> c;

        c = (std::move(b));

        std::cout << "a:\n";
        while (a.getSize()) {
            std::cout << a.top() << " ";
            a.pop();
        }
        std::cout << "\n";
        
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

    }
    
    std::cout << "\n";
    
    //////////////////////////////////////
    
    {
        stack::Stack <int> a;
        
        a.push(5);
        a.pop();
        a.pop();
        
        stack::Stack <float> b;
        b.push(5);
        std::cout << b.top() << "\n";
        b.pop();
        std::cout << b.top() << "\n";

    }
    
}
