### 第七章知识点总结：

###### 1.冒泡排序

主要思路：
1.比较相邻的元素。如果第一个比第二个大，就交换它们两个。
2.对每一个相邻元素做同样的工作，从开始第一对到结尾的每一对。在这一 点，最后的元素应该会是最大的数。
3.针对多有的元素重复以上的步骤，除了最后一个。
持续每次对越来越少的元素重复上面的步骤，知道没有任何一对数字需要比较。



###### 2.选择排序

主要思路：

每一次从无序组的数据元素中选出最小的一个元素，存放在无序组的起始位置，无需组的元素减少，有序组的元素增加，直到全部待排序的数据元素排完。

###### 3.插入排序

主要思路：
插入排序是最简单常用的方法，将数组分为两部分，排好序的数列，以及未排序的数列，将未排序的数列中的元素 与排好序的数列进行比较，然后将该元素插入到已排序列的合适位置中。



###### 4.快速排序

主要思想：分治和递归

（1）选择一个枢纽元素

（2）小于枢纽的元素放左半区，大于放右半区

（3）对左右半区进行步骤（1）（2）

递归直到半区内只有一个元素时返回。

###### 5.归并排序思想（拆分、合并）

简单的说，就是将一个序列不断的进行二分（当然也可以三分、多分）分裂，然后递归下去，再合并。

###### 6.堆排序：

（1）最大堆调整（Heapify）：将堆的末端子节点作调整，使得子节点永远小于父节点
（2）创建最大堆（CreateHeap）：将堆中的所有数据重新排序
（3）堆排序（HeapSort）：移除位在第一个数据的根节点，并做最大堆调整的递归运算.

###### 7.希尔排序

基本思想：先选定一个整数，把待排序文件中所有记录分成若n个组，所有距离相同的分在同一组内，并对每一组内的记录进行排序。然后，重复上述分组和排序的工作。当到达n=1时，所有记录在统一组内排好序。

###### 8.桶排序

工作的原理是将数组分到有限数量的桶子里。每个桶子再个别排序。

###### 9.外部排序

每次进行部分排序，然后将各组部分排序的结果合并，再次排序得到最终的结果．

### 学习心得体会：

本周学习了第七章排序，感觉还算顺利，代码写的比以前多，效率有提升。各个算法的基本原理和代码可以看理解。写不出感悟了，ok.



