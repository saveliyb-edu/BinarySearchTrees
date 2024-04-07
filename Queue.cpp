#pragma once
#include "Queue.h"
#include "QueueException.h"

template <class T>
class CircularQueueArray : public Queue<T>
{
public:
    CircularQueueArray() = delete;
    CircularQueueArray(size_t size) {
        if (size <= 0) {
            throw WrongQueueSize();
        }
        m_array = new T[size];
        m_size = size;
        m_front = 0;
        m_rear = 0;
        m_count = 0;
    }

    CircularQueueArray(const CircularQueueArray<T>& other) {};
    CircularQueueArray(CircularQueueArray<T>&& other) {};

    ~CircularQueueArray() {
        delete[] m_array;
    }

    CircularQueueArray& operator=(const CircularQueueArray<T>& other) {
        if (this != &other) {
            delete[] m_array;
            m_size = other.m_size;
            m_front = other.m_front;
            m_rear = other.m_rear;
            m_count = other.m_count;
            m_array = new T[m_size];
            std::copy(other.m_array, other.m_array + m_size, m_array);
        }
        return *this;
    }

    CircularQueueArray& operator=(CircularQueueArray&& other) {
        if (this != &other) {
            delete[] m_array;
            m_size = other.m_size;
            m_front = other.m_front;
            m_rear = other.m_rear;
            m_count = other.m_count;
            m_array = other.m_array;
            other.m_array = nullptr;
            other.m_size = 0;
            other.m_front = 0;
            other.m_rear = 0;
            other.m_count = 0;
        }
        return *this;
    }

    void enQueue(const T& e) override {
        if (isFull()) {
            throw QueueOverflow();
        }
        m_array[m_rear] = e;
        m_rear = (m_rear + 1) % m_size;
        m_count++;
    }

    T deQueue() override {
        if (isEmpty()) {
            throw QueueUnderflow();
        }
        T temp = m_array[m_front];
        m_front = (m_front + 1) % m_size;
        m_count--;
        return temp;
    }

    bool isEmpty() override {
        return (m_count == 0);
    }

    bool isFull() {
        return (m_count == m_size);
    }

    T front() override {
		if (isEmpty()) {
			throw QueueUnderflow();
		}
		return m_array[m_front];
	}

private:
    T* m_array;
    size_t m_size;
    size_t m_front;
    size_t m_rear;
    size_t m_count;
};