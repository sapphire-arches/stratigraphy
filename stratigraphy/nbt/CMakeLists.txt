include_directories (..)

add_library(nbt IOUtils
                NBTTagEnd
                NBTagByte
                NBTTagCompound
                NBTTag
                NBTTree
           )
target_link_libraries (nbt boost)
