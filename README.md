# CPPDemo

Use To Record  The Test Demo

## MFC Demo

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

