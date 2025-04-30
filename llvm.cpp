
#include <iostream>
#include <string>
#include <vector>
#include "llvm/ADT/SmallVector.h"
#include "llvm/Analysis/CFGPrinter.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

static cl::opt<std::string> InputFilename(cl::Positional, cl::desc("<input file>"), cl::Required);

int main(int argc, char** argv) {
    LLVMContext context;
    SMDiagnostic error;

    // Parse the input file into a module
    std::unique_ptr<Module> module = parseIRFile(InputFilename, error, context);
    if (!module) {
        error.print(argv[0], errs());
        return 1;
    }

    // Generate the control flow graph for the main function
    Function* mainFunc = module->getFunction("main");
    if (!mainFunc) {
        errs() << "Error: main function not found in module.\n";
        return 1;
    }

    std::vector<BasicBlock*> blocks;
    for (auto& basicBlock : *mainFunc) {
        blocks.push_back(&basicBlock);
    }

    errs() << "Generating control flow graph for main function...\n";
    ViewGraph(blocks);
    return 0;
}
