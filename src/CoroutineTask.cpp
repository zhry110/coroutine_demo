//
// Created by like1 on 2021/2/8.
//

#include "CoroutineTask.h"

template<class T>

CoroutineTask<T>::CoroutineTask(const coroutine_handle<promise_type> &handle) : handle(handle) {

}

template<class T>
CoroutineTask<T> CoroutineTask<T>::promise_type::get_return_object() {
    return CoroutineTask(coroutine_handle<promise_type>::
                         from_promise(*this));
}

template<class T>
suspend_never CoroutineTask<T>::promise_type::initial_suspend() const {
    return suspend_never();
}

template<class T>
void CoroutineTask<T>::promise_type::unhandled_exception() const {
    std::terminate();
}

template<class T>
void CoroutineTask<T>::promise_type::return_void() const {

}

template<class T>
suspend_never CoroutineTask<T>::promise_type::yield_value(T _value) {
    value = _value;
    return suspend_never();
}

template<class T>
suspend_never CoroutineTask<T>::promise_type::final_suspend() const noexcept {
    return suspend_never();
}

template
class CoroutineTask<int>;