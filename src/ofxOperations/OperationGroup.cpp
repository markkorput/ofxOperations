#include "ofEventUtils.h"
#include "OperationGroup.h"

using namespace ofxOperations;

void OperationGroup::destroy(){
    for(auto &followedGroup : followedGroups){
        unfollow(followedGroup);
    }
}

void OperationGroup::add(shared_ptr<Operation> op){
    operations.push_back(op);
    ofNotifyEvent(operationAddedEvent, op);
}

void OperationGroup::remove(shared_ptr<Operation> op){
    for(auto it = operations.begin(); it != operations.end(); it++){
        if((*it) == op){
            operations.erase(it);
            ofNotifyEvent(operationRemovedEvent, *it);
            return;
        }
    }
}

void OperationGroup::remove(Operation &op){
    for(auto curOp : operations){
        if(curOp.get() == &op){
            remove(curOp);
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

shared_ptr<Operation> OperationGroup::getByName(const string& name){
    for(auto op : operations)
        if(op->getName() == name)
            return op;

    return nullptr;
}

void OperationGroup::follow(shared_ptr<OperationGroup> otherGroup){
    add(otherGroup);
    ofAddListener(otherGroup->operationAddedEvent, this, &OperationGroup::onFollowedAdded);
    ofAddListener(otherGroup->operationRemovedEvent, this, &OperationGroup::onFollowedRemoved);
    followedGroups.push_back(otherGroup);
}

void OperationGroup::unfollow(shared_ptr<OperationGroup> otherGroup, bool remove){
    for(auto it = followedGroups.begin(); it != followedGroups.end(); it++){
        if((*it) == otherGroup){
            ofRemoveListener(otherGroup->operationAddedEvent, this, &OperationGroup::onFollowedAdded);
            ofRemoveListener(otherGroup->operationRemovedEvent, this, &OperationGroup::onFollowedRemoved);
            if(remove)
                this->remove(otherGroup);
            followedGroups.erase(it);
            return;
        }
    }
}
