class Foo {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int step;

public:
    Foo() {
        step = 1;
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        {
            std::lock_guard<std::mutex> lock(mtx);
            step = 2;
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 2; });
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        step = 3;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 3; });
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};