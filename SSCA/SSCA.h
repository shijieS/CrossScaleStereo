#pragma once
#include "CommFunc.h"
#include "CCMethod.h"
#include "CAMethod.h"
#include "PPMethod.h"
#define COST_ALPHA 0.9

//
// SSCA - Scale Space Cost Aggregation class
//
class SSCA
{
public:
	//
	// Color Image
	//
	Mat lImg;
	Mat rImg;
	int wid;
	int hei;
	//
	// Disparity Image
	//
	Mat lDis;
	int maxDis;
	int disSc;
	//
	// Cost Volume
	//
	Mat* costVol;
public:
	// get left disparity
	Mat getLDis( void );
	// save cost volume
	void saveCostVol( const string fn );
	// add previous pyramid costVol
	void AddPyrCostVol( SSCA* pre );
public:
	//
	// Constructor & Desctructor
	//
	SSCA( const Mat l, const Mat r, const int m, const int d );
	~SSCA(void);
	//
	// 1. Cost Computation
	//
	void CostCompute( CCMethod* ccMtd = NULL );
	//
	// 2. Cost Aggregation
	//
	void CostAggre( CAMethod* caMtd = NULL );
	//
	// 3. Match
	//
	void Match( void );
	//
	// 4. Post Process;
	//
	void PostProcess( PPMethod* ppMtd = NULL );
};

