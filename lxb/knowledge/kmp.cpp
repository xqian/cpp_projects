//Method from algorithm 4th, princiton univ.
#include <iostream>
using namespace std;

class KMP{
public:
     KMP(const string pat){
         pattern = pat;
         M = pattern.size();
         
         dfa.resize(R);
         for (auto unit:dfa){
             unit.resize(M);
         }
         
         buildDFA();
     }

    int search(const string text){
        int N = text.size();
        
        for (int i=0,j=0;i<N && j<M ;++i){
            j = dfa[text[i]][j];
        }
        
        if (j==M) return i-M;
        else return N;  //not found
    }
     
    static const int R;
     
private:
     string pattern;
     int M;
     vector<vector<int> > dfa;  //means in state j (location [0..pattern.size()-1], get one input, what's next state
     
     void buildDFA(){
         dfa[pattern[0]][0] = 1; // for state 0, if we get char pattern[0], move to state 1.
         for (int X=0, j=1; j<pattern.size(); ++j){
             //compute dfa[][j] -->copy all
             for (int c=0; c<R; ++c)
             {
                 dfa[c][j] = dfa[c][X];
             }
             
             // match case
             dfa[pattern[j]][j] = j+1;
             
             //simulate dfa
             X=dfa[pattern[j]][X];
        }
    }
}
    
const int KMP::R = 256;

void main()
{
	string needle = 'pattern';
	text = 'string to find a pattern here';
        KMP kmp(needle);
        return kmp.search(text);
    }
}
