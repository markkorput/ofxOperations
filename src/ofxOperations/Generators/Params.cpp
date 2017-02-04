#include "Params.h"

using namespace ofxOperations;
using namespace ofxOperations::Generators;

shared_ptr<OperationGroup> Params::generateFor(const ofParameterGroup &group){
    auto opGroup = make_shared<OperationGroup>();

    for(int i=0; i<(int)group.size(); i++){
        string type = group.getType(i);
        string name = group.getName(i);

        if(type == typeid(ofParameterGroup).name()){
            auto subOpGroup = generateFor(group.getGroup(i));
            opGroup->add(subOpGroup);
            continue;
        }

        // generate operations for a single param
        auto subOpGroup = generateFor(group.get(i));
        opGroup->add(subOpGroup);
    }

    return opGroup;
}

shared_ptr<OperationGroup> Params::generateFor(const ofAbstractParameter &param){
    auto opGroup = make_shared<OperationGroup>();

    auto setOp = make_shared<Operation>();
    setOp->set("set-"+param.getName(), "Set " + param.getName());
    opGroup->add(setOp);
    return opGroup;
}
