// #define ADD_INPUT(inputname) top->inputname = atoi(argv[2*curr_cycle+offset]); offset++;
#define ADD_PRINT_PORT(portname, fmt) VL_PRINTF(" [" #portname "= %" fmt "]", top->portname); 

#define ADD_PRINT_SMO(portname, fmt) VL_PRINTF("(_ bv%" fmt " 32) ", top->portname);

#define CYCLE_CNT 1 

// #define SMO
// Prints the 3 pipelined PCs, as well as t0-t2 (x5-x7) and t3 (x28)
// #define ADD_SMO_PRINTING_STMTS \
    // ADD_PRINT_SMO(Tile__DOT__core__DOT__dpath__DOT__pc, "lu") \
    // ADD_PRINT_SMO(Tile__DOT__core__DOT__dpath__DOT__fe_pc, "lu") \
    // ADD_PRINT_SMO(Tile__DOT__core__DOT__dpath__DOT__ew_pc, "lu") \
    // ADD_PRINT_SMO(Tile__DOT__core__DOT__dpath__DOT__regFile__DOT__regs[5], "d") \
    // ADD_PRINT_SMO(Tile__DOT__core__DOT__dpath__DOT__regFile__DOT__regs[6], "d") \
    // ADD_PRINT_SMO(Tile__DOT__core__DOT__dpath__DOT__regFile__DOT__regs[7], "d") \
    // ADD_PRINT_SMO(Tile__DOT__core__DOT__dpath__DOT__regFile__DOT__regs[28], "d")

// // Configure inputs
// #define ADD_SET_INPUTS \
//     ADD_INPUT(io_A) \
//     ADD_INPUT(io_B) \
//     ADD_INPUT(io_alu_op)

// Configure DEBUGPRINT
// #define ADD_DEBUG_PRINTING_STMTS \
//     ADD_PRINT_PORT(Tile__DOT__core__DOT__dpath__DOT__pc, "lx") \
//     ADD_PRINT_PORT(Tile__DOT__core__DOT__dpath__DOT__fe_pc, "lx") \
//     ADD_PRINT_PORT(Tile__DOT__core__DOT__dpath__DOT__ew_pc, "lx") \
//     printf("\n");
