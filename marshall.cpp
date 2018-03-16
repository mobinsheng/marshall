#include "marshall.h"

Marshall& operator << (Marshall& output,uint8_t& c){
    output.write_uint8(c);
    return output;
}

Marshall& operator << (Marshall& output,int8_t& c){
    output.write_int8(c);
    return output;
}

Marshall& operator << (Marshall& output,uint16_t& c){
    output.write_uint16(c);
    return output;
}

Marshall& operator << (Marshall& output,int16_t& c){
    output.write_int16(c);
    return output;
}

Marshall& operator << (Marshall& output,uint32_t& c){
    output.write_uint32(c);
    return output;
}

Marshall& operator << (Marshall& output,int32_t& c){
    output.write_int32(c);
    return output;
}

Marshall& operator << (Marshall& output,uint64_t& c){
    output.write_uint64(c);
    return output;
}

Marshall& operator << (Marshall& output,int64_t& c){
    output.write_int64(c);
    return output;
}

//==========================================
Marshall& operator >> (Marshall& input,uint8_t& c){
   c = input.read_uint8();
   return input;
}

Marshall& operator >> (Marshall& input,int8_t& c){
    c = input.read_int8();
    return input;
 }

Marshall& operator >> (Marshall& input,uint16_t& c){
    c = input.read_uint16();
    return input;
 }

Marshall& operator >> (Marshall& input,int16_t& c){
    c = input.read_int16();
    return input;
 }

Marshall& operator >> (Marshall& input,uint32_t& c){
    c = input.read_uint32();
    return input;
 }

Marshall& operator >> (Marshall& input,int32_t& c){
    c = input.read_int32();
    return input;
 }

Marshall& operator >> (Marshall& input,uint64_t& c){
    c = input.read_uint64();
    return input;
 }

Marshall& operator >> (Marshall& input,int64_t& c){
    c = input.read_int64();
    return input;
 }
