## 测试文件以及测试demo使用指南

### demo均放在0exe内，demo主文件均放在test内

### 1.实现牛顿迭代法

* 实现迭代公式为多项式的牛顿迭代

  demo主文件test_ndd.c，demo为test_ndd.exe

  根据提示输入多项式

  然后输入迭代初值和精度w1,w2

  ![image-20220424230541184](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424230541184.png)

  ![image-20220424230507331](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424230507331.png)

* 实现迭代公式为任意可导函数式的牛顿迭代

  demo为test_ndd_b.exe,demo主文件为test_ndd_b.c

  输入函数和导函数：在test_ndd_b.c源文件的y_yuan函数中输入符合c语言语法的函数，

  在y_dao函数中输入导函数

  然后输入迭代初值和精度w1,w2
  
  ![image-20220424230633030](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424230633030.png)
  
  ![image-20220424230708386](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424230708386.png)

### 2.实现拉格朗日插值法

demo代码主文件，test_lglrc.c

根据提示输入用来插值的原函数的一系列坐标点。

然后可以返回插值结果，并且可以新增点

注意！为了美观，实际上打印显示多项式时，系数只打印两位小数

![image-20220424230724382](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424230724382.png)

![image-20220424230751499](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424230751499.png)

![image-20220424230835644](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424230835644.png)

![image-20220424230850882](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424230850882.png)

具体多项式的实现可以看文件mult.c

### 3.实现龙贝格积分法

demo：test_lbg.exe.文件：test_lbg.c

在test_lbg.c里面的f_yuan函数里面修改用来求积分的原函数。

然后用来运行。

默认是使用x^2+x^3当做原函数来使用的。

![image-20220424231440233](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424231440233.png)

![image-20220424234529123](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424234529123.png)

![image-20220424234550389](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20220424234550389.png)

### 4.实现四阶龙格贝塔方法

## 具体实现的文件结构

### 1.pos模块

表示二维坐标点的结构

### 2.item表示单项的结构

记录基本初等函数(没有一个是和式）的乘积。

有效的初等函数类型有，指数函数，幂函数,三角函数等

这个结构存储基本初等函数的乘积。

### 3.mult

表示一元幂函数多项式的结构

能够进行多项式的加减，乘除运算

### 4.lglrc拉格朗日插值多项式

能够根据输入的点的序列，得到拉格朗日多项式结果

### 5.ndc牛顿插值多项式

### 6.func模拟函数多项式

实现item的单项的加减组合。

也就是func用来来存储多个item单项组合成的多项式

func只能是简单基本初等函数的乘积通过加减组合起来的形式。

当前实现到：

* 过渡实现一：

  用自变量幂函数组合的多项式代替func

### 7.ndd进行牛顿迭代法计算