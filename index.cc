#include <nan.h>

NAN_METHOD(AllocateBufferAndReturn) {
  size_t size = 800 * 320 * 4;
  char *data = static_cast<char *>(malloc(size));
  v8::Local<v8::Value> buf = Nan::NewBuffer(data, size).ToLocalChecked();
  info.GetReturnValue().Set(buf);
}

NAN_METHOD(AllocateBufferButDoNotReturn) {
  size_t size = 800 * 320 * 4;
  char *data = static_cast<char *>(malloc(size));
  v8::Local<v8::Value> buf = Nan::NewBuffer(data, size).ToLocalChecked();
  // not sure if compiler would optimize this
  info.GetReturnValue().Set(*data);
}

NAN_MODULE_INIT(InitModule) {
  Nan::SetMethod(target, "allocateBufferAndReturn", AllocateBufferAndReturn);
  Nan::SetMethod(target, "allocateBufferButDoNotReturn", AllocateBufferButDoNotReturn);
}

NODE_MODULE(myModule, InitModule);