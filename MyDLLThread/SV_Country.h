#pragma once
#include "pch.h"
class SV_Country {
public:
	const char* name;
	long long budget;
	long long gdp;
	float taxRate;

	long long policyCost;

public:
	SV_Country();
	/// <summary>
	/// ���� ¡�� �Լ�. ���� �ð� �� ���� ����Ͽ� ���꿡 �ݿ�
	/// </summary>
	void CollectTaxes();
	/// <summary>
	/// ��å�����Լ�. ��å ����� ����Ͽ� ���� ���꿡 û��.
	/// </summary>
	void EnforcePolicy();

	/// <summary>
	/// ����� ��Ʃ��� ����ȯ�濡�� Ȱ���ϴ� ����ſ� print �Լ�.
	/// consol�� country�� ���¸� ����Ѵ�.
	/// </summary>
	void PrintState();

	/// <summary>
	/// ���� �������� ������ ��ȯ
	/// </summary>
	/// <returns> budget </returns>
	long long GetBudget();
};