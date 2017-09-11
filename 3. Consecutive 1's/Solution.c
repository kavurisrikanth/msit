/*
  Convert a number n to binary, and then print all binary numbers below n with the
   maximum consecutive 1s.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* to_binary(long long int);
long long int to_decimal(char *num);

int main(void) {

  long long int num = 0, other_num_one = 0, other_num_two = 0;
  scanf("%lld", &num);

  if(num > 0) {

    char *binary = to_binary(num),
         *temp;

    int i = 0;

    // printf("%lld\n", num);
    // printf("%s\n", binary);
    // printf("%d\n", log(num));

    if(num > 1) {
      // If the number is less than or equal to 1, there are no (positive) binary numbers
      // less than it that have 1s.

      /*
        There can only be 2 possibilities when the binary number has more than 1 digit.
        1. The last digit of the number is 0, and the rest are 1.
        2. The first digit of the number is 0, and the rest are 1.

        So check if any of these are already the given number.
        Alternatively, just convert those 2 cases to decimal, and only print the one
        that's definitely less than the given number.
      */
      temp = (char*)calloc(1, (1 + strlen(binary)) * sizeof(char));

      // Case 1
      for(i = 0; i < strlen(binary) - 1; i++)
        *(temp + i) = '1';
      *(temp + i) = '0';
      *(temp + i + 1) = '\0';

      // printf("temp:%s\n", temp);

      other_num_one = to_decimal(temp);
      if(other_num_one < num)
        printf("%lld\n", other_num_one);

      // Case 2
      *(temp + i) = '1'; // Since i is undisturbed since the loop
      *(temp) = '0';

      // printf("temp:%s\n", temp);

      other_num_two = to_decimal(temp);
      if((other_num_two < num) && (other_num_two != other_num_one))
        printf("%lld\n", other_num_two);
    }

    free(binary);
    free(temp);
  } else {
    // Corner case
    printf("0\n");
  }
  return 0;
}


char* to_binary(long long int num) {
  // Converts a decimal number to binary
  int digit = 0, i = 0, j = 0;
  char *ans = (char*)calloc(1, 256 * sizeof(char)),
       *ret;
  while(num > 0) {
    // printf("num: %lld\n", num);
    digit = num % 2;
    *(ans + i) = ((char)(digit + (int)'0'));
    i++;
    num /= 2;
  }
  *(ans + i) = '\0';

  ret = (char*)calloc(1, (1 + strlen(ans)) * sizeof(char));

  for(i = strlen(ans) - 1; i >= 0; i--) {
    *(ret + j) = *(ans + i);
    j++;
  }
  *(ret + j) = '\0';

  free(ans);
  return ret;
}


long long int to_decimal(char *num) {
  // Converts a binary number to decimal
  int i = 0, len = strlen(num), pos = 0;
  long long int ans = 0, digit = 0;

  for(i = len - 1; i >= 0; i--) {
    digit = *(num + i) - '0';
    ans += digit * (long long int)pow(2, pos);
    pos++;
  }

  // printf("%s = %lld\n", num, ans);
  return ans;
}
