#include "nbt/NBTTag.h"
#include <string>

using namespace stratigraphy;
using namespace nbt;
using namespace std;

NBTTagCompound::NBTTagCompound() {
    Init(new string(), new vector<NBTTag*>());
}

NBTTagCompound::NBTTagCompound(string* name) {
    Init(name, new vector<NBTTag*>());
}

NBTTagCompound::NBTTagCompound(string* name, vector<NBTTag*>* tags) {
    Init(name, tags);
}

void NBTTagCompound::Init(string* name, vector<NBTTag*>* tags) {
    _name = *name;
    _tags = *tags;
}

NBTTagCompound::~NBTTagCompound() {
    delete &_tags;
    delete &_name;
}

TagType NBTTagCompound::GetTagType() {
    return COMPOUND;
}

void NBTTagCompound::WriteTo(ostream out) {
    out.put(GetTagType()); //Write tag header
    //Write name, if there is one.
    if (_name.length() > 0) {
        out.write(_name.c_str(), _name.length());
    }
}
