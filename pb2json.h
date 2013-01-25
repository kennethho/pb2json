#ifndef PB2JSON_H
#define PB2JSON_H

#include <string>

// Forward declaration
namespace google
{
  namespace protobuf
  {
    class Message;
  } // namespace protobuf
} // namespace google

std::string pb2json(const google::protobuf::Message& msg);

template <typename PbMessageType>
std::string pb2json(const std::string& str)
{
  PbMessageType msg;
  msg.ParseFromString(str);
  return pb2json(msg);
}

#endif // PB2JSON_H
