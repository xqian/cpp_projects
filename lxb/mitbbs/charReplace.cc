Src:  http://www.mitbbs.com/article_t/JobHunting/32580237.html

Question:
a替换成b，或者b替换成a，算1次，

给出一个string，比如aaabababbba

问最少替换几次能变成左边都是a，右边都是b的那种？

举个例子，

aba，替换1次，变成aaa
bba，替换一次，变成bbb
aaba，替换1次，变成aabb



有递推关系的不是直接的min值，而是i左右的b字符和a字符个数，所以好像没有办法针
对min值做dp。还是直接scan比较直观。
  int minChange(String s) {
    int[] countABackword = new int[s.length() + 1];
    countABackword[s.length()] = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      char c = s.charAt(i);
      countABackword[i] = c == 'a' ? countABackword[i + 1] + 1
          : countABackword[i + 1];
    }

    int countBForward = 0;
    int min = countABackword[0]; // case: all b
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (c == 'b') {
        countBForward++;
      }
      int curr = countBForward + countABackword[i + 1];
      if (curr < min)
        min = curr;
    }

    return min;
  }
