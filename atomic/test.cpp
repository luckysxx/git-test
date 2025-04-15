#include <iostream>
#include <thread>
#include <atomic>

std::atomic<bool> ready{false};
std::atomic<int> data{0};

void producer()
{
    data.store(42, std::memory_order_relaxed);    // 原子性的更新data的值, 但是不保证内存顺序
    ready.store(true, std::memory_order_release); // 保证data的更新操作先于ready的更新操作
}

void consumer()
{
    // 保证先读取ready的值, 再读取data的值
    while (!ready.load(std::memory_order_acquire))
    {
        std::this_thread::yield(); // 啥也不做, 只是让出CPU时间片
    }

    // 当ready为true时, 再原子性的读取data的值
    std::cout << data.load(std::memory_order_relaxed); // 4. 消费者线程使用数据
}

int main()
{
    // launch一个生产者线程
    std::thread t1(producer);
    // launch一个消费者线程
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
