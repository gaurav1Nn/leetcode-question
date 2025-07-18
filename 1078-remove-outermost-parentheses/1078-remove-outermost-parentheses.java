class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder result = new StringBuilder();
        Stack<Character> st= new Stack<>();
        int start = 0;
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(c=='(') {
                st.push(c);
            }
            else{
                st.pop();
            }
            if(st.isEmpty()){
                result.append(s,start+1,i);
                start  =  i + 1;
            }
        }
        return result.toString();
    }
}