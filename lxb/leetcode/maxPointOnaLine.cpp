http://oj.leetcode.com/problems/max-points-on-a-line/
/*
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

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
