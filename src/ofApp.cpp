#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    width = 20;
    ofSetFrameRate(20);
    pcapThread.startThread(true, false);
}

//--------------------------------------------------------------
void ofApp::update(){
    // Faire memcpy
    memcpy(grid[1], grid[0], sizeof(bool)*31*32);
    if (pcapThread.current_frame){

        pcapThread.lock();
        long int current = pcapThread.current_frame->daddr.int_address;
        long int s_current = pcapThread.current_frame->saddr.int_address;
        for(int k=0; k<16; k++){
            int mask =  1 << k;
            int masked_n = current & mask;
            int thebit = masked_n >> k;
            grid[0][k] = thebit;
        }
        for(int k=0; k<16; k++){
            int mask =  1 << k;
            int masked_n = s_current & mask;
            int thebit = masked_n >> k;
            grid[0][16+k] = thebit;
        }
        pcapThread.unlock();
    }

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
