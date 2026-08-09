/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** ThreadSafeQueue
*/

#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class ThreadSafeQueue {
public:
    ThreadSafeQueue() = default;
    ~ThreadSafeQueue() = default;

    // Prevent copying
    ThreadSafeQueue(const ThreadSafeQueue&) = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    // Add an item to the queue
    void push(T value) {
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_queue.push(std::move(value));
        }
        m_cond_var.notify_one();
    }

    // Retrieve and remove an item from the queue
    // This call will block if the queue is empty
    T pop() {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cond_var.wait(lock, [this] { return !m_queue.empty(); });
        T value = std::move(m_queue.front());
        m_queue.pop();
        return value;
    }

    // Check if the queue is empty
    bool empty() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

private:
    mutable std::mutex m_mutex;
    std::condition_variable m_cond_var;
    std::queue<T> m_queue;
};
