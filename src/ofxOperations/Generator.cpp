// OF
#include "ofAppRunner.h"
// ofxOperations
#include "Generator.h"
#include "Operation.h"

using namespace ofxOperations;

class QuitOp : public Operation {
public:
    QuitOp(){ set("Quit", "Quit OpenFrameworks Application"); }
protected:
    void perform(){ ofExit(); }
};

shared_ptr<OperationGroup> Generator::generateDefault(){
    auto ops = make_shared<OperationGroup>();
    ops->add(make_shared<QuitOp>());
    return ops;
}
