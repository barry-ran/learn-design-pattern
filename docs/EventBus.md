
想象一下，有一个包含大量相互交互的组件的大型应用程序，并且您想要一种方法使您的组件进行通信，同时保持松散耦合和关注点分离原则，事件总线模式可以很好地解决您的问题。
事件总线的想法实际上与网络中研究的总线（总线拓扑）非常相似。你有某种管道和连接到它的计算机，每当其中一个发送消息时，它就会被分派给所有其他人。然后，他们决定是要使用给定的消息还是只是丢弃它。

![](https://dz2cdn1.dzone.com/storage/temp/10633814-networking-bus.png)

在组件级别，它非常相似：计算机是您的应用程序组件，消息是您想要通信的事件或数据，而管道是您的 EventBus 对象。

![](https://github.com/gelldur/EventBus/raw/master/docs/res/EventBus-concept.png)
# 开源实现
 - [A lightweight and very fast event bus / event framework for C++17](https://github.com/gelldur/EventBus)
 - [A lightweight synchronous event framework for C++11](https://github.com/dquist/EventBus)
 - [A simple, header only event bus library written in modern C++17.](https://github.com/DeveloperPaul123/eventbus)