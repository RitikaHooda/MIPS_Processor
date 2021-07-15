This is an implementation of 32-bit MIPS processor in C++. 
#### Features:
1. A set of 32 32-bit registers. 
2. Supports add, sub, sll, srl, sw, lw, beq, bne, blez, bgtz, j, jal, jr
3. 5-stage pipelining; stages are:
* Instruction Fetch (IF)
* Instruction Decode (ID)
* Execute (EX)
* Memory Access (MEM)
* Writeback (WB)
4. Data Forwarding to partially resolve hazards in R-type instructions.
5. Seperate classes for Register, ALU, data memory and instruction memory. 


