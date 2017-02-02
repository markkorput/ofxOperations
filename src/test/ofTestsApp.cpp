#ifdef BUILD_TESTS

#include "ofTestsApp.h"
#include "ofMain.h"
#include "ofxUnitTests.h"

void ofTestsApp::run(){
    test_ofxOperations();
}

void ofTestsApp::test_ofxOperations(){
    test_eq(1,2, "not good");
}

#endif // BUILD_TESTS
