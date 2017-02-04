#include "OperationGroup.h"

using namespace ofxOperations;

void OperationGroup::add(shared_ptr<OperationGroup> opGroup){

}
void OperationGroup::add(shared_ptr<Operation> op){
    operations.push_back(op);
}
