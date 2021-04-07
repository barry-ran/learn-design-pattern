#pragma once
class IDisplay
{
public:
    virtual ~IDisplay() {}
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void print() = 0;
    // 基类控制打印的核心逻辑，子类去实现具体细节
    void display () {
        open();
        print();
        close();
    }
};