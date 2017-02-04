#include "OperationGroup.h"

using namespace ofxOperations;

OperationGroup::OperationGroup(){
    mType = typeid(OperationGroup).name();
}

void OperationGroup::add(shared_ptr<OperationGroup> opGroup){
    operations_group_items.push_back(static_pointer_cast<OperationGroupItem>(opGroup));
}
void OperationGroup::add(shared_ptr<Operation> op){
    operations_group_items.push_back(static_pointer_cast<OperationGroupItem>(op));
}

shared_ptr<Operation> OperationGroup::add(const string& _id, const string& name, const string &description){
    auto op = make_shared<Operation>();
    op->set(_id, name, description);
    add(op);
    return op;
}
