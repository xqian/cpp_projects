这道题目非常复杂，首先能想到n*log(n)的算法就不简单，即使想到了，能够在面试的
压力下把逻辑coding出来也非常的难。我感觉电面中，问到这种题目而且要coding的，
如果从没有见过，基本就是不让你过。感觉这种题目适合onsite用。

在知道算法后，我大概花了一些时间，写了如下的代码，基本思路就是楼上讨论的。
1. 首先把所有的interval的起点和终点存进一个vector<timePoint>,并且sort
struct timePoint {
    int point;
    bool startORend;
    int vol;
    timePoint(int p, bool s, int v): point(p), startORend(s), vol(v) {}
};
2. 建立一个multiset用来存储还没有结束的volume，同时可以用来判断某个时间段是
否被输入的interval cover了。
3. 然后扫描vector<timePoint>开始建立输出的vector：
1）如果碰到start的点，先检查multiset是否为空，如果是，就是insert当前point的
volume；如果不为空，就比较当前volume与multiset里的最大值，如果当前的volume大
，那就创建一个interval，push到输出的vector里去；否则，新的时间段仍可以被前一
段cover
2）如果碰到end的点，先erase当前的volume，然后判断multiset是否为空，如果为空
，创建一个interval，push到输出的vector；如果不为空，检查multiset里的最大值是
否比当前的volume要小，如果是，创建一个interval，否则（最多是等于），就不创建。
代码如下，感觉肯定有bug，欢迎大家指正
struct timePoint {
    int point;
    bool startORend;
    int vol;
    timePoint(int p, bool s, int v): point(p), startORend(s), vol(v) {}
};

struct Interval {
    int start, end;
    int vol;
    Interval(int s, int e, int v): start(s), end(e), vol(v) {}
};

static bool compare(timePoint &p1, timePoint &p2) {return p1.point<p2.point;}

vector<Interval> findMaxVol(vector<vector<Interval> > &intv) {
    vector<Interval> ret;
    if(intv.size()<2) return intv;
    vector<timePoint> p;
    for(int i=0; i<intv.size(); i++) {
        p.push_back(timePoint(intv.start, 0, invl.vol));
        p.push_back(timePoint(intv.end, 1, invl.vol));
    }
    sort(p.begin(), p.end(), compare);
    multiset<int> mp;    
    timePoint prev(p[0].point, 0, p[0].vol);
    mp.insert(p[0].vol);
    for(int i=1; i<p.size(); i++) {
        if(p.startORend==0) {
            if(mp.empty()==0) {
                int vol = *(--mp.end());
                if(p[i].vol>vol) {
                    ret.push_back(Inverval(prev.point, p[i].point, vol));
                    prev = p[i];
                }
            } else prev = p[i].point; //which means that the time before 
this is not covered by the input            
            mp.insert(p[i].vol);
        }
        else {           
            mp.erase(prev.vol);
            if(mp.empty()==0) { //some time space is not covered by the 
input
                int vol = *(--mp.end());
                if(vol<prev.vol) ret.push_back(Interval(prev.point, p[i].
point, prev.vol));               
                prev_start = p[i].point;
            } else ret.push_back(Interval(prev.point, p[i].point, prev.vol));
        }
    }
    return ret;
}


/*On(n) ?*/
发信人: lcheng16 (chenglg), 信区: JobHunting
标  题: Re: G电面的一个题
发信站: BBS 未名空间站 (Fri Nov 15 15:26:50 2013, 美东)

这一题跟skyline 不同，是个变形体吧。  两个speaker ， 各自事件已经排序且没有
重叠， 相互事件可以重叠。

用于记volumn的maxHeap 最多有两个元素。用于记录time event 的minHeap 同样

不用把两个speaker的事件merge再sort，keep一个size为2 的 timeevent 的minheap，
一开始把两个speaker的start event放进time heap。 然后开始pop timeevent heap. 

pop出start event的时候，往volumn heap里面push 这个start event 对应的volumn 
同时把这个start event对应的end event push进time heap。update result

pop出end event 的时候， 把volumn heap里面对应的volumn pop出来， 把这个
speaker对应的下一个start event push进time event。 update result

每个 event push pop 各一次
heap size ， volumn heap 和time heap 最多为2 （2个speaker） 

复杂度O(n)
--
