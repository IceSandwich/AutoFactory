set(target_name AutoFactory)
set(target_src "main.cpp")
set(target_libs "")
set(factories "AnimalFactory" "PersonFactory")

# 搜索Factory下的cpp文件，如果只有hpp/h文件是不会引用的，因此记得使用cpp文件写产品类。
foreach(FACTORY_NAME ${factories})
aux_source_directory(${FACTORY_NAME} FACTORY_PRODUCTS)
list(PREPEND target_src ${FACTORY_PRODUCTS})
endforeach()

add_executable (${target_name} ${target_src})
target_link_libraries(${target_name} ${target_libs})
