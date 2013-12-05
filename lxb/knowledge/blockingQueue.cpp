https://github.com/anson627/design/blob/master/BlockingQueue/BlockingQueue.cpp

//============================================================================
// implement a blocking queue implementation using ring buffer
//============================================================================

#include <iostream>
#include <mutex>
#include <thread>
#include <memory>
#include <condition_variable>

using namespace std;

class BlockingQueue {
public:
    BlockingQueue(int capacity) :
        _capacity(capacity),
        _front(0),
        _rear(0),
        _count(0) {
        _buffer = unique_ptr<int[]>(new int[capacity]);
    }
    // Inserts the specified element into this queue, waiting if necessary for space to become available.
    void put(int data) {
        unique_lock<mutex> lock(_mutex);
        _not_full.wait(lock, [this](){ return _count != _capacity; });
        push(data);    
        _not_empty.notify_one();
    }

    // Retrieves and removes the head of this queue, waiting if necessary until an element becomes available.
    int take() {
        unique_lock<mutex> lock(_mutex);
        _not_empty.wait(lock, [this](){ return _count != 0; });
        int result = pop(); 
        _not_full.notify_one();
        return result;
    }

    // Inserts the specified element into this queue, waiting up to the specified wait time if necessary for space to become available.
    bool offer(int data, chrono::milliseconds timeout) {
        unique_lock<mutex> lock(_mutex);
        if (!_not_full.wait_for(lock, timeout, [this](){ return _count != _capacity; }))
            return false;
        push(data);    
        _not_empty.notify_one();
        return true;
    }

    // Retrieves and removes the head of this queue, waiting up to the specified wait time if necessary for an element to become available.
    bool poll(int & data, chrono::milliseconds timeout) {
        unique_lock<mutex> lock(_mutex);
        if (!_not_empty.wait_for(lock, timeout, [this](){ return _count != 0; }))
            return false;
        data = pop(); 
        _not_full.notify_one();
        return true;
    }

private:
    void push(int data) {
        _buffer[_rear] = data;
        _rear = (_rear + 1) % _capacity;
        ++_count;
    }

    int pop() {
        int result = _buffer[_front];
        _front = (_front + 1) % _capacity;
        --_count;
        return result;
    }

    unique_ptr<int[]> _buffer;
    int _capacity;

    int _front;
    int _rear;
    int _count;

    mutex _mutex;
    condition_variable _not_full;
    condition_variable _not_empty;
};

void consumer_take(int id, BlockingQueue & queue) {
    for (int i = 0; i < 50; ++i) {
        int data = queue.take();
        cout << "Consumer " << id << " take " << data << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
    }
}

void producer_put(int id, BlockingQueue & queue) {
    for (int i = 0; i < 75; ++i) {
        int data = i;
        queue.put(data);
        cout << "Producer " << id << " put " << data << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer_poll(int id, BlockingQueue & queue) {
    int i = 0;
    while (i < 50) {
        int data;
        if (queue.poll(data, chrono::milliseconds(250))) {
            cout << "Consumer " << id << " poll " << data << endl;
            i++;
            continue;
        }
        cout << "Consumer " << id << " retry" << endl;    
    }
}

void producer_offer(int id, BlockingQueue & queue) {
    int i = 0;
    while (i < 75) {
        int data = i;
        if (queue.offer(data, chrono::milliseconds(100))) {
            cout << "Producer " << id << " offer " << data << endl;
            i++;
            continue;
        }
        cout << "Producer " << id << " retry" << endl;
    }
}

int main() {
    BlockingQueue queue(200);

    /*
    thread c1(consumer_take, 0, ref(queue));
    thread c2(consumer_take, 1, ref(queue));
    thread c3(consumer_take, 2, ref(queue));
    thread p1(producer_put, 0, ref(queue));
    thread p2(producer_put, 1, ref(queue));
    */
    
    thread c1(consumer_poll, 0, ref(queue));
    thread c2(consumer_poll, 1, ref(queue));
    thread c3(consumer_poll, 2, ref(queue));
    thread p1(producer_offer, 0, ref(queue));
    thread p2(producer_offer, 1, ref(queue));
    
    c1.join();
    c2.join();
    c3.join();
    p1.join();
    p2.join();

    return 0;
}
