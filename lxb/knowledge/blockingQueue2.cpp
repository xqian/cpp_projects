Refer: http://www.zybuluo.com/smilence/note/540

template <typename T>
class BlockingQueue{
    private:
        queue<T> _queue;
        mutex _mutex;
        condition_variable _cond;
    public:
        void push( const T& item){
            unique_lock<mutex> locker(_mutex);
            _queue.push(item);
            locker.unlock();
            _cond.notify_one(); 
        }
        T pop(){
            unique_lock<mutex> locker(_mutex);
            _cond.wait(locker, [=](){ return !_queue.empty() ;} );  //lambda function, capture by value
            T item = _queue.front();
            _queue.pop();
            return item; 
        }
};
