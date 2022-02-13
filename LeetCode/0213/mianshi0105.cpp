//面试题 01.05. 一次编辑
//字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int firstLen = first.size();
        int secondLen = second.size();
        int sub = firstLen - secondLen;
        if (abs(sub) > 1) return false;
        for (int i = 0, j = 0; i < firstLen && j < secondLen; i++, j++){
            if (first[i] != second[j]){
                // 这里sub取值只有-1,0,1
                if (sub == -2){ //这里的-2作为一次操作后的退出条件
                    return false; //替换过了或者删除或者插入了字符
                }
                else if (sub == 0) {//等于时有一次替换机会
                    sub = -2; //替换过了
                }
                else if (sub == -1) { //插入字符
                    i--;
                    sub = -2; //插入过了
                }
                else { //删除字符 sub == 1
                    j--;
                    sub = -2; //删除过了
                }
            }
        }
        return true;
    }
};
 
