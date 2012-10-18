include_directories (..)

add_library(nbt NBTTag
                NBTTagEnd
                NBTTagByte
                NBTTagShort
                NBTTagInt
                NBTTagLong
                NBTTagFloat
                NBTTagCompound
                NBTTree
           )
target_link_libraries (nbt boost ioutils)
