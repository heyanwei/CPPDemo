#pragma once

class SingletonCT
{
public:
	static SingletonCT& Instance();

	void Test();

private:
	SingletonCT();
	~SingletonCT();
};

