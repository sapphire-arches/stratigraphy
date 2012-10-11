#include "nbt/NBTTag.h"
#include <string>
#include "nbt/IOUtils.h"

using namespace stratigraphy;
using namespace nbt;
using namespace std;

NBTTagCompound::NBTTagCompound(string& name) {
    Init(name, new TagMap());
}

NBTTagCompound::NBTTagCompound(string& name, vector<NBTTag*>& tagList) {
    TagMap* tags = new TagMap();

    typename vector<NBTTag*>::iterator it;
    for(it = tagList.begin(); it != tagList.end(); it++) {
        string name = (*it)->GetName();
        tags->insert(make_pair(name, (*it)));
    }

    Init(name, tags);
}

void NBTTagCompound::Init(string& name, TagMap* tags) {
    _name = name;
    _tags = *tags;
}

NBTTagCompound::~NBTTagCompound() {
    delete &_tags;
    delete &_name;
}

TagType NBTTagCompound::GetTagType() {
    return COMPOUND;
}

string& NBTTagCompound::GetName() {
    return _name;
}

void NBTTagCompound::WriteTo(ostream& out) {
    //General buffer
    char *buff = new char[4];
    out.put(GetTagType()); //Write tag header
    //Write name, if there is one.
    WriteString(out, _name, buff)
}
