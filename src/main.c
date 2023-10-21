#include <stdio.h>
#include <stdbool.h>

//Instruction Pointer
int ip = 0;
//Stack Pointer
int sp = -1;

// #define sp (registers[SP])
// #define ip (registers[IP])

//Stack
int stack[256];
// array of registers

bool running = true;

// define the instructions for our program
typedef enum
{
  PSH,
  ADD,
  POP,
  SET,
  HLT
} InstructionSet;

// define the registers
// NUM_OF_REGISTERS is so we can get the size of the registers
typedef enum {
  A,B,C,D,E,F, PC, SP,
  NUM_OF_REGISTERS
} Registers;
int registers[NUM_OF_REGISTERS];

// store a test program as an array
const int program[] =
{
  PSH, 5,
  PSH, 6,
  ADD,
  POP,
  HLT
};

//This function will return the current instruction when called
int fetch()
{
  return program[ip];
}

//The eval function will take a single parameter, which is the instruction to evaluate
void eval(int instr)
{
  switch (instr)
  {
  case HLT:
    { // adding braces here gives the case scope
      running = false;
      break;
    }
  case PSH:
    { // adding braces here gives the case scope
      sp++;
      stack[sp] = program[ip];
      break;
    }
  case POP:
    {
      // store the value at the stack in val_popped THEN decrement the stack ptr
      int val_popped = stack[sp--];
      // print it out!
      printf("popped %d", val_popped);
      break;
    }
  case ADD:
    {
      // first we pop the stack and store it as 'a'
      int a = stack[sp--];
      // then we pop the top of the stack and store it as 'b'
      int b = stack[sp--];
      // we then add the result and push it to the stack
      int result = b + a;
      sp++; // increment stack pointer **before**
      // set the value to the top of the stack
      stack[sp] = result;
      break;
    }
  }
};

//  The ip variable serves as an index in the array as to which instruction is currently being executed.
int main()
{
  while (running)
  {
    eval(fetch()); // if equal to false we break out of the program
    ip++;
  }
}
