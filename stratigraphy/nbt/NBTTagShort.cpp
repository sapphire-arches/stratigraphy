#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"
#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagShort::NBTTagShort(istream& from) {
    ReadFrom(from);
}

NBTTagShort::NBTTagShort(string& name) : _val(0), _name(name) {
}

NBTTagShort::NBTTagShort(string& name, short val) : _val(val), _name(name) {
}

NBTTagShort::~NBTTagShort() {
}

TagType NBTTagShort::GetTagType() {
    return SHORT;
}

void NBTTagShort::WriteTo(ostream& o) {
    o.put(char(SHORT));
    char buff[4];
    WriteString(o, _name, buff);
    WriteShortBE(o, _val, buff);
}

void NBTTagShort::ReadFrom(istream& is) {
    int i = is.get();
    if (i != SHORT) {
        is.setstate(ios_base::failbit);
        const string fmt = "Error reading short tag, unexpected tag header byte %02x.";
        const string temp = (boost::format(fmt) % i).str();
        throw ios_base::failure(temp);
    }
    char buff[4];
    _name = ReadString(is, buff);
    _val = ReadShortBE(is, buff);
}

string& NBTTagShort::GetName() {
    return _name;
}

NBTTagShort& NBTTagShort::operator= (const NBTTagShort& rhs) {
    if (&rhs == this) {
        return *this;
    }

    delete &_name;

    _name = string(rhs._name);
    _val = rhs._val;

    return *this;
}
