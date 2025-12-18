cmake_minimum_required(VERSION 3.0)

project(ThreadHoussam)

# Crée des variables avec les fichiers à compiler
set(SRCS
    main6.c
    )
    
#set(HEADERS void.h)

add_executable(main ${SRCS})
