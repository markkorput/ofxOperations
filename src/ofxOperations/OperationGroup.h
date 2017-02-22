#pragma once

// OF
#include "ofTypes.h"
// ofxOperations
#include "Operation.h"

namespace ofxOperations {

    class OperationGroup {

        public: // methods

            ~OperationGroup(){ destroy(); }
            void destroy();

            void add(shared_ptr<Operation> op);
            void add(OperationGroup &opGroup);
            void add(shared_ptr<OperationGroup> opGroup);
            shared_ptr<Operation> add(const string& name = "", const string &description = "");

            void remove(shared_ptr<Operation> op);
            void remove(Operation &op);
            void remove(OperationGroup &opGroup);
            void remove(shared_ptr<OperationGroup> opGroup);

            void follow(shared_ptr<OperationGroup> otherGroup);
            void unfollow(shared_ptr<OperationGroup> otherGroup, bool remove=false);

            shared_ptr<Operation> getByName(const string& name);
            const vector<shared_ptr<Operation>> & getOperations(){ return operations; }

        public: // events

            ofEvent<shared_ptr<Operation>> operationAddedEvent;
            ofEvent<shared_ptr<Operation>> operationRemovedEvent;

        private: // callbacks

            void onFollowedAdded(shared_ptr<Operation> &op){ add(op); }
            void onFollowedRemoved(shared_ptr<Operation> &op){ remove(op); }

        private: // attributes

            vector<shared_ptr<Operation>> operations;
            vector<shared_ptr<OperationGroup>> followedGroups;
    };

} // namespace ofxOperations
