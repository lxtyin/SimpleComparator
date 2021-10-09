#### [Github项目地址](https://github.com/lxtyin/SimpleComparator)

#### 用法：

需要装有MinGW并且添加到环境变量

1. 将两份程序（一般是你的不知道哪错了的程序和标答）扔进program1.cpp和program2.cpp
2. 在constructor.cpp里写随机输入数据生成器，对应你的这道题目
3. 双击run.bat运行，输入希望对拍的次数，等待对拍结果

对拍结果完全一样显示 **[Accepted]**

不同则会显示 **[Wrong Answer]**

有不同时，会同时显示使两份程序结果不一样的数据，你就可以复制拿去debug了

同时所有结果都会保存在result.txt里，关掉控制台后仍然可以查看

![](https://images.cnblogs.com/cnblogs_com/blogs/684906/galleries/2042436/o_211009051720QQ%E6%88%AA%E5%9B%BE20211001201358.png)



#### 原理：

原理其实没啥好说的（（

先调用随机数生成器构造输入数据data.txt，再分别扔进两份代码跑

用另一个脚本比较输出内容，返回结果即可。

ps：一开始是用纯c语言和c++的文件读写搞的，但奈何我太菜搞不出来

然后学习了队友教的.bat大法，很快就搞好了。



#### BUG：

尝试了makefile不知道为啥不管用，而且用makefile对mingw还有特殊要求，~~所以直接给删了~~

坏处就是每次运行要先编译个几秒，~~问题不大~~

2021/9/23