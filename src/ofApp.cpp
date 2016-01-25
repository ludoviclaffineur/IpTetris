#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    width = 20;
    ofSetFrameRate(10);
}

//--------------------------------------------------------------
void ofApp::update(){
    // Faire memcpy
    memcpy(grid[1], grid[0], sizeof(bool)*31*32);
    for(int i=0; i<32; i++)
        grid[0][i] = rand()%2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    for(int i=0; i<32; i++){
        for (int j=0; j<32; j++){
            if (grid[i][j] == true){
                ofDrawRectangle(0+j*(width+3), 0+i*(width+3), width, width);
            }
        }
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
