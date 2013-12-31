/*************************************************************************
 *  Compilation:  javac ArrayStackOfStrings.java
 *  Execution:    java ArrayStackOfStrings
 *  
 *  Stack of strings implementation with a fixed-size array.
 *
 *  % more tobe.txt 
 *  to be or not to - be - - that - - - is 
 * 
 *  % java ArrayStackOfStrings 5 < tobe.txt 
 *  to be not that or be
 *
 *************************************************************************/

import java.util.Iterator;

public class ArrayStackOfStrings implements Iterable<String> {
    private String[] a;  // holds the items
    private int N;       // number of items in stack

    public ArrayStackOfStrings(int max) {  a = new String[max];       }
    public boolean isEmpty()            {  return (N == 0);           }
    public void push(String item)       {  a[N++] = item;             }
    public String pop()                 {  return a[--N];             }
    public Iterator<String> iterator()  { return new ArrayIterator(); }


    public class ArrayIterator implements Iterator<String> {
        private int i = N-1;

        public boolean hasNext() { return i >= 0; }
        public String next()     { return a[i--]; }
        public void remove()      { throw new UnsupportedOperationException(); }
    }


    public static void main(String[] args) {
        int max = Integer.parseInt(args[0]);
        ArrayStackOfStrings stack = new ArrayStackOfStrings(max);
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (!item.equals("-")) stack.push(item); 
            else if (stack.isEmpty())  StdOut.println("BAD INPUT"); 
            else                       StdOut.print(stack.pop() + " ");
        }
        StdOut.println();

        // print what's left on the stack
        StdOut.print("Left on stack: ");
        for (String s : stack) {
            StdOut.print(s + " ");
        }
        StdOut.println();
    } 
} 
