//
// Created by like1 on 2021/2/8.
//

#ifndef COROUTINE_DEMO_COROUTINETASK_H
#define COROUTINE_DEMO_COROUTINETASK_H

#include <experimental/coroutine>

using std::experimental::coroutine_handle;
using std::experimental::suspend_never;

template<class T>
class CoroutineTask {
public:

    class promise_type;

private:
    coroutine_handle<promise_type> handle;
public:
    explicit CoroutineTask(const coroutine_handle<promise_type> &handle);

    class promise_type {
    private:
        T value;
    public:
        CoroutineTask get_return_object();

        inline suspend_never initial_suspend() const;

        inline suspend_never final_suspend() const noexcept;

        inline suspend_never yield_value(T value);

        inline void return_void() const;

        void unhandled_exception() const;
    };
};


#endif //COROUTINE_DEMO_COROUTINETASK_H
