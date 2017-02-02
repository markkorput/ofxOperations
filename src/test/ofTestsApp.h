#ifdef BUILD_TESTS

#include "ofMain.h"
#include "ofxUnitTests.h"

class ofTestsApp : public ofxUnitTestsApp{

public:
    void run();

private:
    void test_ofxOperations();
};

#endif // BUILD_TESTS
