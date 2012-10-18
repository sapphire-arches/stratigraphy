#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"
#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagByte::NBTTagByte(string& name) : NBTTag(name), _val(0) {
}

NBTTagByte::NBTTagByte(string& name, char val) : NBTTag(name), _val(val) {
}

NBTTagByte::~NBTTagByte() {
}

TagType NBTTagByte::GetTagType() {
    return BYTE;
}

void NBTTagByte::WriteData(ostream& out, char* buff) {
    out.put(_val); //Write our value.
}

void NBTTagByte::ReadData(istream& is, char* buff) {
    _val = is.get();
}

NBTTagByte& NBTTagByte::operator= (const NBTTagByte& rhs) {
    if (this == &rhs)
        return *this;
    
    delete &_name;
    _name = string(rhs._name);
    _val = rhs._val;

    return *this;
}

string& NBTTagByte::GetName() {
    return _name;
}

char NBTTagByte::GetValue() {
   return _val;
}

void NBTTagByte::SetValue(char c) {
    _val = c;
}
