#include <algorithm>
//#include <type_traits>

#include "../include/Stack.h"

namespace stack
{
    template<class T>
    Stack<T>::Stack()
    {
        //if (std::is_same<T, int[5]>::value) {
        //    isArr = true;
        //}
    }
    
    template<class T>
    Stack<T>::Stack(int newSize) {
        ptr = new T[newSize];
        size = newSize;
        end = 0;

        //проверка на int[]
    }
    
    template<class T>
    Stack<T>::~Stack()
    {
        if (!isArr) {
            if (ptr) {
                delete[] ptr; 
            }
        }
    }
    
    template<class T>
    Stack<T>::Stack(const Stack& other)
    {
        delete[] ptr;
        ptr = (other.ptr? new T(*other.ptr): nullptr); //при T = int[k] надо рассматривать отдельно
         
        size = other.size;
        end = other.end;
        isArr = other.isArr;
    }
    
    template<class T>
    Stack<T>::Stack(Stack&& other)
    {
        delete[] ptr;
        ptr = other.ptr;
        
        size = other.size;
        end = other.end;
        isArr = other.isArr;
        
        other.ptr = nullptr; //Вопрос! это бесполезно (нам передали rvalue)?
        other.size = 0;
        other.end = 0;
        other.isArr = false;
    }
    
    template<class T>
    Stack<T>& Stack<T>::operator=(const Stack& other)
    {
        Stack <T> interim(other);
        std::swap(interim, *this);
        
        return *this;
    }
    
    template<class T>
    Stack<T>& Stack<T>::operator=(Stack&& other)
    {
        Stack <T> interim(std::move(other));
        std::swap(interim, *this);

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
        if (size == 0) {
            std::cout << "ОШИБКА! Stack пуст\n";
            return;
        }
        
        --end;
    }
    
    template<class T>
    T Stack<T>::top()
    {
        //проблема с возращением int[]
        if (size == 0)
        {
            std::cout << "ОШИБКА! Stack пуст\n";
            T ret;
            return ret;
        }
        
        return ptr[end-1];
    }
    
    template<class T>
    int Stack<T>::getSize()
    {
        return end;
    }
}
