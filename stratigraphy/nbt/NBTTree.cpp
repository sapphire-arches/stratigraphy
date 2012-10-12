#include "nbt/NBTTree.h"

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTree::NBTTree(istream& from) : _root(from) {
}

NBTTree::NBTTree(string& name) : _root(name) {
}

NBTTree::NBTTree(const NBTTree &other) : _root (other._root) {
}

NBTTree::~NBTTree() {
}

NBTTagCompound NBTTree::GetRoot() {
    return _root;
}

void NBTTree::WriteTo(ostream& to) {
    _root.WriteTo(to);
}

NBTTree &NBTTree::operator= (const NBTTree &other) {
    if (&other == this) {
        return *this;
    }
    _root = other._root;
    return *this;
}
