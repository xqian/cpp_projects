public class AllStringFuctionExample {
public static void main(String[] args) {
String str = “All String function Example in java”;
// convert string into Lower case
String Lowercase = str.toLowerCase();
System.out.println(“Lower case String ==> ” + Lowercase);
// convert string into upper case
String Uppercase = str.toUpperCase();
System.out.println(“Upper case String ==> ” + Uppercase);
// Find length of the given string
System.out.println(“Length of the given string ==>” + str.length());
// Trim the given string i.e. remove all first and last the spaces from
// the string
String tempstr = “    String trimming example   “;
System.out.println(“String before trimming ==> ” + tempstr);
System.out.println(“String after trimming ==> ” + tempstr.trim());
// Find the character at the given index from the given string
System.out.println(“Character at the index 6 is ==> ” + str.charAt(6));
// find the substring between two index range
System.out.println(“String between index 3 to 9 is ==> ”
+ str.substring(3, 9));
// replace the character with another character
System.out.println(“String after replacement ==> ”
+ str.replace(‘a’, ‘Y’));
// replace the substring with another substring
System.out.println(“String after replacement ==> ”
+ str.replace(“java”, “loan”));
}
}
