#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>

using namespace std;

struct Node {
    Node *next;
};

class LockFreeQueue {
private:
        
    atomic<Node*> head;

public:
    LockFreeQueue() {
        head = nullptr;
    }

    void push(Node *newNode) {
        Node * expected = nullptr, * desired = nullptr;
        atomic_compare_exchange_strong(&head, &expected, desired);
        while (true) {
            newNode->next = expected;
            if (atomic_compare_exchange_strong(&head, &expected, newNode))
                return;
        }
    }
    
    Node * pop() {
        Node * expected = nullptr, * desired = nullptr;
        while (true) {
            if (atomic_compare_exchange_strong(&head, &expected, desired)) 
                return expected;
            else 
                desired = expected->next; 
        }

        return nullptr;
    }
};

void consumer_pop(int id, LockFreeQueue & queue) {
    for (int i = 0; i < 50; ++i) {
        Node * node = queue.pop();
        cout << "Consumer " << id << " pop " << node << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
    }   
}

void producer_push(int id, LockFreeQueue & queue) {
    for (int i = 0; i < 75; ++i) {
        Node * node = new Node();
        queue.push(node);
        cout << "Producer " << id << " push " << node << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }   
}


int main() {
    LockFreeQueue queue;
    thread c1(consumer_pop, 0, ref(queue));
    thread c2(consumer_pop, 1, ref(queue));
    thread c3(consumer_pop, 2, ref(queue));
    thread p1(producer_push, 0, ref(queue));
    thread p2(producer_push, 1, ref(queue));

    c1.join();
    c2.join();
    c3.join();
    p1.join();
    p2.join();

    return 0;
}
