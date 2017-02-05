#pragma once

// OF dependencies
#include "ofTypes.h"
#include "ofEvent.h"

namespace ofxOperations {

    class Operation {

        public: // methods

            Operation();
            Operation(string name, string description="");
            void run();

        protected:

            virtual void perform(){}

        public: // getters / setters


            const string& getName(){ return name; }
            void setName(string name){ this->name = name; }
            const string& getDescription(){ return description; }
            void setDescription(string desc){ this->description = desc; }
            void set(const string& name, const string& description = "");
            void setAsync(bool async=true){ bAsync = async; }

        public: // events

            ofEvent<Operation> startEvent, endEvent;

        private: // attributes

            bool bAsync;
            string name;
            string description;
    };

} // namespace ofxOperation
