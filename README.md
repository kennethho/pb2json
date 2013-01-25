1. Introducton:

* Transcodes protobuf to json format
* It depends on [jansson] (http://www.digip.org/jansson/) to pack json
* It also depends on protobuf obviously

Support all type of protobuf Message (example: see test/person.proto) except binary bytes (json is text not binary)

1. Install protobuf and jansson
You can easily install protobuf and jansson in most recent Linux distros. In Ubuntu, you do:
    $ sudo apt-get install libjansson-dev libprotobuf-dev protobuf-compiler

2. Install
    $ cd $pb2json_dir/
    $ make 
    $ sudo make install

3. Test & example
    $ cd $pb2json_dir/test
    $ make && ./runtest # to see the result

4. Usage
You can refer to $src/test/test_json.cpp.

It is pretty simple to use, there are two APIs.

First overload takes a initailized protobuf message object and returns a json string.

    std::string pb2json(const google::protobuf::Message& msg);
    
This is the API to use when you have a initailized message object. Example usage:

    SomeMessage msg;
    msg.ParseFromString(str);
    cout << pb2json(msg) << endl;

Second overload takes a serialized protubuf binary in a string and returns a json string.

    template <typename PbMessageType>
    std::string pb2json(const std::string& str);

This is the API to use when you have a serialized protobuf and you know the type of message it is. Example usage:

    cout << pb2json<SomeMessage>(str) << endl;
