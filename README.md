#### [Github项目地址](https://github.com/lxtyin/SimpleComparator)

2021/9/23

#### 环境需求

- 仅支持windows

- 装有MinGW并且添加到环境变量（使用g++编译）

#### 用法

1. 将两份程序（一般是你的不知道哪错了的程序和标答/暴力解）扔进`program1.cpp`和`program2.cpp`
2. 在`generator.cpp`里写随机输入数据生成器，对应你的这道题目
3. 双击`run.bat`运行，输入希望对拍的次数，等待对拍结果

对拍结果完全一样显示 **[Accepted]**

不同则会显示 **[Wrong Answer]**

有不同时，会同时显示使两份程序结果不一样的数据，你就可以复制拿去debug了

同时所有结果都会保存在`result.txt`里，关掉控制台后仍然可以查看

![](http://lxtyin.ac.cn/img/simplecomparator/1.png)



### 2022/8/10更新

- 改了部分文件名，`constructor`被改成了`generator`，其他变更不影响使用
- 默认对比方式已忽略行末空格和回车。

- 现已支持special judge

用法：同样方法放入程序和编写数据生成器之后，还需在 `work/special_judge.cpp` 中编写spj

spj必须包含头文件 `judge.h`，这个头文件提供了一些基础的api。

引用头文件后，你可以使用三个输入流，它们都为 ifstream。

`inp` 从本组的输入数据中读取

`ans1` 从 `program1` 的输出数据中读取

`ans2` 从 `program2` 的输出数据中读取

判题之后，你需要给出评测结果，`judge.h` 提供了以下api，建议使用：

- `AC();` 给出正确提示
- `WA();` 给出错误提示
- `display();` 显示数据，建议在答案错误时显示
- `color(int x);` 更改字体颜色，具体颜色对应值如下：![](https://ask.qcloudimg.com/http-save/yehe-7873581/mg9ppffbb6.png?imageView2/2/w/1620)

- `hint(const string &s);` 以黄色字体给出提示信息
- `warn(const string &s);` 以红色字体给出提示信息

当然你也可以自由使用 `cout/printf` 等方式输出。

例如，下面是一个判断精度是否在 `1e-6` 以内spj

```C++
#include "judge.h"

// sample spj for accuracy within 1e-6
// input data can be read by inp(ifstream)
// program1 output can be read by ans1(ifstream), so as ans2.
int main() {
    double as1, as2;
    ans1 >> as1;
    ans2 >> as2;

    if(abs(as1 - as2) / as2 < 1e-6) AC();
    else {
        WA();
        display();
        color(YELLOW);
        printf("The accuracy is %.10f\n", abs(as1 - as2) / as2);
        color(WHITE);
    }

    inp.close();
    ans1.close();
    ans2.close();
    return 0;
}
```

效果如下：

![](http://lxtyin.ac.cn/img/simplecomparator/2.png)