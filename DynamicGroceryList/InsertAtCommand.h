#ifndef INSERTATCOMMAND_H
#define INSERTATCOMMAND_H

#include <string>
#include <vector>
#include "UndoCommand.h"

class InsertAtCommand : public UndoCommand {
private:
   std::vector<std::string>* sourceVector;
   int insertIndex;
   std::string insertValue;

public:
   InsertAtCommand(std::vector<std::string>* vector, int index, const std::string& value)
        : sourceVector(vector), insertIndex(index), insertValue(value) {}
    
   void Execute() override {
      sourceVector->insert(sourceVector->begin() + insertIndex, insertValue);
   }
};

#endif
