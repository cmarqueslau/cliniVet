#include "encaminhamentoDao.hpp"

EncaminhamentoDao::EncaminhamentoDao()
    : funcionario1(1, "Dr. João", Data(10, 8, 2024), Data(0, 0, 0), 'A',IMAGINOLOGISTA),
      funcionario2(2, "Dra. Amanda", Data(12, 1, 2024), Data(0, 0, 0), 'A',IMAGINOLOGISTA),
      veterinario1(1, "Dr. Fabricio", Data(5, 6, 2024), Data(0, 0, 0), 'A', MEDICO,std::string("CRMV-1234")),
      veterinario2(2, "Dra. Bruna", Data(7, 9, 2024), Data(0, 0, 0), 'A',MEDICO,std::string("CRMV-5678"))
{
    encaminhamentos = {
        Encaminhamento(1, Data(15, 8, 2024), "Requisito um exame de sangue para o pet Filipo.", &funcionario1, &veterinario2),
        Encaminhamento(2, Data(20, 1, 2025), "Requisito uma ultrassonografia abdominal P.A. para a pet Amanda.", &funcionario2, &veterinario1),};
}

void EncaminhamentoDao::create(Encaminhamento encaminhamento){
    encaminhamentos.push_back(encaminhamento);
}

void EncaminhamentoDao::update(int idEncaminhamento, Encaminhamento encaminhamento){
    for (size_t i = 0; i < encaminhamentos.size(); i++)
    {
        if (encaminhamentos[i].getIdEncaminhamento()==idEncaminhamento)
        {
            encaminhamentos[i] = encaminhamento;
        }
        
    }
    
}

void EncaminhamentoDao::remove(int idEncaminhamento){

    for (size_t i = 0; i < encaminhamentos.size(); i++)
    {
        if (encaminhamentos[i].getIdEncaminhamento()==idEncaminhamento)
        {
            encaminhamentos.erase(encaminhamentos.begin()+i);
        }
        
    }
}

Encaminhamento* EncaminhamentoDao::retrieve(int idEncaminhamento){
    for (size_t i = 0; i < encaminhamentos.size(); i++)
    {
        if (encaminhamentos[i].getIdEncaminhamento()==idEncaminhamento)
        {
            return &encaminhamentos[i];
        }
        
    }
    return nullptr;
}

std::vector<Encaminhamento> EncaminhamentoDao::list(){
    return encaminhamentos;
}