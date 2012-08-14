#include "testApp.h"

//--------------------------------------------------------------
testApp::testApp(){

}

//--------------------------------------------------------------
void testApp::setup(){

	blobs = NULL;
	vidGrabber.setVerbose(true);
	vidGrabber.listDevices();
	vidGrabber.initGrabber(640, 480);
	
//	flob .setup((int)vidGrabber.getWidth(), (int)vidGrabber.getHeight(), ofGetWidth(), ofGetHeight());
	flob .setup(128,128, ofGetWidth(), ofGetHeight());

	cout << "ofxflob "  << flob.worldwidth << " : " << flob.worldheight << "\n ";
	cout << flob.videoresw << " : " << flob.videoresh << "\n ";
	

}

//--------------------------------------------------------------
void testApp::update(){
			
	vidGrabber.grabFrame();
	if(vidGrabber.isFrameNew()){
		blobs = flob.calc(	
						  flob.binarize(	vidGrabber.getPixels(), 
										(int)vidGrabber.getWidth(), 
										(int)vidGrabber.getHeight() ) );		
	}
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofBackground(0);
	
	ofSetColor(255,200);
	flob.draw();
	
	int s = 128;
//	vidGrabber.draw( ofGetWidth()-s, 0, s, s);
	flob.videoimggray.draw(ofGetWidth()-s, 0, s, s);
	
	flob.videotexbin.draw(ofGetWidth()-s, s, s, s);
	flob.videotexmotion.draw(ofGetWidth()-s, s+s, s, s);
	
	if(blobs!=NULL){
		for(int i=0; i<blobs->size();i++){
			ABlob & ab  = *(blobs->at(i));
			ofSetColor(0,0,255,100);
			ofRect(ab.bx, ab.by, ab.dimx, ab.dimy);
			ofSetColor(0,255,0,200);
			ofRect(ab.cx, ab.cy, 10,10);
							
		}
	}
	
	string info = "ofxflob info:\n";
	info += "<t/T> thresh: " + ofToString(flob.videothresh) + "\n";
	info += "<f/F> fade: " + ofToString(flob.videofade) + "\n";
	info += "<o> om: " + ofToString(flob.om) + "\n";
	info += "<x> mirrorx: " + ofToString(flob.mirrorX) + "\n";
	info += "<y> mirrory: " + ofToString(flob.mirrorY) + "\n";
	
	ofSetColor(255);
	ofDrawBitmapString(info, 10,20);
		
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	
	if(key=='t'){
		flob.videothresh--;	
	}
	if(key=='T'){
		flob.videothresh++;	
	}
	if(key=='f'){
		flob.videofade--;	
	}
	if(key=='F'){
		flob.videofade++;	
	}
	if(key=='o'){
		flob.om ^= 1;	
	}
	if(key=='x'){
		flob.mirrorX ^= true;	
	}
	if(key=='y'){
		flob.mirrorY ^= true;	
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::resized(int w, int h){

}
