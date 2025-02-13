#include "exameDao.hpp"

ExameDao::ExameDao() {
    animal2 = new Animal(5, "Betinho", Data(10, 8, 2024), 'M');
    animal5 = new Animal(6, "Marcelo", Data(12, 1, 2024), 'M');

    funcionario1 = new Funcionario(1, Data(10, 8, 2024), Data(0, 0, 0), 'A');
    funcionario2 = new Funcionario(2, Data(12, 1, 2024), Data(0, 0, 0), 'A');

    veterinario1 = new Veterinario(1,  Data(5, 6, 2024), Data(0, 0, 0), 'A', "CRMV-1234");
    veterinario2 = new Veterinario(2,  Data(7, 9, 2024), Data(0, 0, 0), 'A', "CRMV-5678");

    encaminhamento432 = new Encaminhamento(1, Data(5, 6, 2024), "Encaminhamento para exame de sangue.", funcionario1, veterinario1);
    encaminhamento440 = new Encaminhamento(2, Data(7, 9, 2024), "Encaminhamento para radiografia.", funcionario2, veterinario2);

    exames = {
        Exame(1, Data(15, 8, 2024), animal2, encaminhamento432, "Hemograma completo", 'F'),
        Exame(2, Data(20, 1, 2025), animal5, encaminhamento440, "Radiografia de tórax", 'F')
    };
}

void ExameDao::create(Exame exame){
    exames.push_back(exame);
}

void ExameDao::update(int idExame, Exame exame){
    for (int i = 0; i < exames.size(); i++){
        if (exames[i].getIdExame()==idExame){
            exames[i] = exame;
        }
    }
}

void ExameDao::remove(int idExame){
    for (int i = 0; i < exames.size(); i++){
        if (exames[i].getIdExame()==idExame){
            exames.erase(exames.begin()+i);
        }
    }
}

Exame ExameDao::retrieve(int idExame){
    for (int i = 0; i < exames.size(); i++){
        if (exames[i].getIdExame()==idExame){
            return exames[i];
        }
    }
}

std::vector<Exame> ExameDao::list(){
    return exames;
}