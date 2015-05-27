//#include "stdafx.h"
#include "SingerThread.h"

string CSingerThread::RowRowRow ="Row row row your boat gently down the stream";
string CSingerThread::Teapot = "I'm a little teapot short and stout";

CSingerThread::CSingerThread(void)
	:mLineNum(0)
{
}

CSingerThread::~CSingerThread(void)
{
	mDrawNode.clear();
}

void CSingerThread::sing(const string &lyrics, boost::posix_time::time_duration dur, bool indent)
{
	istringstream iss;
	iss.str(lyrics);
	mLineNum = 1;
	do {
		iss >> mCurrWord;
		mLineNum++;
		if(iss) {
			DrawNode drawNode;
			if(indent) {
				drawNode.mPoint.x = abs(ofGetWidth()*0.50f);
			} else {
				drawNode.mPoint.x = abs(ofGetWidth()*0.10f);
			}
			drawNode.mPoint.y = abs(ofGetHeight()*0.10f)*mLineNum;
			drawNode.mWord = mCurrWord;
			mDrawNode.push_back(drawNode);
			//sleep interval duration
			boost::this_thread::sleep(dur);
		}//end iss
	} while( !iss.bad() && !iss.eof() );
	cout << endl;
}

void CSingerThread::draw(bool indent)
{
	for(int i=0;i<mDrawNode.size();i++)
	{
		if(indent) {
			//We draw the current word
			mFont2.drawString(mDrawNode[i].mWord, mDrawNode[i].mPoint.x, mDrawNode[i].mPoint.y);
		} else {
			//We draw the current word
			mFont1.drawString(mDrawNode[i].mWord, mDrawNode[i].mPoint.x, mDrawNode[i].mPoint.y);
		}
	}
}