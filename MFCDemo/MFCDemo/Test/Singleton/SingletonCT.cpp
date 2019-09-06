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
	TRACE("SingletonCT���캯��...\n");
}


SingletonCT::~SingletonCT()
{
	TRACE("SingletonCT��������...\n");
}
