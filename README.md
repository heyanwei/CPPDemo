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

