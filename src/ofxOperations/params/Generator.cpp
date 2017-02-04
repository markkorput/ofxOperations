#include "Generator.h"
#include "Operation.h"

using namespace ofxOperations;
using namespace ofxOperations::Params;

shared_ptr<OperationGroup> Generator::generateFor(ofParameterGroup &group, const string &prefix){
    auto opGroup = make_shared<OperationGroup>();

    for(int i=0; i<(int)group.size(); i++){
        string type = group.getType(i);

        if(type == typeid(ofParameterGroup).name()){
            auto subOpGroup = generateFor(group.getGroup(i), prefix+group.getName(i)+"/");
            opGroup->add(subOpGroup);
            continue;
        }

        // generate operations for a single param
        auto subOpGroup = generateFor(group.get(i), prefix);
        opGroup->add(subOpGroup);
    }

    return opGroup;
}

shared_ptr<OperationGroup> Generator::generateFor(ofAbstractParameter &param, const string &prefix){
    auto opGroup = make_shared<OperationGroup>();

    auto op  = make_shared<Params::Operation>();
    op->set("set-param-" + prefix + param.getName(),
            "Set param " + prefix + param.getName());
    op->setParameter(&param);
    opGroup->add(op);

    return opGroup;
}
