cmake_minimum_required(VERSION 3.24)
project(Lab_2_Gestiune_cont_bancar_ C)

set(CMAKE_C_STANDARD 17)

add_executable(Lab_2_Gestiune_cont_bancar_ main.c Infrastructura/domain.c Infrastructura/repo.c Service/service.c Teste/teste.c UI/ui.c Validation/valid.c)
