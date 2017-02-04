#pragma once

// OF dependencies
#include "ofTypes.h"
#include "ofEvent.h"

namespace ofxOperations {

    class Operation {

        public: // methods

            Operation();
            Operation(string _id, string name="", string description="");
            void run();

        protected:

            virtual void perform(){}

        public: // getters / setters

            void set(string _id, string name="", string description="");
            void setId(string _id){ this->_id = _id; }
            const string& getName(){ return name; }
            void setName(string name){ this->name = name; }
            const string& getDescription(){ return description; }
            void setDescription(string desc){ this->description = desc; }

        public: // events

            ofEvent<Operation> startEvent, endEvent;

        private: // attributes

            string _id;
            string name;
            string description;
    };

} // namespace ofxOperation
