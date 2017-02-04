#include "OperationGroup.h"

using namespace ofxOperations;

void OperationGroup::add(shared_ptr<Operation> op){
    operations.push_back(op);
}

void OperationGroup::add(shared_ptr<OperationGroup> otherGroup){
    // copy all operations from otherGroup to this group
    for(auto op : otherGroup->getOperations()){
        this->add(op);
    }
}

shared_ptr<Operation> OperationGroup::add(const string& _id, const string& name, const string &description){
    auto op = make_shared<Operation>();
    op->set(_id, name, description);
    add(op);
    return op;
}
