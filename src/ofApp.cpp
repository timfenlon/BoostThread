#include "ofApp.h"
using namespace boost::posix_time;

//--------------------------------------------------------------
void ofApp::setup(){

	if(!mSinger1.mFont1.isLoaded())
	{
		mSinger1.mFont1.loadFont("verdana.ttf", 24, true, true);
		mSinger1.mFont1.setLineHeight(18.0f);
		mSinger1.mFont1.setLetterSpacing(1.037);
	}
	if(!mSinger2.mFont2.isLoaded())
	{
		mSinger2.mFont2.loadFont("frabk.ttf", 24, true, true);
		mSinger2.mFont2.setLineHeight(18.0f);
		mSinger2.mFont2.setLetterSpacing(1.037);
	}

	boost::thread_group tgroup;//Thread Group

	time_duration interval( milliseconds(800) );

	//mySinger1.sing(CSingerThread::RowRowRow, interval);
	tgroup.create_thread( boost::bind(&CSingerThread::sing, &mSinger1, CSingerThread::RowRowRow, interval, false) );
	//mySinger2.sing(CSingerThread::Teapot, interval, true);
	tgroup.create_thread( boost::bind(&CSingerThread::sing, &mSinger2, CSingerThread::Teapot, interval, true) );

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//clear scren by drawing white
	ofSetColor(ofColor::cyan);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());

	ofSetColor(ofColor::black);
	mSinger1.mFont1.drawString("Singer1", abs(ofGetWidth()*0.10f), abs(ofGetHeight()*0.05f));
	mSinger2.mFont2.drawString("Singer2", abs(ofGetWidth()*0.50f), abs(ofGetHeight()*0.05f));

	mSinger1.draw();
	mSinger2.draw(true);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
