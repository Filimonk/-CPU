#include <algorithm>
#include <iostream>
#include "../include/Stack.h"

namespace stack
{
    template<class T> 
    Stack<T>::Stack() = default;
            
    template<class T>
    Stack<T>::Stack(int newSize)
    {
        ptr = new T[newSize];
        size = newSize;
        end = 0;
    }
    
    template<class T>
    Stack<T>::~Stack()
    {
        delete[] ptr; 
    }
    
    
    template<class T>
    void Stack<T>::swap(Stack& first, Stack& second)
    {
        std::swap(first.ptr, second.ptr);
        std::swap(first.size, second.size);
        std::swap(first.end, second.end);
    }


    template<class T>
    Stack<T>::Stack(const Stack& other)
    {
        delete[] ptr;
        ptr = (other.ptr? new T[other.size]: nullptr);
        std::copy(other.ptr, other.ptr + other.size, ptr);
         
        size = other.size;
        end = other.end;
    }
    
    template<class T>
    Stack<T>::Stack(Stack&& other)
    {
        delete[] ptr;
        ptr = other.ptr;
        
        size = other.size;
        end = other.end;
        
        other.ptr = nullptr;
        other.size = 0;
        other.end = 0;
    }
    
    template<class T>
    Stack<T>& Stack<T>::operator=(const Stack& other)
    {
        Stack <T> interim(other);
        swap(interim, *this);
        
        return *this;
    }
    
    template<class T>
    Stack<T>& Stack<T>::operator=(Stack&& other)
    {
        Stack <T> interim(std::move(other));
        swap(interim, *this);

        return *this;
    }
    
    
    template<class T>
    void Stack<T>::resize(int newSize) {
        T* interim = new T[newSize];
        std::copy(ptr, ptr + size, interim);
        size = newSize;
        
        delete[] ptr;
        std::swap(interim, ptr);
    }
    
    
    template<class T>
    void Stack<T>::push(const T& element)
    {
        if (end >= size) {
            (*this).resize(std::max(size * 2, 1));
        }
        
        ptr[end] = element;
        ++end;
    }
    
    template<class T>
    void Stack<T>::pop()
    {
        if (end == 0) {
            std::cout << "ОШИБКА! Stack пуст\n";
            throw "ERROR! Stack is empty";
        }
        
        --end;
    }
    
    template<class T>
    T Stack<T>::top()
    {
        if (end == 0)
        {
            std::cout << "ОШИБКА! Stack пуст\n";
            throw "ERROR! Stack is empty";
        }
        
        return ptr[end-1];
    }
    
    template<class T>
    int Stack<T>::getSize()
    {
        return end;
    }
}
