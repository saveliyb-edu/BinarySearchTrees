#pragma once
#include "Stack.h"
#include "StackException.h"


template <class T>
class StackArray : public Stack<T>
{
public:
    StackArray() = delete;
    StackArray(size_t size) {
        if (size <= 0) {
            throw WrongStackSize();
        }
        try
        {
            m_array = new T[size];
            m_size = size;
            m_nowSize = 0;
        }
        catch (const std::exception& ex)
        {
            throw ex;
        }
    }
    StackArray(const StackArray<T>& other) {};
    StackArray(StackArray<T>&& other) {};
    ~StackArray() {
        delete[] m_array;
    }

    StackArray& operator=(const StackArray<T>& other) {
        if (this != &other) {
            delete[] m_array;
            m_size = other.m_size;
            m_nowSize = other.m_nowSize;
            m_array = new T[m_size];
            std::copy(other.m_array, other.m_array + m_nowSize, m_array);
        }
        return *this;
    };

    size_t getSize() {
        return m_nowSize;
    }

    StackArray& operator=(StackArray&& other) {
        if (this != &other) {
            delete[] m_array;
            m_size = other.m_size;
            m_nowSize = other.m_nowSize;
            m_array = other.m_array;
            other.m_array = nullptr;
            other.m_size = 0;
            other.m_nowSize = 0;
        }
        return *this;
    };

    void push(const T& e) {
        if (m_nowSize == m_size)
        {
            throw StackOverflow();
        }
        m_array[m_nowSize] = e;
        m_nowSize += 1;
    };
    T pop() {
        if (isEmpty()) {
            throw WrongStackSize();
        }
        T temp = m_array[m_nowSize - 1];
        m_nowSize -= 1;

        return temp;
    };

    bool isEmpty() {
        return (m_nowSize == 0);
    };
    
    T top() {
        if (isEmpty()) {
            throw WrongStackSize();
        }
        return m_array[m_nowSize - 1];
    }


private:
    T* m_array;
    size_t m_size;
    size_t m_nowSize;
};