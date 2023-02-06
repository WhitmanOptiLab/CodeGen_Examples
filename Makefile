

all: gcc

clang:
	clang -O3 -fno-vectorize -S codegen_examples.c -o codegen_examples_clang.s

gcc:
	gcc -O3 -fno-tree-loop-vectorize -S codegen_examples.c
