李浩维
18342046

# 一、使用python解决高数问题

- 使用python做高数题时，我们应先引入sympy库，在命令行中输入from sympy import*。

- 接着，在进行计算之前，我们应先定义x或者说给x赋值：x=Symbol('x')。

## 求极限

![习题](题目2.png)

用python求极限时，需要用到limit函数，其格式为limit(表达式，变量，趋近值)。
具体操作如下图：

![高数极限](lab4.png)

## 求泰勒展开式

![习题](题目1.png)

用python求泰勒展开式时，需要用到series函数，其格式为series(表达式，变量，指定展开点，展开阶数)。具体操作如下图：

![泰勒展开](lab5.png)

这里的pprint函数则是为了打印出方便阅读的展开式。

# 二、使用python解决线代问题

- 使用python做线代题时，我们应先引用nupmy库，在命令行中输入import numpy as np。

## 解方程 && 求dot && 求逆矩阵

![习题](题目3.png)

具体操作如下：

![矩阵方程](lab6.png)
