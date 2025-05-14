# PyCraftr - The combination of Python and C programming language

#### PyCraftr is a custom programming language that seamlessly blends the simplicity and readability of Python with the speed and efficiency of C. Designed to offer an intuitive syntax without compromising on performance, PyCraftr empowers developers to write high-level code that compiles down to optimized machine instructions.

## Key Feature:

  1. Easy to understand: This programming language is easy to understand the concept of the programming.
  2. User-Friendly Syntax: Maintains Python's readability, reducing the learning curve.
  3. Cordinative: code shoulde be cohesive and wellstructured.
  4. User-friendly: user-feriendly keywords,opeeators and syntax.
  

# Student Information

  ### **Student Name: Maharshi Patel**  
  ### **Enrollment ID:22000394**

# Project Components: 
  1. lexer.l : flex file for lexical analysis for generating tokens for Pycraftr
  2. parser.y: definding grammer and parsing rules 
  3. lexer.yy.c: Auto generated lexer code 
  4. parser.tab.c: Auto generated parser code 
  5. compiler.exe: compiled binaries
  6. input.txt: input code of Pycraftr language
  7. intermediate.ir: intermediate code

# How to run Pycraftr language

### Compilation Instruction
To compile and execute PyCraftr programs, follow these steps:
1. Generate the parser using bison
   
   ```win_bison -d parser.y  ```
2. Generating the lexer using flex
   
    ```win_flex lexer.l```
3. Compile the generated files using GCC

   ```gcc lex.yy.c parser.tab.c -o compiler.exe```

4. Run a sample PyCraftr porgram

   ```compiler.exe```
  
5. If wanted to run Pycraftr program file (Pycraftr program file:input.txt) 

   ```compiler.exe > input.txt ```

### Example Program

``` start add x, y:
  sum = x + y
  show "The sum is"
  show sum
  give sum
end
```

### System Requirements

- GCC Compiler
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Windows/linix or complatible envioronment


### Rules of the language
####  A refernce for rules,identifiers,keyword and syntax for Pycraftr language 
[Pycraftr Language.pdf](./Pycraftr.pdf)


### Acknoledgement
- A special thanks to prof.Vaibhavi Patel for her guidance and support during this project






  


