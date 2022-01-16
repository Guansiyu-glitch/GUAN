class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> ans = new LinkedList<>();
        backTrack(new StringBuilder(s), ans, 0);
        return ans;
    }
private void backTrack(StringBuilder s, List<String> ans, int curIndex) {
    if(curIndex == s.length()) {
        ans.add(new String(s));
        return;
    }

    char c = s.charAt(curIndex);
    // 不做任何改变
    backTrack(s, ans, curIndex + 1);

    //改为大写或者小写(前提是字母)
    if((c >='A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        if(c <= 'Z') {
            s.setCharAt(curIndex, (char)(c + 32));
        } else {
            s.setCharAt(curIndex, (char)(c - 32));
        }

        backTrack(s, ans, curIndex + 1);
    }

}
