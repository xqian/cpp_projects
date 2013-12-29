Small Tips for Code Interview:
random, generate per bit.
STL Vector implementation: maintain start, current, end pointer. int a[] => vector<int> A(a, a + sizeof(a)/sizeof(a[0])
deque: maintain two group of list?
INT_MAX, DBL_MAX numeric_limits<double>::max()
infix expression evaluation. 2 stack, one for operator, one for operatnum.

*Random Alg.
Selection sample: choose m out of n size. 
generate U = [0,1)
t: handled element, k:chosen element.  if (n-t)*U  in [k,m), then choose it, otherwise, ++t, continue;
Reseval alg. choose m out of unknown stream
choose first m into array (vector with size m). 
t: handled element. if k=U * t < m, a[k] = t;   
vector is storing the index in the stream. Need get the real value when done.
random shuffle
for (int t=n-1;t>=0;—t)  swap (U*t, t);

Thread, synchronization
A livelock is similar to a deadlock, except that the state of the two processes involved in the livelock constantly changes with regards to the other process.  As a real world example, livelock occurs when two people meet in a narrow corridor, and each tries to be polite by moving aside to let the other pass, but they end up swaying from side to side without making any progress because they always both move the same way at the same time. A deadlock results in an infinite wait whereas a livelock results in wasting CPU cycles.
LeetCode:
DP
triangle mini path sum. dp[i][j]: from a[i][j to last level, the mini path. dp[i][j] = min(dp[i+1][j] , dp[i+1][j+1]) + f[i][j].
unique binary tree:
Find the number: dp[i]: total number 1..i;  dp[i] =  dp[j] * dp[i-j-1] for j in [0..i). return dp[n]  //base dp[0]=dp[1] = 1. root in i, and split left part into left/right child. left child number j can be [0..i-1].
dfs (dfs(start,end)  if start > end res.push(NULL) //extension: for (int i=start;i<=end;++i) { left = dfs(start, i-1); right = (i+1,end);  for (int k=0;k<left.size();) for (int m=0;m<right.size();++m){root = new Node(i); root->left = left[k] , ...}
decode number way: dp[i]: i..n-1, the decode number way.   dp[i] = dp[i+1] + (s[i]==‘1’ ||s[i]==‘2’ &&s[i+1] <‘7’) ? dp[i+2] : 0  ; handle s[i] == ‘0’ case.
wild match: (* match 0 or more . different from regular expression(a*). scan string and pattern iteratively. for ‘*’, remember the first char after * pattern, when mismatch, retreat to that place. don’t mix *p++=‘*!!
regular expression: recursive way. for *(p+1)==‘*’, while (*s==*p||*p==‘.’) {if isMatch(s,p+2) return true; else s++} return isMatch(s,p+2);
canJump: while (start<end && end <n-1) { end = max(end, start + A[start]); ++start} return end >=n-1
followup, minimum jump step: greedy, choose one which jump most far set and next step start from that.  
word break: dp[i] : i..N-1, whether it’s breakable. for j in [i..N-1], if (i..j) is word and dp[j+1] is breakable. solution dp[0]. init dp[N] = true;
word breakII, full solution: dfs, signature dfs(str, index, path, result,dict) base index==str.size(), extension: for (int i=index;i<s.size();++i) { if [i..j] is word, dfs(str, i+1, path + word’s..j’, result, dict).
longest valid parenthsis. dp[i]: i..n-1, s[i] included, the max num valid ‘(‘,')’. dp[i] = { if s[i] == ‘(‘ , j=i+1 + dp[i+1], s[j]=‘)’, then dp[i] = 2 + dp[i+1] + dp[j+1]  if j+1<=N). resolution max(dp[j]). j is 0..n-1. 
palindrome partition: get all result. dfs. position[] to save the cut index. dfs(str,index, position, result). recover from position index. base:str.size()==index; expend: for i=index;i<str.size();{if (isPalin[index+1,i-1) { position.push_back(i); dfs(i+1,…);position.pop_back();
palindrome minimum cut/partition, so that each word is also a palindrome. dp[i]: min cut from i..n-1. isPal[i,j]:i..j is a palin or not. dp[i] = min( for j=i+1..n, if isPal[i,j] && s[i]==s[j]: dp[i] = 1+ dp[j+1]) , set isPal[i][j] to true.
longest palindrom substr. 
O(1) space, O(n^2). for each position, do central expansion both left/right. If a[i]==a[i=1]expand 2 letter center.
Knapsack problem:  
0/1 without duplicate. choose or not chose. each item has weight and value. dp[i][w] means choose from first i term to get exactly weight w, the optimal value. the solution is the max(dp[i][w]). subproblem: dp[i][w]= max( not choose: dp[i-1][w], choose, dp[i-1][w-Wi] + vi;
 Integer knapsack problem. with duplicate. dp[i] means the maxValue with capacity(size) i. dp[i] = max(dp[i-1], dp[i-Cj] + Vj) for j from 1..n. O(nc)
Interval Problems:
Given interval list, find out the largest number of task to finish without conflict. (one resource). Sort by ending time, then go through as greedy, find one, exclude all other start time < end time. Then move on.
Given Interval list, find the most overlap (e.g.: arrange classroom, what’s the maximum classroom needed). Sort by start time and convert to EndPoint (isStart, interval *). Sweep endpoint, if start_point, add into count, record max(count). If end_time, count—.
dp: weighted interval problem. choose interval, without overlap, but the sum of weigh is largest. dp[i]: means first [1..i] interval, the optimization  value. For i, choose it or not choose it. dp[i] = max(dp[p[i]]+Vi, dp[i-1]). p[I]: means the most right index which didn’t have conflict with i.
So build p[i] first. Just sort by started, then scan back to find i-1..0, find first end point less than start_point_i.
dp.
recursive or depth search:
phone number word: map<char, vector<char> > mapTable; dfs(str,index,path,result,mapTable).  extension: for (auto ch: map[str[index]]) dfs(str,index+1,path+ch’.. 
sudoSolver: dfs, find ‘’.’, then put every choice (1-9) to it, check whether it’s valid. If it is , dfs further (to find other ‘.’). For isValid(row,col,board), check row, col, and the small 3x3 (3*r/3,3*r/3+3..)
NQueen: 
depth search. depth: row. //base: row ==n ; //extend: for each row, we can put (0..n) to that location. a[row] = i; check validation.
put queen from row 1 to row n. So no conflict in row. Consider one dimension for col. for that row, we can put to 1..9 col. So we just put it and validate whether it’s invalid. If it’s valid, go further dfs(row+1, A) . base: row == A.size(), validation check: A[c] = ‘Q’ means I put c col one ‘Q’. any conflict with other row (same col)? so col is 0..r. abs(r-i) ? == ? abs(A[r] - A[i]).
Word search: dfs, extension: upper, down,left,right , dfs(str, index, board, row,col,visited); validation check: row,col boundary check, visited[r][c], str[index] ==?board[row][col]?).
RestoreIPaddress: eg: 2552551223, [255.255.12.23, 255.255.122.3,255.255.1.223,255.25.51.223…]   dfs, expect 4 part, extension: as long as num<255, length cut: range (4-part, (4-part)*3) vs the left str size. use string to pass parameter instead of reference for intermediate result will simplify the code logic. handle 0 as special case, only one leading 0 allowed for one part.
binary gray code: 
1<<n; for i in [1..1<<n]:  i^(i-1)
enumerate(int k){ if (k==n){..}  ; enumerator(k+1), flip(s[i]), enumerate(k+1)
void generateGrayCode(vector<string>& ret,

      string& s, int i, int n){

      if(i==n){

            ret.push_back(s);

      }else{

            generateGrayCode(ret,s,i+1,n);

            if(s[i]=='0') s[i]='1';

            else s[i]='0';

            generateGrayCode(ret,s,i+1,n);

      }

}
Graph:
topological sort. dfs. stack. struct GNode{ vector<GNode *> edges; bool visited; int maxDist). vector<GNode *> G;  dfs(GNode * &v, stack<GNode *> &s)
word ladder: change one letter each time, it can any position (means dfs or depth search didn’t work). bfs, neighbor( for (auto ch : str) { for c=‘a’;c<=‘z’;++c){  replace ch to c; if it’s a word, then add into queue, mark visited. remember to recover. level ; record levelSize for each level’s size, pop/finish all that level before move to next level.
Digstra alg. Find shortest path from source (s) to target(t) in weighted graph. 
Node{ int dist = INT_MAX; vector<pair<Node *, weight>> edges}
Use minHeap(STL set for better delete performance). Init s.dist = 0; set<Node *,comp> ; struct comp{bool operation()(…}
while (!set.empty()){ curr=set.cbegin(); //relax all curr neighbor = curr->neighbor[i].first; cure->neighbor[i].second + curr->d < neighbor.d, ….// set.erase(set.begin());  if cure == t, done.  
Permutation & Combination:
’123’ permuation: depth search, dfs(str, index, result)   base: index==str.size(), extension. for (int i=index;i<str.size();++i){swap[str[index],str[i]),dfs(str,index+1,result). 
Followup: remove duplicate. 
* set<char> to avoid duplicate.
getKthPermutation(int n): condor encoding, (n-1)! res[n-1] = s[k/(n-1)!], k = k%(n-1)!; critical  res.push_back(s.erase(s.begin() k/(n-1)!)). then update (n-1)! -> (n-2)!,
STL: next_permutation(num.begin(), num.end())  if not false, get it this way.  

Random review:
bit string add. rbegin() ,rend() v.insert(v.begin(),12) to avoid reverse.    c++ alto. reverse(vector1.begin(), vector1.end())
check whether balanced binary  tree: post order travel, bottom up, return two value (balanced? height)
Morris travel: O(1), prev is temp variable to help establish thread tree (right child->root). diff first time and second time. after left done, move to right child directly. Modify node. Multiple thread may have issue.
max sum along binary tree or tree diameter. ( maxTreePathSum(TreeNode *, int &csum, int &maxSum) . csum means the longest path include root.  For csum, compare (left child->csum, right child csum, root->value,) for max, compare one more (left+right+root, maxsum).
kmean, faculty location problem, manhattan distance.

Tree:
*LCA: 
binary tree. LCA(r,a,b). if (!r) return NULL; if (r==a||r==b) return r; L=LCA(r->left,a,b) R=LCA(r->right,a,b) if L&R return r; return L?L:R.
binary tree with parent pointer: link list merge. No duplicate.
two pointer. fast,slow, get depth first.
unordered_set visited; interweave.
n-binary, find LCA. findPath(r,a,list_a) findPath(b,list_b); find last common node in two list. findPath(r,a,list_a) can use dfs. //base: find it or null; //ext: ListNode{list<ListNode *> children;int label} for (auto &v: a->children).
Open Question: find two node whose sum is given in bst. 
O(n). in order travel, then two pointers. 
two pointer point to least, largest and use the idea. stack to support. previous, next. (Haitaohe)  Too many code for interview.
find min depth in tree. end node in path should be leaf. 
int minDepth(r){if !r return 0; if (!r->left) return minDepth(r->right)+1; if (!r->right) return minDepth(r->left)+1; return (min(minDepth(r->left),minDepth(r->right))+1;
SymmetricTree(r): 
bool sym(l,r){ //special case !l && !r. !l||!lr, l->val == r->val, sym(l->left,r->right) && sym(l->right,…)
iterative. Use two queue, and BFS travel. pay attention to the push sequence.
* Find closest value in BST: 1. with parent pointer?binary search idea but not very impressive.
Node * findClosest(Node *r, int val){ if (!r return NULL; if (r->val==val) return r; if (r->val >val) {if !r->left return r; node *p = findClosest(r->left,val); if abs(p->val-val).. return p else return r; … similarly to right case). o(log N) or O(h) h is the height. 
*Followup. Find k closest value for given target. Idea: recursive in order . put first smallest k into deque. Then compare smallest one with current value to decide to put into queue or pop the smallest one (pop_front()).
findKthClosest(r, k, target, deque<node *> Q){  if (!r) return; findKthClose(r->left,k,target,Q); if Q.size()<k Q.push_back(r->val) else{ compare Q.pop_front(); Q.push_back(r->val); or ignore;; findKthClose(r->right…);
RecoverBST. two exchanged. 
O(n): vector<node*> inOrderSequence and find two from the mismatched elements by scanning it front/back two pointer.
O(1) extra space: inOrder recursive travel tree, find first and second mismatched node. (use prev node to track the first, second one is pref->next or cure).
inOrder(r,first,second,prev){ if !r return; inOrder(r->left…) if (prev && pref->val >r->value) {if !first first = pref; second=r;}  prev=r; in order(r->right).
Flatten binary tree to link list: idea. for r, put r-right to its previous (defined as it’s left child’s right most kid). then put it’s left child as right child, move to right child directly.
Rebuild tree from inOrder+pre/post order. recursive, compute subs tree len ,pass by start,end.
Binary Tree maximum path sum:
helper(r, csum,maxsum) csum: used to store max sum including root, but not cross left to right so that it can go upper with parent. but maxsum keep record global max.   Then postOrder travel to bottom up.
subtree(t1,t2): if t->val == t2->value && matchTree(t->left,t2->left)&& matchTree(t->r, t2->r) return true; return subtree(l->l,t2)||subtree(r->r,t2).  //base if !t2 return true; if !t1 return false;
serial/deserialize tree: use ‘# ‘ for NULL child.  Preorder.   
serial:  serial(r,ostream &os){if !r os<<‘# ‘; else {os << r->val; serial(r->left, os); serial(r->right,os);
deserial: deserial(istream, node *&r) : istream>>token; if (token != ‘#’){ r=new node(token); desrial(istream,root->left), desrial(stream,root->right);
BST -> double linklist. Recursive, convert(root, &pLastNode); inOrder travel. 1. convert(root->left,pLastNode) 2. connect pLastNode with root. if pLastNode { pLastnode->right = root; root->left = pLastNode} 3. update pLastNode to root. 4. recursively on right convert(root->right, pLastNode)   5. return result should be head. so go from pLastNode back to first one.
Various: cycle double link.  make first and last point each other.
Another method based on rotation. Complex.

LinkList
Remove duplicate and keep only one element in sorted list. Use set to decide duplicate (O(n) space, O(n) time). need pre pointer to do delete. Or write function to go through list (O(n^2) time, O(1) space). Another smart way, inspired from qsort, two pointer, p0 maintain the list which is final result. p1 move on till end. then remove the later part. 
Followup: remove all element which has duplicate. With set (O( n) space). You can also go through list by compare next element to check duplicate.
Merge two sorted lists: use dummy node, two pointer compare, the result (cur) will point to winner. keep move till end of one list. then append the other left part.
Follwup: k-way merge. Use one minHeap (priority_queue<node, vector<node>, comp>)  struct comp{ bool operator()(node &lhs,node &rhs){return ..lhs->val>rhs->val). Init: push into Q from each list. use dummy node to keep result. find the winner (top of heap), let tail point to it. then refill from exactly that list.
Reverse link list every k node. Use stack to do the reverse. use dummy to handle head/tail mess. find k node, do the reverse, move to next group. special handle to last group.
Rotate list every k node. trick: k should reset to k = k % lenOfList; then it becomes two pointer problem, find the pointer, reset the new head and next node. Remember to cut out immediately if k==0 as a result.
Partition List: Use two dummy node list. put less than value to lessList. Then connect lessList with moreList. Pay attention to the last element. Also pay attention to ==.
ReverseListBetweenMandN(l, M,N): find M and N. pref->next=M. next=N->next; then reverse(prev, N) by head insert. maintain pre as dummy head. Connect together then.
ListLoop: two pointer, fast, slow. pay attention to boundary. (fast && fast->next)   
isListPalindrom: find middle point, reverse one part, do apple to apple comparation.  Or middle, with stack.
GetIntersectOfTwoLists: 
Two stack, then pop up till find different. 
Two pointer, get list length, move one pointer len1-len2 first, then move two pointer to find intersect.
Union and intersect two list. Use set to judge whether it appeared. Choose one list, add the value into set. Go through 2nd list, if it’s in set, clone into intersect,otherwise put int map and put into union set.
CopyList with random pointer.
O(1) space. first copy and create next node; secondly copy random pointer; third recover.
O(n) space. Have a map table map[ori]=clone. recursively (or depth) clone next/random node. only clone if it’s not in mapping table.

Random Number:
Three Methods
choose n from N. t: handled record number, always ++t. m:chosen number so far. while(m<n) , decide whether choose that element. generate random *(N-t) ->k, if k>(n-m), not choose.
reservor sample: unknown size. choose m first. t=m+1. generate random [0..t)=M, if M<m choose this one and swap(t,M).  ++t. the vector save all  the candidate index.
shuffling random: for t=v.size()-1 to 0, generate random number v.size()-t = M, swap(M,—t)     

Binary Search:
Median of two sorted array: A,m, B,n, odd,even  (m+n)/2, (m+n)/2 +1 ,generally, kth.   Pa = min(m, k/2), pb = k-pa. if m>n, swap call. Compare Pa-1 vs Pb-1. If Pa- > Pb-1, mean can’t be in 1..Pb. A,m, B+Pb, n-Pb, K-Pb.   base case: m=0==> return B[k-1]. k=1, return min(A[0],B[0]). if A[Pa-1] = B[Pb-1], return A[Pa-1].  
Divide two number. Sign. overflow when INT_MAX/(-1).  int ->long long , static convert. abs((long long)n). algorithm, div <<1  < divisor ===> count<<=1, div<<=1; until divisor < div.
Search in a rotated sorted array: apply binary search to the part strictly sorted. A[low] < A[mid]:  low..mid is sorted. Otherwise, other part is sorted. if target is in sorted part ( target <= maxnum and target >=minum, move L/H towards that part, otherwise, move to reverse part.
Followup: if duplicate exist. Special handling when A[L] = A[mid]:  L++ only.
Binary Search: lower boundary, duplicate handle. If ‘==‘, for lower boundary, we can only move H to mid, since it maybe the first one. Merge case together A[mid] >=target  => R=mid. Also notice while L<R , mid = L + (R-L)/2.  Vice verse. two elements to avoid for-ever loop. mid = l + (h-l+1)/2;  [l+(h-l)/2, l+(h-l+1)/2]  lower boundary or higher boundary.  while L<=H.  
Variance: Search for a range in sorted array: search for lower boundary + upper boundary (log(n)*2), then return.
Finding missing number in [1..n] . Binary search + adjacent number check.
Power(x,n): sign  handle, even/odd, base: n=0, return 1; n=1, return x;
sqrt(int r): special case. r<0, invalid. r=0, return 0; r=1,return 1; L=1; R=r; mid; if mid > r/mid =>R=mid-1; else L=mid;  return A[L]
sqrt(double r): range 0..1, 1.. n. For 0..1, the n^n < n, L=r, R=1; For 1..n, L=1, R=r;   eplison to compare (R-L)> eplison. mid = L+(R-L)/2; if mid*mid < r =>L=mid; otherwise, R=mid;  return A[L].
Find local min in NxN matrix. find middle row, the lowest one, start from there and recursively do it until find one.

Two Pointers:
Remove duplicated from sorted array. Use idea of quick look partition: Two pointers, one kept tracking of the non duplicate one and copy it.  i=0;j=0; while (j<n){ if (a[i]!=a[j]){a[i++]==a[j]}; j++};
Longest substring without repeating characters:  abcadbcac  —> adbc   two pointer i ,j . Use one bool[] to check duplicate. move j until find dup. get a unique string, compare longest. Then move i till it get the dup A[j] . at the same time, maintain the bool table (remove from it). Next move i and j to do the same thing. until j come to end. do last time.  
Container with most water. find two line, so that the rectange(water) is maximum. Two pointer i=0, j=end-1; compute area = min(a[i][,a[j]) * (j-i), then move i or j based on (a[i][ > a[j]). 
Another water problem: trapping water container. Find the maximum and divide into two part. compute each part .   min (largest_so_far, current) *  (largest-current). maintain largest_so_far. do similar for right part, but start from end.
2sum: i=0,j=n-1; if a[i]+a[j] > sum j—j; else ++i. while i<j.
3sum: for i in [0,n-2]: do 2sum
4sum; for i in [0..n-3], j in[n-1..i], do 2 sum;
Merge two sorted array without additional memory. Two pointer i = n-1; j=m-1; Target point k=n+m-1  a[k—] = a[i]>a[j]?a[i—]:a[j—]. Then handle the shorter array.
Merge k sorted lists. priority queue, rewrite struct for compare function (bool operator()(const …); heapNode{index, node}, then pop one, put into list (dummy node), refill one.
STL, multipleset, just add all into it, then enumerate. rewrite compare function.
strStr: bruce force, text, pattern, i and j point to them. for i (0..n-j-1), compare i..i+j-1 with pattern[0,n] apple by apple. If not match, i++, reset j. 
kmp: dfa state machine. review the idea.
bourn ..; compare from last character, possible n/m. If mismatch, how to move?
roundHash: Horner’s algorithm on modular. 1234->2345   1234 - 1*10^3 + 5  mod 931.
bloom filter. multiple hash function
substring with concatenation of all words. diff from strstr, words sequence not important. map<string,int> need, found. Pointer i, move from 0.. n-sizeof(pattern), it make sure to find all solution. Then for each len(pattern), we do the check whether it’s valid.  Have a separate function to help simplify logic.
isPalindrome, ignore space. Find first non space character i and j, do the comparation. while (i<j){ if isSpace(i) {i++,continue;}  if is space(j){—j;continue}. if a[i]!=a[j] return false; ++i,—j;}  Use just one loop with continue to simplify code logic.
Min window substring. two pointer i,j. use need/found to record the appearance time. Use totalNeed to count the total number needed. Maintain totalNeeded. if found[i] < needed[i], count it. otherwise, just found[i]++. when find one solution, move pointer i until found[i]<need[i]. O(n). Maintain the mapper, counter and pointer properly.
sort color: quick sort partition idea. [0..i] included: red, [i..j):b [j..k]:not checked yet. [k..n]: green. while (j<k) {case[a[j]): ‘r’  swap(++i, j++), ; ‘b’: j++  ‘g’: swap(j,—k)}
*Balance parenthesis: eg: (a(()fd)))  two pointer, first=0; last = end; move first pointer, if ‘(‘, first last pointer till find one ‘)’.; then put ‘(‘ into result and counter_’(‘++;  others if it is ‘)’: check if counter_’c’>0: put into result; otherwise, ignore it and move on.    

Others:
sliding windows max value, windows size k.
deque:  only store valuable node. for i in [0,k-1], if value[Q.top()] < value[i], pop(); then push_back(i);  Then check Q.front(), popup all invalid index(outside of window), then get one Q.front() each time. O(n). http://leetcode.com/2011/01/sliding-window-maximum.html
priority queue, or heap. push k node into priority queue first. QueueNode { index,value},, pop out till we found one valid index (in that window). O(nlogn)
Validate parenthese: stack, put ‘(‘ ‘{‘ onto stack. when meet ‘)’, popup . error if stack is empty.   After done, error if not empty. :-) Simplifer code with table map[‘}’]=‘[‘.  special case “”, null.
isNumber: dfa machine: define input type (enum INPUTTYPE{…INVALID}, define state convert table state[state][INPUTTYPE]. if INVALID, then return false. after eating all input, check state is in final state set. also start state. simple, clean and effective.
setZero. define row[],col[]. go through each element, if it’s 0, set respective row/col to 0. Second round ,check if that row/col is 0. then set it. O(n*m)
anagram: sort by anagram, output the same group. use map<string, vector<string> > ; map[sorted(s)].push_back(s). then iterate the map.
method 2: supply one sort method and sort it. then go through one by one (by compare with sorted). Easy to mess up code.
Rotate image, clock wise 90.
cc150 method. for (circle=0; circle < n/2;++i) { for (point=circle;point<n-circle-1;++point) {move 4 points. t=(i,j)->(n-j-1,i)->(n-i-1,n-j-1)->(j,n-i-1)
Spiral Matrix: rowMin=0,rowMax=row-1,colMin=0,colMax=colMax-1; while true{//top colMin->colMax, rowMin…   ;rowMin++.  check rowMin < rowMax.}  boundary check.
Followup: generate a square matrix. two pointer, start=0, end=n-1, generate by circle. while start < end; //top, for (int i=start; i<end;++i) M[start][i] = num++;  //right j=start+1..
string multiply: a[m], b[n], result[m+n].  then simulate multiple for (int i=m-1;i>=0;—i)  for (int j=n-1; j>=0; —j) { int carrier = 0; result[i+j-1] += carrier + a[i]*a[j]; carrier = result[i+j+1]/10; result[i+j+1] %=10; }  result[i] += carrier;   then remove leading ‘0’ in string.
mergeInterval: sort by start point, then go through each one. call sub function to decide whether need merge res.back(), interval[i]. if not, just push_back, else, update res.back(). sort(a.begin(),a.end(), sorter())  struct sorter{ bool operator()(…).
InsertInterval.  // first skip/copy unoverlap one; then merge overlap one until last. skip/copy last part. interval.start = min(…), interval.end=max(..)   if a[i].start between intervals.start and interval.end.
Text justification: handle line by line, greedy choose maximum possible words. then compute space leftspaces=(L-words.size()). . evenly space  = leftspaces / (words-1), extra one more space for first leftspaces % words-1 word.  Handle last line specially (no extra space).  Corner case: one word in that line, left alignment and put all space append to that line. always put first word to res, then start from there.
romanToInt(): mapping table for roman M[‘I’] = 1, M[‘V’] = 5, then start from right, if M[a[i]]<M[a[i+1]] minus M[a[i]] else +M[a[i]].
IntToRoman  mapping table. two arrays. digital = [1000,900,500,400,100,90,50,40,10,9,5,4,1]  for symbol, remember: I(1), V(5) X(10),L(50),C(100)D(500)M(1000).  then easy to figure out IV(4), IX(9), XL(40),XC(90), CD(400), CM(900).  count = num / digital[i] , i start from 0 to digital.size()-1. put count sym[i] onto result.
ReverseInt: sign,(long long to save result) overflow(long long to compare with INT_MAX,INT_MIN):
Idea 1: convert int into a vector<int>, then do the computation.  
Smarter way. Just do it on the air. for x, x%10 is the last digit. r = r*10 + x%10, x/=10;
Rotate array by L. reverse whole(A,n) first, then reverse part (A,L) and part (A+L, n-L)
Heap
for each node, it’s the max node (maxHeap, compare <).  i=0..n-1.   left(p) = 2*p + 1, right(p) = 2*p+2.  parent(i) = (i-1)/2;
Heapify(extract root), topdown. choose max(l,r) to exchange O(h). 
Insert(element). bottom up whenever parent.value < it’s value;
Delete(i): similar to extract root. exchange last element with node i. since last element will be less than node i’s parent, we only need to maintain node i and it’s children. top-down heapify will get this done.
priority_queue<int, vector<int>,comp> PQ. PQ.push(), PQ.top(), PQ.pop() PQ.size(), PQ.empty()
#include <algorithm> 
make_heap(A.begin(),A.end(),comp); 
pop_heap(); This exchange first element with last one, and maintain A[0.n-2] is still heap. 
push_heap():  insert one element into heap and adjust as heap.   v.push_back(), push_heap(v.begin(),v.end())
sort_heap():  just sort
WordLadder: BFS, neighbor definition (for each location, from ‘a’ to ‘z’, if not visited, add into queue) till queue is empty.
Followup, find all solutions from it. BFS, need record the path. unordered_map<Node*, vector<Node *> from> father. Maintain it: when find a neighbor, put into map. when build, use depth search on father, with intermediate result on the path.
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';

  std::pop_heap (v.begin(),v.end()); v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); std::push_heap (v.begin(),v.end());
  std::cout << "max heap after push: " << v.front() << '\n';

  std::sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';

  return 0;
}


TODO:
1. Interval (algorithm design, EPI)
3. 
4. Find read/write lock (MS DB team interview). 
5. Read really c++ lock/mutex syntax.

