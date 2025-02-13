#include <iostream>
#include <vector>
#include "../entidades/consulta.hpp"
#include "../daos/daoManager.hpp"
#include "../entidades/data.hpp"

#pragma once

class FuncionarioManager
{
    DaoManager *daoManager;

public:
    FuncionarioManager(DaoManager *daoManager);

    void getFuncionario(int idFuncionario);

    void listFuncionarios();

    void listMedicosVeterinarios();

    void listImaginologistas();

};