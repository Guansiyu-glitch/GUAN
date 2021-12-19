### 本周总结：

本周是学习《数据结构与算法》这本书的最后一周，因为快临近考试，所以进度有些落后，只学习了最后两章 的部分内容，会利用空余时间将遗漏的和这本书上不太理解难懂的知识再学习，进行梳理。主要学习了12章中二叉查找树几种有效的变种。自顶向下的伸展树，treap树，红黑树和确定性跳跃表等。11章摊还算法好难，完全看不懂。 数据结构是计算机专业的必修课，重要的基础。通过两个多月的学习，我从一个基本什么都不知道的小白到现在基本了解了所有类型的数据结构。通过看书，看博文敲代码学到了很多知识，但我觉得自己学的还不都深入，一些数据结构还不能完全理解做到灵活运用。接下来要开始学习《算法导论》，希望自己可以静下心耐心学习。

### 知识点总结：

##### 自顶向下的伸展树

当我们沿着树向下搜索某个节点X的时候，我们将搜索路径上的节点及其子树移走。我们构建两棵临时的树──左树和右树。没有被移走的节点构成的树称作中树。在伸展操作的过程中：
1、当前节点X是中树的根。
2、左树L保存小于X的节点。
3、右树R保存大于X的节点。

```
伪代码：

Function Top-Down-Splay
        Do 
              If X 小于 T Then 
                   If X 小于 T 的左孩子 Then 
                     T的左子节点绕T右旋 
                   EndIf    
                右连接 
              Else If X大于 T Then 
                   If X 大于 T 的右孩子 Then 
                     T的右子节点绕T左旋
                   EndIf 
				左连接 
         EndIf
```



##### 红黑树：是一种自平衡的二叉搜索树。

红黑树的五条”红黑性质”：
1).每个结点或是红色或是黑色。
2).根结点是黑色的。
3).每个叶结点是黑色的
4).如果一个结点是红色的，那么它的两个子节点都是黑色的。
5).对于每个结点，从该结点出发到其所有后代叶结点的简单路径上均包含相同数目的黑结点。

插入的四种情况：z为插入结点

case1:z=root;

color black;

case2：z.uncle=red;

把z的父节点和祖父节点颜色交换

case3:z.uncle=black(triangle);

将z 和父节点rotate;

case4:z.uncle=black(line);

把祖父节点和父节点rotate；然后交换祖父和父节点颜色。

总的思想：插入z 并上色为red；

​                   重新上色并旋转节点保证红黑树性质。(参考b站视频“大锤八十六” red black trees 讲解)。

##### 跳跃表

插入节点的流程有以下几步：

1. 新结点和各层索引结点逐一比较，确定原链表的插入位置，时间复杂度是O(logN)。

2. 把索引插入到原链表，时间复杂度是O(1)。

3. 利用抛硬币的随机方式，决定新结点是否提升到上一级索引。结果为正则提升，并且继续抛硬币，结果为负则停止，时间复杂度是O(logN)

   跳跃表删除结点的操作步骤：

   1. 自上而下，查找第一次出现结点的索引，并逐层找到每一层对应的结点（因为每层索引都是由上层索引晋升的），时间复杂度是O(logN)。
   2. 删除每一层查找到的结点，如果该层只剩下一个结点，删除整个一层，时间复杂度是O(logN)

相对于红黑树来说，由于跳跃表维持结构平衡的成本比较低，完全依靠随机。而红黑树在多次插入和删除后，需要rebalance来重新调整结构平衡。
