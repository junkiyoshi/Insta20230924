#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetLineWidth(10);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 20;
	for (int x = 0; x <= ofGetWindowWidth(); x += span) {

		for (int y = 0; y <= ofGetWindowHeight(); y += span) {

			bool flag = ofNoise(x * 0.01, y * 0.01, ofGetFrameNum() * 0.05) < 0.5 ? true : false;

			if (flag) {

				ofSetColor(239, 139, 139);
				ofDrawLine(x - span * 0.5, y, x + span * 0.5, y);
			}
			else {

				ofSetColor(139, 139, 239);
				ofDrawLine(x, y - span * 0.5, x, y + span * 0.5);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}