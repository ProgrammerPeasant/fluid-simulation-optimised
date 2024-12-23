#ifndef FLUID_SIMULATION_OPTIMISED_THREADPOOL_H
#define FLUID_SIMULATION_OPTIMISED_THREADPOOL_H

#include <vector>
#include <thread>
#include <queue>
#include <future>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <optional>

class ThreadPool {
public:
    explicit ThreadPool(size_t);

    ~ThreadPool();

    template <class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
    -> std::future<typename std::invoke_result<F, Args...>::type>;

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

#endif //FLUID_SIMULATION_OPTIMISED_THREADPOOL_H
