include_directories (..)

add_library(nbt NBTTagEnd
                NBTTagByte
                NBTTagShort
                NBTTagCompound
                NBTTag
                NBTTree
           )
target_link_libraries (nbt boost ioutils)
