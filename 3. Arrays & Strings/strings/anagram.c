#include <stdio.h>
#include <string.h>

int main (void) {
	char s1[14],s2[14];
	printf("enter string1: ");
	scanf("%s",s1);
	printf("enter string2: ");
	scanf("%s",s2);
   char temp;

   int i, j;
   int n  = strlen(s1);
   int n1 = strlen(s2);

   // If both strings are of different length, then they are not anagrams

   if( n != n1) {    
      printf("%s and %s are not anagrams! \n", s1, s2);
      return 0;
   }
   
   // lets sort both strings first −

   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (s1[i] > s1[j]) {
            temp  = s1[i];
            s1[i] = s1[j];
            s1[j] = temp;
         }
         if (s2[i] > s2[j]) {
            temp  = s2[i];
            s2[i] = s2[j];
            s2[j] = temp;
         }
      }
   }

   // Compare both strings character by character

   for(i = 0; i<n; i++) {
      if(s1[i] != s2[i]) {    
         printf("Strings are not anagrams! \n", s1, s2);
         return 0;
      }
   }

   printf("Strings are anagrams! \n");
   return 0;
}
