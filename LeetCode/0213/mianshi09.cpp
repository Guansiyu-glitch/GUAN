//面试题 01.09. 字符串轮转
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.length() == s2.length() && (s2 + s2).find(s1) != -1;
    }
};
