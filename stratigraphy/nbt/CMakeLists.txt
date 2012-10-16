include_directories (..)

add_library(nbt NBTTagEnd
                NBTTagByte
                NBTTagShort
                NBTTagInt
                NBTTagLong
                NBTTagFloat
                NBTTagCompound
                NBTTag
                NBTTree
           )
target_link_libraries (nbt boost ioutils)
