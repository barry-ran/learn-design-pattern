# sdk-eventbus
## 应用层
- 加载sdk-eventbus模块，并导出其接口
- 根据idl依赖关系使用EventBus_InitModule加载其他sdk模块
- 使用EventBus_CallModuleEvent/EventBus_CallModuleDrop调用其他模块的接口
- 使用RegisterObserver注册应用层感兴趣的通知事件
- 根据依赖关系使用RegisterObserverModule关联模块间的notify
- 根据依赖关系卸载其他sdk模块

# 自动脚本
- 根据idl生成eventbus相关代码，eventid，notifyid，包装函数等（参考sdk-audio）

## sdk开发人员
- 声明idl接口或者回调并实现
- 使用自动脚本更新eventbus自动生成代码