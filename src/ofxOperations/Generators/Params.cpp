#include "Params.h"

using namespace ofxOperations;
using namespace ofxOperations::Generators;

shared_ptr<OperationGroup> Params::generateFor(const ofParameterGroup &group, const string &prefix){
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

shared_ptr<OperationGroup> Params::generateFor(const ofAbstractParameter &param, const string &prefix){
    auto opGroup = make_shared<OperationGroup>();
    opGroup->add(   "set-param-" + prefix + param.getName(),
                    "Set param " + prefix + param.getName());
    return opGroup;
}
