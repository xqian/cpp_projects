Small Tips for Code Interview:
random, generate per bit.
STL Vector implementation: maintain start, current, end pointer. int a[] => vector<int> A(a, a + sizeof(a)/sizeof(a[0])
deque: maintain two group of list?
INT_MAX, DBL_MAX numeric_limits<double>::max()
infix expression evaluation. 2 stack, one for operator, one for operatnum.


LeetCode:
DP
triangle mini path sum. dp[i][j]: from a[i][j to last level, the mini path. dp[i][j] = min(dp[i+1][j] , dp[i+1][j+1]) + f[i][j].
unique binary tree II: dp + shift trick. or dfs (dfs(start,end)  if start > end res.push(NULL)  http://oj.leetcode.com/submissions/detail/1619958/
decode number way: dp[i]: i..n-1, the decode number way.   dp[i] = dp[i+1] + (s[i]==‘1’ ||s[i]==‘2’ &&s[i+1] <‘7’) ? dp[i+2] : 0  ; handle s[i] == ‘0’ case.
wild match: (* match 0 or more . different from regular expression(a*). scan string and pattern iteratively. for ‘*’, remember the first char after * pattern, when mismatch, retreat to that place. don’t mix *p++=‘*!!
regular expression: recursive way. for *(p+1)==‘*’, while (*s==*p||*p==‘.’) {if isMatch(s,p+2) return true; else s++} return isMatch(s,p+2);
canJump: while (start<end && end <n-1) { end = max(end, start + A[start]); ++start} return end >=n-1
followup, minimum jump step: greedy, choose one which jump most far set and next step start from that.  
word break: dp[i] : i..N-1, whether it’s breakable. for j in [i..N-1], if (i..j) is word and dp[j+1] is breakable. solution dp[0]. init dp[N] = true;
word breakII, full solution: dfs, signature dfs(str, index, path, result,dict) base index==str.size(), extension: for (int i=index;i<s.size();++i) { if [i..j] is word, dfs(str, i+1, path + word’s..j’, result, dict).
longest valid parenthsis. dp[i]: i..n-1, s[i] included, the max num valid ‘(‘,')’. dp[i] = { if s[i] == ‘(‘ , j=i+1 + dp[i+1], s[j]=‘)’, then dp[i] = 2 + dp[i+1] + dp[j+1]  if j+1<=N). resolution max(dp[j]). j is 0..n-1. 

recursive or depth search:
phone number word: map<char, vector<char> > mapTable; dfs(str,index,path,result,mapTable).  extension: for (auto ch: map[str[index]]) dfs(str,index+1,path+ch’.. 
sudoSolver: dfs, find ‘’.’, then put every choice (1-9) to it, check whether it’s valid. If it is , dfs further (to find other ‘.’). For isValid(row,col,board), check row, col, and the small 3x3 (3*r/3,3*r/3+3..)
NQueen: put queen from row 1 to row n. for that row, we can put to 1..9 col. So we just put it and validate whether it’s invalid. If it’s valid, go further dfs(row+1, A) . base: row == A.size(), validation check: A[r] = ‘Q’ means I put r col one ‘Q’. any conflict with other row (same col)? so col is 0..r. abs(r-i) ? == ? abs(A[r] - A[i]).
Word search: dfs, extension: upper, down,left,right , dfs(str, index, board, row,col,visited); validation check: row,col boundary check, visited[r][c], str[index] ==?board[row][col]?).
RestoreIPaddress: eg: 2552551223, [255.255.12.23, 255.255.122.3,255.255.1.223,255.25.51.223…]   dfs, expect 4 part, extension: as long as num<255, length cut: range (4-part, (4-part)*3) vs the left str size. use string to pass parameter instead of reference for intermediate result will simplify the code logic. handle 0 as special case, only one leading 0 allowed for one part.
binary gray code: enumerate(int k){ if (k==n){..}  ; enumerator(k+1), flip(s[i]), enumerate(k+1)
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
Permutation & Combination:
’123’ permuation: depth search, dfs(str, index, result)   base: index==str.size(), extension. for (int i=index;i<str.size();++i){swap[str[index],str[i]),dfs(str,index+1,result). 
Followup: remove duplicate. 
set<char> to avoid duplicate.
sort and compare adjacent element. (?? used array?)
getKthPermutation(int n): condor encoding, (n-1)! res[n-1] = s[k/(n-1)!], k = k%(n-1)!; critical  res.push_back(s.erase(s.begin() k/(n-1)!)). then update (n-1)! -> (n-2)!,
STL: next_permutation(num.begin(), num.end())  if not false, get it this way.  
Random review:
bit string add. rbegin() ,rend() v.insert(v.begin(),12) to avoid reverse.    c++ alto. reverse(vector1.begin(), vector1.end())
check whether balanced binary  tree: post order travel, bottom up, return two value (balanced? height)
Morris travel: O(1), prev is temp variable to help establish thread tree (right child->root). diff first time and second time. after left done, move to right child directly. Modify node. Multiple thread may have issue.
max sum along binary tree. ( maxTreePathSum(TreeNode *, int &csum, int &maxSum) . scum means the longest path include root.  For csum, compare (left child->csum, right child csum, root->value,) for max, compare one more (left+right+root, maxsum).
kmean, faculty location problem, manhattan distance.

Tree:
LCA: 
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
Find closest value in BST: 1. with parent pointer?binary search idea but not very impressive.
Node * findClosest(Node *r, int val){ if (!r return NULL; if (r->val==val) return r; if (r->val >val) {if !r->left return r; node *p = findClosest(r->left,val); if abs(p->val-val).. return p else return r; … similarly to right case). o(log N) or O(h) h is the height. 
Followup. Find k closest value for given target. Idea: recursive in order . put first smallest k into deque. Then compare smallest one with current value to decide to put into queue or pop the smallest one (pop_front()).
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

Random Number:
Three Methods
choose n from N. t: handled record number, always ++t. m:chosen number so far. while(m<n) , decide whether choose that element. generate random *(N-t) ->k, if k>(n-m), not choose.
reservor sample: unknown size. choose m first. t=m+1. generate random [0..t)=M, if M<m choose this one and swap(t,M).  ++t. the vector save all  the candidate index.
shuffling random: for t=v.size()-1 to 0, generate random number v.size()-t = M, swap(M,—t)     
Given an vector (size unknown), generate random n node list. reserval sample. 
CopyList with random pointer.
O(1) space. first copy and create next node; secondly copy random pointer; third recover.
O(n) space. Have a map table map[ori]=clone. recursively (or depth) clone next/random node. only clone if it’s not in mapping table.
