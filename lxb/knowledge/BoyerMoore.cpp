enum { R = 256 };

//Idea: match pattern from right side to left side and skip when mismatch. Never backup. N/M normal case.
class BoyerMoore{
public:
  BoyerMoore(string pat){
	pattern = pat;
	int M = pat.size();
	right.resize(R, -1);  //-1 means not in current pattern.
	for (int j=0; j<R; ++j){
	  right[pattern[j]] = j;
	}
  }

  int search(string text){
    //search for pattern in text
    int M=pattern.size();
    int N=text.size();

    int skip;
    for (int i=0;i<N - M; i+=skip){
    	skip = 0;
	for (int j=M-1; j>=0; --j){
	   if (pattern[j] != text[i+j]){
		//mismatch
		skip=max(1, j-right[text[i+j]]);
		break;
	   }
        }

	if (skip==0) return i;
    }
	
    return N;  //not found.
  }
}
