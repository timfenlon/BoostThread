#pragma once
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/bind.hpp>
#include <string>
#include "ofMain.h"

using namespace std;

struct DrawNode {
	ofPoint mPoint;
	string  mWord;
};

class CSingerThread
{
public:
	static string RowRowRow;
	static string Teapot;

	string mCurrWord;
	int mLineNum;
		
	ofTrueTypeFont	mFont1;
	ofTrueTypeFont	mFont2;
	
	vector<DrawNode> mDrawNode;

public:
	CSingerThread(void);
	~CSingerThread(void);

	void sing(const string &lyrics, boost::posix_time::time_duration dur, bool indent=false);
	void draw(bool indent=false);
};

