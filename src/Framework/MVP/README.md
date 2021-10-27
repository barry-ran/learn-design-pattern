# MVP
MVC模式解决分离用户界面和业务逻辑的问题，但是还有一个重要的问题没有解决： 控制器是界面相关的，没有办法为控制器编写单元测试程序。为了解决上面的问题，MVP模式应运而生。MVP是Model-View-Presenter简称。

![](https://github.com/zlgopen/awtk-mvvm/raw/master/docs/images/mvp.png)

MVP(Model-View-Presenter 的缩写)模式是 MVC 的改良模式，由 IBM 的子公司 Taligent 提出。和 MVC 的相同之处在于：Controller/Presenter 负责业务逻辑，Model 管理数据，View 负责显示，只不过是将 Controller 改为了 Presenter，View 通过接口与 Presenter 进行交互，降低耦合，方便进行单元测试，同时改变了通信方向。

- Model：模型还是MVC中的模型，这里不再赘述。
- View：视图还是MVC中的视图，但它不需要向模型注册改变的事件通知了，这个由Presenter去做了。
- Presenter：作为 View 与 Model 交互的中间纽带，负责完成 View 与 Model 间的交互。可以把 Presenter 理解为一个中间层的角色，它接受 Model 层的数据，并且处理之后传递给 View 层，还需要处理 View 层的用户交互等操作。,，Controller变成了Presenter只是表面现象，最重要的是MVP对视图进行了抽象，呈现逻辑不再向控制器那样直接访问具体的视图了，而是通过视图的接口去访问视图，视图的接口是抽象的，可以有不同的实现，所以可以方便的Mock出一个视图，让编写呈现逻辑的单元测试程序成为可能。注意，这里视图的接口并不是通用的，每个视图都有一个独立的接口，有一个真正的实现和一个用于测试Mock的实现。

## 特点
- MVP模式的特点在于Presenter完全把Model和View进行了分离，并且Model、View和Presenter之间双向通信。
- View与Model不通信，都通过Presenter传递。Presenter完全把Model和View进行了分离，主要的程序逻辑在Presenter里实现。
- View非常薄，不部署任何业务逻辑，称为“被动视图(Passive View)”，即没有任何主动性，而Presenter非常厚，所有逻辑都部署在那里。
- Presenter与具体的View 是没有直接关联的，而是通过定义好的接口进行交互，从而使得在变更View时候可以保持Presenter的不变，这样就可以重用。
- 还可以编写测试用的View，模拟用户的各种操作，从而实现对Presenter的测试而不需要使用自动化的测试工具。
- 在MVP中，View并不直接使用Model，它们之间的通信是通过Presenter来进行的，所有的交互都发生在Presenter内部。在MVC中，View会直接从Model中读取数据而不是通过Controller。

## 优点
MVP 模式具有以下优点：
- 模型与视图完全分离，可以修改视图而不影响模型；
- 可以更高效地使用模型，因为所有的交互都发生在一个地方 —— Presenter 内部；
- 可以将一个 Presenter 用于多个视图，而不需要改变 Presenter 的逻辑。这个特性非常的有用，因为视图的变化总是比模型的变化频繁；
- 如果把逻辑放在 Presenter 中，那么就可以脱离用户接口来测试这些逻辑(单元测试)。

## 缺点
MVP模式具有以下缺点：
- View和Presenter 的交互会过于频繁，使得他们的联系过于紧密。也就是说，一旦视图变更了，Presenter 也要变更

# 参考链接
- [MVC、MVP 和 MVVM 之间的区别](https://henleylee.github.io/posts/2019/de9d67a4.html)
- [MVC&MVP&MVVM](https://github.com/zlgopen/awtk-mvvm/blob/master/docs/8.intro.md)