#include "OperationGroup.h"

using namespace ofxOperations;

void OperationGroup::add(shared_ptr<Operation> op){
    operations.push_back(op);
}

void OperationGroup::remove(shared_ptr<Operation> op){
    for(auto it = operations.begin(); it != operations.end(); it++){
        if((*it) == op){
            operations.erase(it);
            return;
        }
    }
}

void OperationGroup::add(OperationGroup &otherGroup){
    // copy all operations from otherGroup to this group
    for(auto &op : otherGroup.getOperations()){
        this->add(op);
    }
}

void OperationGroup::add(shared_ptr<OperationGroup> otherGroup){
    add(*otherGroup.get());
}

void OperationGroup::remove(OperationGroup &opGroup){
    for(auto &op : opGroup.getOperations()){
        this->remove(op);
    }
}

void OperationGroup::remove(shared_ptr<OperationGroup> otherGroup){
    remove(*otherGroup.get());
}

shared_ptr<Operation> OperationGroup::add(const string& name, const string &description){
    auto op = make_shared<Operation>();
    op->set(name, description);
    add(op);
    return op;
}
