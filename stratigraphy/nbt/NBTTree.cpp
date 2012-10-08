#include "nbt/NBTTree.h"

using namespace stratigraphy::nbt;

NBTTree::NBTTree() : _root() {
}

NBTTree::NBTTree(const NBTTree &other) : root (other.root) {
}

NBTTree::~NBTTree() {
}

NBTTree::GetRoot() {
    return _root;
}

NBTTree &NBTTree::operator= (const NBTTree &other) {
    if (&other == this) {
        return *this;
    }
    _root = other._root;
    return *this;
}
