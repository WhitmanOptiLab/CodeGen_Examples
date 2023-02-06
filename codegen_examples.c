/*Concepts to cover*/

//Loop unrolling
//Common subexpression elimination
//Loop invariant removal
//Polynomial evaluation

//Parameters
//Aliasing (and the restrict keyword)

int strength_reduction1(int x) {
  return x*16;
}

int strength_reduction2(int x) {
  return x*5;
}

void strength_reduction_loop(int array[], int len, int scale) {
  for (int i = 0; i < len; i++) {
    array[i] = i*scale;
  }
}

int strength_reduction_cond(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

//Forward declarations for functions defined elsewhere
int a_function(int x);
int another_function(int x);

int cse1(int x, int y) {
  return a_function(x+y*3) + another_function(y*3-x);
}

//What gets moved out of the loop? What doesn't?
void doAll(int array[], int len, int x) {
  for (int i = 0; i < len; i++) {
    array[i] = a_function(x*5);
  }
}

//What happened to the loop?
//How many multiply instructions are there?
//Could you do better?
void cross_outer(float a[3], float b[3], float cross[3], float outer[3][3]) {
  cross[0] = a[1]*b[2] - a[2]*b[1];
  cross[1] = a[2]*b[0] - a[0]*b[2];
  cross[2] = a[0]*b[1] - a[1]*b[0];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      outer[i][j] = a[i]*b[j];
    }
  }
}

//Compare gcc and clang on this one. What do you notice?
int polynomial(int coeff[], int len, int x) {
  int result = 0;
  for (int n = 0, x_n = 1; n < len; n++, x_n *= x) {
    result += coeff[n] * x_n;
  }
  return result;
}

int algebraic_simplification1(int x) {
  return (x*10 + 5)*(x*5 + 2);
}

int algebraic_simplification2(int x, int y) {
  if (x+y > x) {
    return 1;
  } else {
    return 0;
  }
}

//What do you think the best assembly should be?
int use_and_return_a(int* a, int* b) {
  *b = *a + 1;
  return *a;
}


