# mytest
PROJECT(mytest)

add_definitions("-Wall -lpthread -g")

# head file path
INCLUDE_DIRECTORIES( include )

# source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

# set environment variable
SET(mytest ${DIR_SRCS})


# set extern libraries
SET(LIBRARIES "./lib/*.so")

# set output binary path
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


#add executable file  
ADD_EXECUTABLE(mymake ${mytest})

#add link library  
TARGET_LINK_LIBRARIES(mymake ${LIBRARIES})
