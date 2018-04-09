#include "instruction.h"

//Size 19
std::string const Instruction::INSTRUCTION_LIST[] =
{"LDV", "LDC", "HALT", "CALL", "RET", "ADD", "SUB", "MUL", "DIV", "GT",
 "GE", "LT", "LE", "EQ", "NEQ", "JMP", "JZ", "ASN", "DUP"};

Instruction::Instruction(std::string command, std::vector<std::string> opStrList){
    this->command = command;
    this->opStrList = opStrList;
    //Finding commandIndex in INSTRUCTION_LIST
    auto res = std::find(INSTRUCTION_LIST, INSTRUCTION_LIST + 19, command);
    if(res != INSTRUCTION_LIST + 19){
        this->commandIndex = res - INSTRUCTION_LIST;
    }else{
        this->commandIndex = -1;
        std::cerr << "Error when initial instruction: " << command << std::endl;
    }

    std::cout << command << " ";
    for(int i = 0; i < opStrList.size(); i++){
        std::cout << opStrList[i] << " ";
    }std::cout << std::endl;
}

int Instruction::getCommandIndex(){
    return this->commandIndex;
}

std::vector<std::string> Instruction::getOpStrList(){
    return this->opStrList;
}