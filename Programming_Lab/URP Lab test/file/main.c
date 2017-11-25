#include <stdio.h>

main() {
   FILE *fp;
   FILE*fp1;

   fp = fopen("input.txt", "r");
   fp1 = fopen("output.txt", "w+");

   int x;
   fscanf(fp, "%d", &x);
   fprintf(fp1, "%d",x);

   fclose(fp);
   fclose(fp1);
}
