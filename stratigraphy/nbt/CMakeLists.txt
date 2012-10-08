include_directories (..)

add_library(nbt IOUtils
                NBTTagCompound
                NBTTag
                NBTTree
           )
target_link_libraries (nbt boost)
