class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(path.length() == 0) return path;
        int i = 1;
        int curPos = 1; //the place to insert, after /
        while( i < path.length()) {
            int j = path.find_first_of('/', i);
            if ( j == string::npos) j = path.length();
            if ( j != i) {
                if ( j - i == 2 && path[i] == '.' && path[i+1] == '.') {
                    if (curPos >= 2) { //BUG this condition with the one above, cause problem in else
                        curPos = path.find_last_of('/', curPos -2 );
                        curPos++;
                    }
                }
                else if ( j -i != 1 || path[i] != '.') {
                    for(int k = i; k < j; ++k) {
                        path[curPos++] = path[k];
                    }
                    if ( j != path.length()) {
                        path[curPos++] = '/';
                    }
                }
            }
            i = j+1;
        }
        if ( curPos == 1) {
            return path.substr(0,1);  //BUG: usage of substr  
        }   
        else if (path[curPos-1] != '/'){
            return path.substr(0,curPos);
        }
        else {
            return path.substr(0,curPos-1);
        }
    }
};