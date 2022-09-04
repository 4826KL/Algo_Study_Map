# 基于邻接表的有向图拓扑排序

## 什么是拓扑排序

​	在图论中，**拓扑排序（Topological Sorting）**是一个**有向无环图（DAG, Directed Acyclic Graph）**的所有顶点的[线性](https://so.csdn.net/so/search?q=线性&spm=1001.2101.3001.7020)序列。且该序列必须满足下面两个条件：

- 每个顶点出现且只出现一次。
- 若存在一条从顶点 A 到顶点 B 的路径，那么在序列中顶点 A 出现在顶点 B 的前面。

> [有向无环图]()（DAG）才有拓扑排序，非DAG图没有拓扑排序一说。

如下图:

![img](https://img-blog.csdn.net/20150507001028284)

它是一个 DAG 图，那么如何写出它的拓扑排序呢？这里说一种比较常用的方法：

1. 从 DAG 图中选择一个 没有前驱（即入度为0）的顶点并输出。
2. 从图中删除该顶点和所有以它为起点的有向边。
3. 重复 1 和 2 直到当前的 DAG 图为空或**当前图中不存在无前驱的顶点为止**。后一种情况说明有向图中必然存在环。

![img](https://img-blog.csdn.net/20150507001759702)

​	于是，得到拓扑排序后的结果是 { 1, 2, 4, 3, 5 }。

​	通常，一个有向无环图可以有**一个或多个**拓扑排序序列。

## 拓扑排序的应用

拓扑排序通常用来“排序”具有依赖关系的任务。

## 拓扑排序的实现

根据上面讲的方法，关键是要**维护一个入度为0的顶点的集合**。

图的存储方式有两种：邻接矩阵和邻接表。这里我们采用**邻接表**来存储图，C++代码如下：

### hpp文件（可以理解为h和cpp文件的结合，实现一个类）

```C++
#include <iostream>
#include <list>
#include <queue>
using namespace std;


class Graph
{
    int V;          // 顶点总个数
    list<int> *adj; // 邻接表
    queue<int> q;   // 维护一个入度为0的顶点的集合
    int *indegree;  // 记录每个顶点的入度
public:
    Graph(int V);               // 构造函数
    ~Graph();                   // 析构函数
    void addEdge(int v, int w); // 添加边
    bool topological_sort();    // 拓扑排序
};


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    indegree = new int[V]; // 入度全部初始化为0
    for (int i = 0; i < V; ++i)
        indegree[i] = 0;
}

Graph::~Graph()
{
    delete[] adj;
    delete[] indegree;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    ++indegree[w];
}

bool Graph::topological_sort()
{
    for (int i = 0; i < V; ++i)
        if (indegree[i] == 0)
            q.push(i); // 将所有入度为0的顶点入队

    int count = 0; // 计数，记录当前已经输出的顶点数
    while (!q.empty())
    {
        int v = q.front(); // 从队列中取出一个顶点
        q.pop();

        cout << v << " "; // 输出该顶点
        ++count;
        // 将所有v指向的顶点的入度减1，并将入度减为0的顶点入栈
        list<int>::iterator beg = adj[v].begin();
        for (; beg != adj[v].end(); ++beg)
            if (!(--indegree[*beg]))
                q.push(*beg); // 若入度为0，则入栈
    }

    if (count < V)
        return false; // 没有输出全部顶点，有向图中有回路
    else
        return true; // 拓扑排序成功
}
```

### main.cpp

```C++
#include "Graph.hpp"

int main()
{
    Graph g(6);         // 创建图
    g.addEdge(5, 2);    
    g.addEdge(5, 0);    
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topological_sort();
    return 0;
}
```

测试如下DAG图：

![img](https://img-blog.csdn.net/20150507013500102)

输出结果是 4, 5, 2, 0, 3, 1。这是该图的拓扑排序序列之一。

每次在入度为0的集合中取顶点，并没有特殊的取出规则，随机取出也行，

这里使用的`queue`。取顶点的顺序不同会得到不同的拓扑排序序列，当然前提是该图存在多个拓扑排序序列。

## LeetCode

### [383. 赎金信 - 力扣（LeetCode）](https://leetcode.cn/problems/ransom-note/submissions/)

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        //哈希解法  空间换时间
        int record[26]={0};     //记录magazine中字母出现的次数
        for(int i=0;i<magazine.length();i++)
        {
            //通过record数组记录magazine中各个字符出现次数
            record[magazine[i]-'a']++;
        }
        for(int j=0;j<ransomNote.length();j++)
        {
            //遍历ransoNote,在record里对应的字符个数做--操作
            record[ransomNote[j]-'a']--;

            //如果小于零说明ransomNote里出现的字符，magazine没有
            if(record[ransomNote[j]-'a']<0)
            {
                return false;
            }
        }
        return true;

    }
};
```

## 思路

​	这道题目就是让判断让ransomNote中的每一个字符能否在magazine中一一匹配。

​	提示中的信息指明了每一个字母不可重复出现！同时所有字母均为小写。

​	以前这道题我使用暴力解法AC过一遍，现在学习过哈希表之后，我们可以使用哈希来解决这道问题。

​	因为题目中所有字符均为小写，我们采用空间换时间的哈希策略，用一个长度为26的数组来记录magazine中字母出现的次数，然后用**ransomNote**去验证这个数组是否包含了ransomNote所需要的所有字母！

### [1207.独一无二的出现次数](https://leetcode.cn/problems/unique-number-of-occurrences/submissions/)

```c++
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int time[2002] = {0};   //统计数字出现的频率
        for(int i=0;i<arr.size();i++)
        {
            time[arr[i]+1000]++;    //+1000是为了规避下标为负数的情况
        }   
        bool frequency[1002] = {false}; //统计相同频率是否重复出现
        for(int i=0;i<=2000;i++)
        {
            if(time[i])
            {
                if(frequency[time[i]]==false)
                {
                    frequency[time[i]]=true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;

    }
};
```

## 思路

- 哈希法 哈希数组 题目中对于数组长度给予了限制 加以修正
- **本题强调了-1000 <= arr[i] <= 1000**，那么就可以用数组来做哈希，arr[i]作为哈希表（数组）的下标，那么arr[i]可以是负数，怎么办？负数不能做数组下标。
- **此时可以定义一个2000大小的数组，例如int time[2002];**，统计的时候，将arr[i]统一加1000，这样就可以统计arr[i]的出现频率了。
- 题目中要求的是是否有相同的频率出现，那么需要再定义一个哈希表（数组）用来记录频率是否重复出现过.
- bool fre[1002]; 定义布尔类型的就可以了，
- **因为题目中强调1 <= arr.length <= 1000，所以哈希表大小为1000就可以了**。