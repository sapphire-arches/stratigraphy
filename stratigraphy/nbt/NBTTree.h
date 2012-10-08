#ifndef _STRAT_NBT_NBTTREE_H_
#define _STRAT_NBT_NBTTREE_H_

#include "nbt/NBTTag.h"

namespace stratigraphy { namespace nbt {
    class NBTTree {
        public:
            NBTTree();
            NBTTree(const NBTTree &tree);

            virtual ~NBTTree();

            NBTTagCompound GetRoot();
            
            NBTTree & operator= (const NBTTree &tree);

        private:
            NBTTagCompound _root;
    };
}; };

#endif
