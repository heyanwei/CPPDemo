#pragma once

class SingletonCT
{
public:
	static SingletonCT& Instance()
	{
		static SingletonCT theCT;
		return theCT;
	}

	void Test();

private:
	SingletonCT();
	~SingletonCT();
};

