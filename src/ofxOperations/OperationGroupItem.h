#pragma once

namespace ofxOperations {

    ///
    /// @name OperationGroupItem
    ///
    /// @description Abstract class that both the
    /// OperationGroup and Operation class inherit from
    /// as instances of both child-classes appear in an
    /// ordered list within an OperationGroup
    ///
    class OperationGroupItem {
    public:
        const string& getType(){ return mType; }

    protected:
        string mType;
    };
}
