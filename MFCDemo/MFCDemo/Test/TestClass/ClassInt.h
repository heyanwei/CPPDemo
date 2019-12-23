#pragma once
/*
测试operator用于类型转换
*/
class ClassInt
{
public:
	ClassInt();
	ClassInt(int param);

	operator int()
	{
		return _param;
	}

	ClassInt operator+(const ClassInt& addCls) const
	{
		ClassInt cInt;
		cInt._param = _param + addCls._param;
		return cInt;
	}

private:
	int _param;
};

