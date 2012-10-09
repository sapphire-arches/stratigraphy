include_directories (..)

add_library(nbt IOUtils
                NBTTagEnd
                NBTTagCompound
                NBTTag
                NBTTree
           )
target_link_libraries (nbt boost)
