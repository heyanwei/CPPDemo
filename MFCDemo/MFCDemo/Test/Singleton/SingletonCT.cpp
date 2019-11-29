#include "stdafx.h"
#include "SingletonCT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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
