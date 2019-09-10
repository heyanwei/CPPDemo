# CPPDemo

Use To Record  The Test Demo

## MFC Demo

### 工程结构

```shell
D:.
└─MFCDemo
    ├─Debug
    └─MFCDemo
        ├─Debug
        │  └─MFCDemo.tlog
        ├─IDE
        ├─res
        ├─Test
        │  └─Utils
        └─Utils
```

IDE：主要放置MFC主框架的类

Test：主要放置测试类

utils：主要放置需要使用的工具类

### 工具类

#### DataFormat 数据格式转换

```c++

//CString 转换成unsigned short类型//
unsigned short CStringToUnShort(CString str);
```

测试用例

~~~c++
void TestDataFormat::CStringToUShort()
{
//如果全部是字符类型，会返回0//
CString str = _T("你好");
unsigned short k = hyw::utils::CStringToUnShort(str);
TRACE("%d ======\n", (int)k);

```
//如果其中有数字有字符，那么返回最前面的数字，即123//
str = _T("123你好333");
k = hyw::utils::CStringToUnShort(str);
TRACE("%d ======\n", (int)k);

//如果全部是数字，那么返回数字，即3215//
str = _T("3215");
k = hyw::utils::CStringToUnShort(str);
TRACE("%d ======\n", (int)k);
```

}
~~~

### 单例模式

#### 说明与比较

参考文档 《C++ and the Perils of Double-Checked Locking》  Scott Meyers and Andrei Alexandrescu 

<https://www.researchgate.net/publication/238437962_C_and_the_Perils_of_Double-Checked_Locking>

> ```
> If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization.
> 如果当变量在初始化的时候，并发同时进入声明语句，并发线程将会阻塞等待初始化结束。这样保证了并发线程在获取静态局部变量的时候一定是初始化过的，所以具有线程安全性。
> ```

```
//SingletonCT.h

class SingletonCT
{
public:
	static SingletonCT& Instance();

​```
void Test();
​```

private:
	SingletonCT();
	~SingletonCT();
};

//SingletonCT.cpp

#include "stdafx.h"
#include "SingletonCT.h"

SingletonCT & SingletonCT::Instance()
{
	static SingletonCT theCT;
	return theCT;
}

void SingletonCT::Test()
{
	TRACE("TEST....\n");
}

SingletonCT::SingletonCT()
{
	TRACE("SingletonCT构造函数...\n");
}

SingletonCT::~SingletonCT()
{
	TRACE("SingletonCT析构函数...\n");
}

```

```
//测试用例
void TestManager::TestInStart()
{
	//测试这种写法的单例模式会不会多次多CT初始化，结果不会//
	SingletonCT &ct1 = SingletonCT::Instance();
	ct1.Test();
	SingletonCT &ct2 = SingletonCT::Instance();
	ct2.Test();
}
```



