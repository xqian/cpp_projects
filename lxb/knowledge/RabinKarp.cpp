class RabinKarp{
public:
  RabinKarp(const string pat){
    M = pat.size();
    Q = longRandomPrime();  //997. big prime.
    RM = 1;
    // compute R^(M-1).
    for (int i=1; i<M; ++i){
	RM = (R * RM) % Q;
    }

    patHash = hash(pat,M);
  }

  bool check(int i) { return true;}
  
  int search(string text){
    int N = text.size();

    //compute first hash
    long txtHash = hash(text, M);
    if (patHash == txtHash) return 0;

    for (int i=M; i<N; ++i){
	txtHash = (txtHash + Q -RM * text[i-M] % Q) % Q;
	txtHash = (txtHash * R + text[i] ) % Q;

	if (pathHash == txtHash) {
	  if (check(i-M+1)) return i-M+1; //match
	}
    }

    return N; //no match found.
  }


  long longRandomPrime(){
    return 997;	
  }

private:
  string pattern;
  int M; //pattern size.
  long Q;  //prime value for modulization. hashcode.
  int R=256; //Radix R
  long RM;  // to store R^(M-1) for shift hash computation.

  //Horner's method : avoid overflow, modularization.
  long hash(string key, int M){
	long h=0;
	for (int j=0; j<M; ++j)
	  h = (R * h + key[j]) % Q;

	return h;
  }
}
