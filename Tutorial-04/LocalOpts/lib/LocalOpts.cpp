#include "LocalOpts.h"

#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>

using namespace llvm;

extern "C" PassPluginLibraryInfo llvmGetPassPluginInfo() 
{
  return 
  {
      .APIVersion = LLVM_PLUGIN_API_VERSION,
      .PluginName = "LocalOpts",
      .PluginVersion = LLVM_VERSION_STRING,
      .RegisterPassBuilderCallbacks = [](PassBuilder &PB) 
      { 
        // CREO LO STUB per il mio TestPass
        // 
        // RICORDA: Posso usare (coi relativi Pass Managers)
        // -------------------------------------------------
        // ModulePass
        // CallGraphSCCPass
        // FunctionPass
        // LoopPass
        // RegionPass
        // BasicBlockPass
        
        PB.registerPipelineParsingCallback( [](StringRef Name, FunctionPassManager &MPM, ArrayRef<PassBuilder::PipelineElement>) -> bool 
        {
          if (Name == "transform") 
          {
            MPM.addPass(TransformPass());
            return true;
          }

          return false;
        });
      } // RegisterPassBuilderCallbacks
  }; // struct PassPluginLibraryInfo
}
