#include "cmdline_parser.hpp"
#include "Core/Core.h"

int MainPhotoshop(Core& core);

int main(int argc, char *argv[]) {
    ParseArgs(argc, argv);

    Core core;
    return MainPhotoshop(core);
}

int MainPhotoshop(Core& core) {
    VertexArray vt(PrimitiveType::Lines, 10);
    core.Run();
    return 0;
}
