/*
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.
*/
Focus:  1. Map operation. Map<k,v> map = new HashMap<k,v>(); map.put(k,v) 
	   Iterator.  for (Key k : map.keySet()) { map.get(k)..
		for (Value v : map.values())
		for (Map.Entry<Key, Value> entry: map.entrySet() ) {
			entry.getKey()  , entry.getValue()
		} 
	2. ArrayList<T> arrlist = new ArrayList<T>()   (vs C++ vector).  arrlist.add(v)
	   Iterator:  for (T t: arrlist) { ... }
	 
public class Solution {
    public ArrayList<String> anagrams(String[] strs) {
        Map<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
        for (int i = 0; i < strs.length; ++i) {
            char[] charArr = strs[i].toCharArray();
            Arrays.sort(charArr);
            String arr = new String(charArr);
            
            if (map.get(arr) == null) {
                ArrayList<String> tmp = new ArrayList<String>();
                tmp.add(strs[i]);
                map.put(arr, tmp);
            } else {
                map.get(arr).add(strs[i]);
            }
        }
        
        ArrayList<String> res = new ArrayList<String>();
        for (ArrayList<String> group : map.values()) {
            if (group.size() > 1) {
                for (String str : group) {
                    res.add(str);
                }
            }
        }
        
        return res;
    }
}
