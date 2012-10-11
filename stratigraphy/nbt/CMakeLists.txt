include_directories (..)

add_library(ioutils IOUtils.cpp) #.cpp needed for some odd reason

add_library(nbt NBTTagEnd
                NBTTagByte
                NBTTagCompound
                NBTTag
                NBTTree
           )
target_link_libraries (nbt boost ioutils)
