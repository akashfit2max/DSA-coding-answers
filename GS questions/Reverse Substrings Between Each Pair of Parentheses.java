class Solution {
    public String reverseParentheses(String s) {
        Stack<String> st = new Stack<>();
        String str = "";
        for(Character ch : s.toCharArray()) {
            // agar a to z k beech me h thoo make a string
            if(ch >= 'a' && ch <= 'z') {
                str += ch;
            }
            else if(ch == '(') {
                // push the curent made string
                st.push(str);
                str = "";
            }
            else {
                String p = st.pop();
                String t = new StringBuilder(str).reverse().toString();
                str = p + t;
            }
        }
        return str;
    }
}