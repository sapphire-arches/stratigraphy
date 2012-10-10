#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagByte::NBTTagByte(string *name) : _name(name), _val(0) {
}

NBTTagByte::NBTTagByte(string *name, char val) : _name(name), _val(val) {
}

NBTTagByte::~NBTTagByte() {
    delete _name;
}

virtual TagType NBTTagByte::GetTagType() {
    return BYTE;
}

virtual void NBTTagByte::WriteTo(ostream& out) {
    out.put(char(BYTE)); //write our header
    WriteString(out, *name); //Write name
    out.put(val); //Write our value.
}

virtual void NBTTagByte::ReadFrom(istream& is) {
    int i = is.get();
    if (i != BYTE) {
        is.setstate(ios_base::iostate::failbit);
        throw ios_base::failure("Unexpected byte: " + i + " while reading TAG_BYTE");
    }
    _name = ReadString(is);
    _val = is.get();
}

NBTTagByte& NBTTagByte::operator= (const NBTTagEnd& rhs) {
    if (rhs != *this)
        return *this;

    
    return *this;
}

string& NBTTagByte::GetName() {
    return *_name;
}
