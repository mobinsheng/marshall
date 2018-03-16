#include <iostream>
#include <vector>
#include "marshall.h"
using namespace std;

class Head:public Marshallable{
public:
    Head(){

    }
    ~Head(){

    }

    void marshall(){
        const char* inBuffer = "Hello World! !@#$%^&*()_+~`!@#$%^&*()";
        size_t len = strlen(inBuffer);

        version = 10;
        type = 2;
        seq_id = 10;
        buffer_size = len;
        memcpy(buffer,inBuffer,len);

        write_int16(version);
        write_int16(type);
        write_uint64(seq_id);
        write_uint32(buffer_size);
        write(buffer,buffer_size);
    }

    void unmarshall(){
        version = read_int16();
        type = read_int16();
        seq_id = read_uint64();
        buffer_size = read_uint32();
        memset(buffer,0,1024*4);
        read(buffer,buffer_size);
        printf("version = %d\n",version);
        printf("type = %d\n",type);
        printf("seq_id = %lld\n",seq_id);
        printf("buffer_size = %d\n",buffer_size);
        printf("buffer = %s\n",buffer);
    }
private:
    int16_t version;
    int16_t type;
    uint64_t seq_id;
    uint32_t buffer_size;
    char buffer[1024*4];
};

void test1(){
    Marshallable m;
    char outBuffer[1024] ={0};
    const char* inBuffer = "Hello World! !@#$%^&*()_+~`!@#$%^&*()";
    size_t len = strlen(inBuffer);

    for(int i = 0; i < 100; ++i){
        m.write_uint8(i);
        m.write_int8(-i);
    }

    for(int i = 0; i < 1000; ++i){
        m.write_uint16(i);
        m.write_int16(-i);
    }

    for(int i = 0; i < 10000; ++i){
        m.write_uint32(i);
        m.write_int32(-i);
    }

    for(int i = 0; i < 10000; ++i){
        if(i % 1000 == 0){
            m.write(inBuffer,len);
        }
        m.write_uint64(i);
        m.write_int64(-i);
    }

    //===============
    for(int i = 0; i < 100; ++i){
        m.read_uint8();
        m.read_int8();
    }

    for(int i = 0; i < 1000; ++i){
        m.read_uint16();
        m.read_int16();
    }

    for(int i = 0; i < 10000; ++i){
        m.read_uint32();
        m.read_int32();
    }

    for(int i = 0; i < 10000; ++i){
        if(i % 1000 == 0){
            m.read(outBuffer,len);
            printf("%s\n",outBuffer);
        }
        uint64_t v = m.read_int64();
        assert(v == i);
        m.read_int64();

        printf("%d\n",v);
    }
}

void test2(){
    Head h;
    h.marshal();
    h.data();
    h.unmarshal();
}

int main()
{
    test1();
    test2();
    return 0;
}
