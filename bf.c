#include <stdio.h>

int main(void) {
  FILE *in = fopen("mandlebrot.bf", "rb");
  FILE *out = fopen("mandlebrot.c", "wb");
  fputs("int putchar(int);", out);
  fputs("static int t[1024*1024]={0};", out);
  fputs("static int *p=&t[0];", out);
  fputs("int main(){", out);
  char c;
  while (fread(&c, 1, 1, in)) {
    switch (c) {
      case '+': fputs("(*p)++;", out); break;
      case '-': fputs("(*p)--;", out); break;
      case '>': fputs("p++;", out); break;
      case '<': fputs("p--;", out); break;
      case '[': fputs("while(*p){", out); break;
      case ']': fputs("}", out); break;
      case '.': fputs("putchar(*p);", out); break;
    }
  }
  fputs("}", out);
  return 0;
}
