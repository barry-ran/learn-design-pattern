# MVC
![](https://github.com/zlgopen/awtk-mvvm/raw/master/docs/images/mvc.png)

MVC模式（Model–view–controller）是软件工程中的一种软件架构模式，把软件系统分为三个基本部分：模型（Model）、视图（View）和控制器（Controller）。

其中model处理数据，业务逻辑等；view处理界面的显示结果；controller起到桥梁的作用，来控制view和model通信以此来达到分离视图显示和业务逻辑层。

```
每个人都以不同的方式解释 MVC。这背后的原因，是今天软件工程师之间并没有100%的共识，到底什么是MVC，什么不是。所以只要你的程序有不知道视图的模型类，和专门负责用户界面的视图类，也许还有一个控制器在前者之间进行协调和通信，设计就可以称为 MVC 的变体。
```

## view
- view只负责视图显示相关逻辑，对其它逻辑无感知
- view的UI事件传递给controller，可以通过持有controller并调用controller接口实现，也可以通过观察者模式或者Qt的信号来传递给controller
- view提供必要接口给controller调用（设置、获取ui元素、处理交互等）
- model的数据变更事件通过观察者模式或者Qt的信号来通知view更新

## controller
- controller起到桥梁的作用，来控制view和model通信以此来达到分离视图显示和业务逻辑层。（view和model之间的所有耦合都用controller隔离）
- controller响应view的ui事件，处理用户交互，转换view的输入传递给model

## model
- model负责业务逻辑和数据，对视图显示和用户交互无感知
- model提供业务接口给controller调用
- model通过观察者模式或者Qt的信号通过view更新

## 生命周期管理和mvc组合关系
一般一个mvc组合的生命周期是从view创建开始，从view被销毁（代码逻辑主动销毁/用户点击关闭销毁），所以采用view管理controller，controller管理model的方式。这样想创建多个mvc组合的时候，只需创建维护view就可以了，不用自己创建维护controller和model。
- 先创建view，view中创建并持有controller（也负责销毁controller），controller创建并持有model（也负责销毁model）
- view通过controller接口操作controller
- controller也需要直接操作view，所以controller会持有view指针，通过view接口操作view
- controller通过model接口操作model
- model通过观察者模式或者Qt信号槽来通知view，model和view的关联是在controller中完成的

## MVC缺点
- controller依赖view类的具体实现（持有view类的对象），不方便对controller进行单元测试（例如view的按钮点击事件就需要创建一个真的view去界面上触发点击事件才能测试）
- model和view是有直接通信的，并没有完全解耦合。（TODO:那会有什么问题呢？）

## 注意
很多文章把model当作data，只管理数据相关，把业务逻辑放在controller中，这是错误的，正确的MVC定义是model是数据+业务，controller只负责控制view和model通信，良好的MVC设计是胖model，瘦controller。

# 参考链接
- [Simple Example of MVC (Model View Controller) Design Pattern for Abstraction](https://www.codeproject.com/Articles/25057/Simple-Example-of-MVC-Model-View-Controller-Design)
- [MVCDemo android](https://github.com/ProgressiveDevelop/MVCDemo)
- [wiki mvc](https://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller)
- [how to do mvc in cpp](https://softwareengineering.stackexchange.com/questions/426791/how-to-do-mvc-in-c)
- [深入理解MVC架构](https://www.cnblogs.com/zuoshoushizi/p/8324672.html?share_token=fb00a5a1-e303-4a10-a5ab-e4b870a09ab0)
- [MVC&MVP&MVVM](https://github.com/zlgopen/awtk-mvvm/blob/master/docs/8.intro.md)