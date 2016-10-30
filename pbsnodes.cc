#include <node.h>
#include <stdio.h>

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

    void statnode(const FunctionCallbackInfo<v8::Value>& args) {

        char server_out[MAXSERVERNAME] = "";
        int connect = cnt2server(server_out);
        //printf("connected to server %s", server_out);

        struct batch_status *bstatus;
        int local_errno = 0;

        /*
        char **nodearg = (char **)calloc(2, sizeof(char *));
        nodeargs[0] = strdup("");
        nodeargs[1] = '\0';
        */

        bstatus = pbs_statnode_err(connect, "", NULL, NULL, &local_errno);

        Isolate* isolate = args.GetIsolate();
        Local<Object> ret = Object::New(isolate);

        for (struct batch_status *p_status = bstatus;p_status;p_status = p_status->next) {
            Local<Object> q = Object::New(isolate);

            Local<Array> jobs = Array::New(isolate);

            //iterate through attributes in a queue
            attrl *at = p_status->attribs;
            while(at) {
                Local<String> name = String::NewFromUtf8(isolate, at->name);
                if( !strcmp(at->name, ATTR_NODE_mom_port) || !strcmp(at->name, ATTR_NODE_mom_rm_port) ) {
                    //as integer
                    int i = atoi(at->value);
                    Local<Integer> value = Integer::New(isolate, i);
                    q->Set(name, value);
                } else if( !strcmp(at->name, ATTR_NODE_np)) {
                    //TODO - I assume pbsnodes will always list np before jobs.. otherwise jobs will be overwritten
                    //np..
                    int np = atoi(at->value);
                    Local<Integer> value = Integer::New(isolate, np);
                    q->Set(name, value);
                    for(int i = 0;i < np; ++i) {
                        jobs->Set(i, v8::Null(isolate)); //reset to null
                    }
                } else if( !strcmp(at->name, ATTR_NODE_properties) ) {
                    //quote delimited strings
                    char *token = strtok(at->value, ",");
                    Local<Array> values = Array::New(isolate);
                    int i = 0;
                    while(token) {
                        values->Set(i++, String::NewFromUtf8(isolate, token));
                        token = strtok(NULL, ","); //next..
                    }
                    q->Set(name, values);
                } else if( !strcmp(at->name, ATTR_NODE_status) ) {
                    //key/value list
                    char *token = strtok(at->value, ",");
                    Local<Object> states = Object::New(isolate);
                    
                    while(token) {
                        //split "key=value"
                        char *dpos = strchr(token, '=');
                        *dpos = 0; //mark it as end of state name
                        //int n = atoi(dpos+1);
                        //states->Set(String::NewFromUtf8(isolate, token), Integer::New(isolate, n));
                        states->Set(String::NewFromUtf8(isolate, token), String::NewFromUtf8(isolate, dpos+1));

                        token = strtok(NULL, ","); //next..
                    }
                    q->Set(name, states);
                } else if( !strcmp(at->name, ATTR_NODE_jobs) ) {
                    //jobs list
                    char *token = strtok(at->value, ",");
                    while(token) {
                        //split "id/jobid"
                        char *dpos = strchr(token, '/');
                        *dpos = 0; //mark it as end of state name
                        int id = atoi(token);
                        jobs->Set(id, String::NewFromUtf8(isolate, dpos+1));
                        token = strtok(NULL, ","); //next..
                    }
                } else {
                    //as string
                    Local<String> value = String::NewFromUtf8(isolate, at->value);
                    q->Set(name, value);
                }
                at = at->next;
            }

            //jobs are set at the end to make sure it exists even if it's empty
            q->Set(String::NewFromUtf8(isolate, ATTR_NODE_jobs), jobs);

            ret->Set(String::NewFromUtf8(isolate, p_status->name), q);
        }

        args.GetReturnValue().Set(ret);
    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "all", statnode);
    }

    NODE_MODULE(pbsnodes, init)
}  
