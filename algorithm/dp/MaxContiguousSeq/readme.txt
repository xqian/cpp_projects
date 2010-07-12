- memo
    This program is do pratics dynamic programming;
    It is to use DP method to find the continuous sequence in a string that have the max sum;
    This problem is from MS book beauty of programing;
    I have programmed a recursive version and a non-recursive version;
    
- Notes
    Recursive programming is best for every layer have some brunches; if no brunch, recursive programming can be easily translated to non-recursive method.
    
- to run it;
$ ./maxConSeq.exe <in 2>debug.out
Case #1: 5
Case #2: 4
Case #3: 2
Case #4: -1
Case #5: 4
Case #6: 11
Case #7: 8
Case #8: 9
Case #9: -2
Case #10: 8

or 
$ ./maxConSeq.exe <in
case_count:10
case:0=======================
readed N:2
 4 1
endP:0, n[i]:4, c_max:4, h_max:4
endP:1, n[i]:1, c_max:5, h_max:5
Case #1: 5
case:1=======================
readed N:2
 4 -2
endP:0, n[i]:4, c_max:4, h_max:4
endP:1, n[i]:-2, c_max:4, h_max:2
Case #2: 4
case:2=======================
readed N:2
 -1 2
endP:0, n[i]:-1, c_max:-1, h_max:-1
endP:1, n[i]:2, c_max:2, h_max:2
Case #3: 2
case:3=======================
readed N:2
 -1 -2
endP:0, n[i]:-1, c_max:-1, h_max:-1
endP:1, n[i]:-2, c_max:-1, h_max:-1
Case #4: -1
case:4=======================
readed N:2
 4 -2
endP:0, n[i]:4, c_max:4, h_max:4
endP:1, n[i]:-2, c_max:4, h_max:2
Case #5: 4
case:5=======================
readed N:6
 2 4 -1 2 -2 6
endP:0, n[i]:2, c_max:2, h_max:2
endP:1, n[i]:4, c_max:6, h_max:6
endP:2, n[i]:-1, c_max:6, h_max:5
endP:3, n[i]:2, c_max:7, h_max:7
endP:4, n[i]:-2, c_max:7, h_max:5
endP:5, n[i]:6, c_max:11, h_max:11
Case #6: 11
case:6=======================
readed N:6
 1 -2 3 5 -3 2
endP:0, n[i]:1, c_max:1, h_max:1
endP:1, n[i]:-2, c_max:1, h_max:-1
endP:2, n[i]:3, c_max:3, h_max:3
endP:3, n[i]:5, c_max:8, h_max:8
endP:4, n[i]:-3, c_max:8, h_max:5
endP:5, n[i]:2, c_max:8, h_max:7
Case #7: 8
case:7=======================
readed N:6
 0 -2 3 5 -1 2
endP:0, n[i]:0, c_max:0, h_max:0
endP:1, n[i]:-2, c_max:0, h_max:-2
endP:2, n[i]:3, c_max:3, h_max:3
endP:3, n[i]:5, c_max:8, h_max:8
endP:4, n[i]:-1, c_max:8, h_max:7
endP:5, n[i]:2, c_max:9, h_max:9
Case #8: 9
case:8=======================
readed N:5
 -9 -2 -3 -5 -3
endP:0, n[i]:-9, c_max:-9, h_max:-9
endP:1, n[i]:-2, c_max:-2, h_max:-2
endP:2, n[i]:-3, c_max:-2, h_max:-2
endP:3, n[i]:-5, c_max:-2, h_max:-2
endP:4, n[i]:-3, c_max:-2, h_max:-2
Case #9: -2
case:9=======================
readed N:6
 1 2 -1 1 2 3
endP:0, n[i]:1, c_max:1, h_max:1
endP:1, n[i]:2, c_max:3, h_max:3
endP:2, n[i]:-1, c_max:3, h_max:2
endP:3, n[i]:1, c_max:3, h_max:3
endP:4, n[i]:2, c_max:5, h_max:5
endP:5, n[i]:3, c_max:8, h_max:8
Case #10: 8






















