http://oj.leetcode.com/problems/max-points-on-a-line/
/*
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

Try 1:
Issue: what's the comparation function should overloaded for the hashFunction/map??

Submission Result: Wrong Answer

Input:	[(0,0),(-1,-1),(2,2)]
Output:	1
Expected:	3


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    struct Line{
        double k;
        double b;
        bool vLine;
        Line(double _k, double _b, bool _vLine):k(_k), b(_b), vLine(_vLine){};
    };
    
public:
    struct lineComp{
        bool operator()(const Line &line1, const Line &line2){
            double eplison = 0.000001;
            if (line1.vLine && line2.vLine){
                return fabs(line1.b-line2.b) < eplison;
            }else if (line1.vLine || line2.vLine){
                return 1;
            }else
                return (fabs(line1.k - line2.k) < eplison ) && (fabs(line1.b - line2.b) < eplison) ;
        }
        
    };
    
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int N = points.size();
        if (N<=2) return N;
        
        map<Line,int,lineComp> hashTable;
        
        for (int i=0; i < N-1; i++)
        for (int j=i+1; j < N; j++)
        {
            Line line = computeLine(points[i],points[j]);
            
            //add into hash table
            if (hashTable.find(line) != hashTable.end()){
                hashTable[line]++;
            }else{
                hashTable[line] = 1;
            }
        }
        
        //find max from hash
        int maxNum = 0;
        for (auto it = hashTable.begin(); it!=hashTable.end(); it++) {
            if (maxNum < it->second) maxNum = it->second;
        }
        
        return maxNum;
    }
    
private:
    Line computeLine(Point &P1, Point &P2)
    {
        double k, b;
        bool vLine = false;
        
        if (P2.x == P1.x){
            vLine = true;  
            b = P1.x;
        }else{
            k = (P2.y - P1.y)/(P2.x - P1.x);
            b = (P1.y + P2.y - k*(P1.x + P2.x))/2;
        } 
        
        return Line(k,b,vLine);
    }
};


(2) Try 2: Following EIP method P296.
    Notes: 1. you need define hash function for customized class/struct.
	   eg: struct hashPoint{ bool operator()(const Point &l) const { return hash<int>()(l.x) ^ hash<int>()(l.y); }

	   2. You also need define '==' for key when using hash.

    leetcode complained "Line 121: no matching function for call to 'Solution::maxPoints(std::vector<Point>&)'".
	  
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    struct Point{
        int x;
        int y;
        Point():x(0),y(0){};
        Point(int a, int b): x(a), y(b){};
        
        bool operator==(const Point &p) const{
            return x == p.x && y== p.y;
        }
    };
    
    struct rational{
        int a;
        int b;
        
        rational(int _a, int _b):a(_a),b(_b){};
        
        bool operator==(const rational &that){
            return (a == that.a && b == that.b);
        }
    };
    
    struct Line{
        rational k;
        rational b;
        
        Line(rational _k, rational _b):k(_k), b(_b){};
        
        bool operator==(const Line &that){
            return (k == that.k && b == that.b);
        }
    };
    
    //hash function for Line
    struct hashLine{
        size_t operator()(const Line &l) const{
            return hash<int>()(l.k.a) ^ hash<int>()(l.k.b) ^ hash<int>()(l.b.a) ^ hash<int>()(l.b.b);
        }
    };
    
    struct HashPoint{
        size_t operator()(const Point &p) const{
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }
    };

public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int N = points.size();
        if (N<=2) return N;
        
        unordered_map<Line,unordered_set<Point, HashPoint>, hashLine> hashTable;
        
        for (int i=0; i < N-1; i++)
        for (int j=i+1; j < N; j++)
        {
            Line line = computeLine(points[i],points[j]);
            
            //add into hash table
            hashTable[line].insert(points[i]);
            hashTable[line].insert(points[j]);
        }
        
        //find max from hash
        int maxNum = 0;
        for (auto it = hashTable.begin(); it!=hashTable.end(); it++) {
            if (maxNum < it->second.size()) maxNum = it->second.size();
        }
        
        return maxNum;
    }
    
private:
    int gcd(int a, int b)
    {
        if (a < b) return gcd(b, a);
        if (b == 0) return a;
        return gcd(b, a-b);
    }

    rational getNormalized(int a, int b)
    {
        int commonGCD = gcd(abs(a), abs(b));
        a /= commonGCD;
        b /= commonGCD;
        
        return rational(a,b);
    }

    Line computeLine(Point &P1, Point &P2)
    {
        rational k = P2.x == P1.x ? rational(1,0): getNormalized(P2.y-P1.y, P2.x-P1.x);
        rational b = P2.x == P1.x ? rational(P2.x, 1) : getNormalized(P2.x * P1.y - P1.x * P2.y, P2.x - P1.x);
        
        return Line(k,b);
    }
};
