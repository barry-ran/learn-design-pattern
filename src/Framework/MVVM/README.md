# MVVM
MVVM(Model-View-ViewModel 的缩写)模式和 MVP 模式相比，MVVM 模式用 ViewModel 替换了 Presenter ，其他层基本上与 MVP 模式一致，ViewModel 可以理解成是 View 的数据模型和 Presenter 的合体。

![](https://github.com/zlgopen/awtk-mvvm/raw/master/docs/images/mvvm.png)

- View(视图)：负责绘制 UI 元素、与用户进行交互(在 Android 中 Activity、Fragment、View都可以做为 View 层)
- Model(模型)：负责处理数据、状态和业务逻辑(主要职责是存储、检索、操纵数据)；
- ViewModel(视图模型)：主要包括界面逻辑和模型数据封装，Behavior/Command 事件响应，绑定的属性定义等。

## 特点
MVVM 模式采用双向绑定(data-binding)：View 的变动，自动反映在 ViewModel，反之亦然。这种模式实际上是框架替应用开发者做了一些工作(相当于 ViewModel 类是由库帮开发者生成的)，开发者只需要较少的代码就能实现比较复杂的交互。

## 优点
双向绑定技术，当 Model 变化时，ViewModel 会自动更新，View 也会自动变化，很好的做到数据的一致性；
低耦合，视图(View)可以独立于 Model 变化和修改，一个 ViewModel 可以绑定到不同的 View 上，当 View 变化的时候 Model 可以不变，当 Model 变化的时候 View 也可以不变；
独立开发，开发人员可以专注于业务逻辑和数据的开发(ViewModel)，设计人员可以专注于页面设计，使用 Expression Blend 可以很容易设计界面并生成 xml 代码；
可测试，界面向来是比较难于测试的，而现在测试可以针对 ViewModel 来写

## 缺点
数据绑定也使得 Bug 很难被调试，数据绑定使得一个位置的 Bug 被快速传递到别的位置，要定位原始出问题的地方就变得不那么容易了；
数据双向绑定不利于代码重用。客户端开发最常用的是 View，但是数据双向绑定技术，让每一个 View 都绑定了一个 Model，不同的模块 Model 都不同；
一个大的模块中 Model 也会很大，虽然使用方便了也很容易保证数据的一致性，但是长期持有，不释放内存就造成话费更多的内存。

# 参考链接
- [MVC、MVP 和 MVVM 之间的区别](https://henleylee.github.io/posts/2019/de9d67a4.html)
- [MVC&MVP&MVVM](https://github.com/zlgopen/awtk-mvvm/blob/master/docs/8.intro.md)
- [QML实现一个MVVM](http://www.qtcn.org/bbs/read-htm-tid-62886.html)

## 简单示例
- [基于qml Binding的mvvm模式](https://github.com/thegrondin/Mvvm-Qt-Desktop)
- [qml简单mvvm](https://github.com/wow2006/Qt-quick-MVVM)

## 复杂示例
- [Model View ViewModel framework for large Qt C++ applications](https://github.com/gpospelov/qt-mvvm)
- [基于qml实现View和ViewModel的双向绑定（自己实现Command绑定）](https://github.com/pvanhoof/mvvm)
- [使用MVVM框架开发的Qt小游戏（自己实现Command绑定](https://github.com/2018YX-game/repo)
- [a GUI project implemented with C++17 and Qt, using MVVM(Model-View-ViewModel) design.](https://github.com/JianingWang43/CPP-MVVM-Project)
- [An example of using MVVM and Observer pattern with Qt](https://github.com/skutnii/simple-observable-qt)

## 基于Qt的MVVM框架
- [QLiteMVVM is a light MVVM/MVP framework for Qt](https://github.com/mrchipset/QLiteMVVM)
- [A mvvm oriented library for Qt, to create Projects for Widgets and Quick in parallel](https://github.com/Skycoder42/QtMvvm)