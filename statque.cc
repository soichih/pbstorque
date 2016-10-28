#include <node.h>
#include <stdio.h>

//#include "libpbs.h"
#include "lib_ifl.h"
#include "cmds.h"
#include "pbs_ifl.h"

namespace node_torque {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Integer;
    using v8::Date;
    using v8::Value;
    using v8::Boolean;
    using v8::Array;

/*
struct batch_status
  {

  struct batch_status *next;
  char                *name;

  struct attrl        *attribs;
  char                *text;
  };

*/

    void statque(const FunctionCallbackInfo<v8::Value>& args) {

        char server_out[MAXSERVERNAME] = "";
        char *queue_name_out;
        int any_failed = PBSE_NONE;

        struct batch_status *p_status;
        int connect = cnt2server(server_out);
        p_status = pbs_statque_err(connect, queue_name_out, NULL, NULL, &any_failed);

        Isolate* isolate = args.GetIsolate();
        Local<Object> ret = Object::New(isolate);

        //iterate through queue
        while(p_status) {
            Local<Object> q = Object::New(isolate);


            //iterate through attributes in a queue
            attrl *at = p_status->attribs;
            while(at) {
                Local<String> name = String::NewFromUtf8(isolate, at->name);
                if( !strcmp(at->name, ATTR_maxque) || !strcmp(at->name, ATTR_maxuserqueuable) || !strcmp(at->name, ATTR_total) ) {
                    //as integer
                    int i = atoi(at->value);
                    Local<Integer> value = Integer::New(isolate, i);
                    q->Set(name, value);
                } else if( !strcmp(at->name, ATTR_mtime) ) {
                    //as date
                    double d = atof(at->value);
                    Local<Value> value = Date::New(isolate, d*1000);
                    q->Set(name, value);
                } else if( !strcmp(at->name, ATTR_acluren) || !strcmp(at->name, ATTR_fromroute) || !strcmp(at->name, ATTR_enable) || !strcmp(at->name, ATTR_crayenabled) || !strcmp(at->name, ATTR_start) ) {
                    //as boolean
                    bool b = !strcmp("True", at->value);
                    Local<Boolean> value = Boolean::New(isolate, b);
                    q->Set(name, value);
                } else if( !strcmp(at->name, ATTR_aclhost) ) {
                    //host names
                    char *token = strtok(at->value, ",");
                    Local<Array> values = Array::New(isolate);
                    int i = 0;
                    while(token) {
                        values->Set(i++, String::NewFromUtf8(isolate, token));
                        token = strtok(NULL, ","); //next..
                    }
                    q->Set(name, values);
                } else if( !strcmp(at->name, ATTR_count) ) {
                    //state
                    //'Transit:0 Queued:63 Held:0 Waiting:0 Running:27 Exiting:0 Complete:0 '
                    char *token = strtok(at->value, " ");
                    Local<Object> states = Object::New(isolate);
                    while(token) {
                        //split "State:NN"
                        char *dpos = strchr(token, ':');
                        *dpos = 0; //mark it as end of state name
                        int n = atoi(dpos+1);
                        states->Set(String::NewFromUtf8(isolate, token), Integer::New(isolate, n));

                        token = strtok(NULL, " "); //next..
                    }
                    q->Set(name, states);
                } else {
                    //as string
                    Local<String> value = String::NewFromUtf8(isolate, at->value);
                    q->Set(name, value);
                }
                at = at->next;
            }

            ret->Set(String::NewFromUtf8(isolate, p_status->name), q);
            p_status = p_status->next;
        }
        args.GetReturnValue().Set(ret);
    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "statque", statque);
    }

    NODE_MODULE(addon, init)
}  
