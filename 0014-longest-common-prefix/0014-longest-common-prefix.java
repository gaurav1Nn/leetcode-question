class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) return "";
        if(strs.length == 1) return strs[0];

        Arrays.sort(strs);
        int n = strs.length;
        String first = strs[0];
        String last  = strs[n-1];
        StringBuilder s = new StringBuilder();
        for(int i=0;i<Math.min(first.length(), last.length()); i++){
            if(first.charAt(i) == last.charAt(i)){
                s.append(first.charAt(i));
            }
            else{
                break;
            }
        }
        return s.toString();
    }
}