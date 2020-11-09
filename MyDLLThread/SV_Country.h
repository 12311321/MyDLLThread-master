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
	/// 세금 징수 함수. 단위 시간 당 세금 계산하여 예산에 반영
	/// </summary>
	void CollectTaxes();
	/// <summary>
	/// 정책실행함수. 정책 비용을 계산하여 국가 예산에 청구.
	/// </summary>
	void EnforcePolicy();

	/// <summary>
	/// 비쥬얼 스튜디오 개발환경에서 활용하는 디버거용 print 함수.
	/// consol에 country의 상태를 출력한다.
	/// </summary>
	void PrintState();

	/// <summary>
	/// 현재 보유중인 예산을 반환
	/// </summary>
	/// <returns> budget </returns>
	long long GetBudget();
};