
# QT引以为豪的“信号槽”

1. 信号槽机制,简单的理解就是事件和监听器的关系。事件触发后，执行与该事件绑定的相关处理。

```
QPushButton *button = new QPushButton("Quit");

QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit())); 
```

这里就是一个标记“Quit”的按钮，点击按钮表示事件触发，执行Quit（关闭窗口）操作。


2. QObject 是所有类的根。Qt 使用这个 QObject 实现了一个单根继承的 C++。它里面有一个 connect静态函数，用于连接信号槽。


# “信号槽”进阶
信号槽机制是 Qt 编程的基础。通过信号槽，能够使 Qt 各组件在不知道对方的情形下能够相互通讯。这就将类之间的关系做了最大程度的解耦。

槽函数和普通的 C++ 成员函数没有很大的区别。它们也可以使 virtual 的；可以被重写；可以使public、protected 或者 private 的；可以由其它的 C++ 函数调用；参数可以是任何类型的。如果要说区别，那就是，槽函数可以和一个信号相连接，当这个信号发生时，它可以被自动调用。

原型

```
connect(sender, SIGNAL(signal), receiver, SLOT(slot));
```
sender 和 receiver 都是 QObject 类型的，singal 和 slot 都是没有参数名称的函数签名。SINGAL()和SLOT()宏用于把参数转换成字符串。

## 扩展 “信号槽”的其他用法

- 一个信号和多个槽相连
  这些槽会一个接一个的调用，但是顺序不确定

- 多个信号连接一个槽
  任意信号触发，槽就会被调用

- 一个信号连接到另外的一个信号
  第一个信号被触发，那么另一个信号也被触发

- 槽可以被取消连接（不常见）

*注意*
- 为了正确的连接信号槽，信号和槽的参数个数、类型以及出现的顺序都必须相同。
- 如果信号的参数多于槽的参数，那么这个参数之后的那些参数都会被忽略掉。

注意到 connect()函数其实是在 QObject 中实现的，并不局限于 GUI，因此，只要我们继承 QObject 类，就可以使用信号槽机制了。

```
class Employee : public QObject 
{ 
        Q_OBJECT 
public: 
        Employee() { mySalary = 0; }  
        int salary() const { return mySalary; } 

public slots: 
        void setSalary(int newSalary); 

signals: 
        void salaryChanged(int newSalary); 

private: 
        int mySalary; 
};


void Employee::setSalary(int newSalary) 
{ 
        if (newSalary != mySalary) { 
                mySalary = newSalary; 
                emit salaryChanged(mySalary); 
        } 
}
```



