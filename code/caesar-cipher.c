#include <stdio.h>
#include <string.h>

/* This is still a work in progress, but the functionality is more or less there.  

Implements a Caesar cipher, both encrypting and decrypting. The key is an integer. This cipher performs its encryption by replacing 
each character in the message by 'shifting' the ASCII value of the character up by a given number of places (the key). i.e. key 2 
encrypts "HI" to "JK". Shifting down is also possible, but this program implements an upward shift. To do: Implement negative shift Caesar cipher */

/* ENCRYPTION */
    
int encrypt(int shift, int size, char string1[]){
    
    // Make new integer array of the same size as original string
    int int_array[size];
    
    /* Loop to convert the characters of string into their ASCII integer value */
    int a;
    
    for (a=0; a<=size; a++){
        // Print the character
         printf("Character: %c\n", string1[a]);
         // Typecast the current character to int
         int char_to_int;
         if(string1[a]!=' '){
         char_to_int = (int)string1[a];
         }
         else{
             // Note that 255 is the ASCII value for a non-breaking space
             // Or is it 160????
             char_to_int = 255;
         }
         // Print the integer value of the char
         printf("ASCII value: %d \n", char_to_int);
         // Put the integer value of the character into the int array
         int_array[a] = char_to_int;
    }
    
    
     /* Print the integers in the array */
    int j;
    
    for (j = 0; j < size; j++ ) {
      printf("Before shift: Element[%d] = %d\n", j, int_array[j] );
    }
    
     /* Shift the integers in the array up by a given number */
     
    for (j = 0; j < size; j++ ) {
        // Temp holder for the integer
        int k = int_array[j];
        // Skip the shift step if there is a space
       if(k==255){
           continue;
       }

	/* Loop around if you are at the end of the alphabet
	Uppercase Z
	if(k==90){
       	k = 65 + shift;
       	}
	Lowercase z
	else if(k==122){
           k = 97 + shift;
      	} */

	/* Loop around if you are at the start of the alphabet in the case 
	of downward shift (not implemented yet) */
       
	// Otherwise, perform the shift
	// put else statement
        k = k + shift;

        // Place the new int value back into the array
        int_array[j] = k;
        
    }
    
     /* Print the integers in the array again after the shift */
    for (j = 0; j < size; j++ ) {
      printf("After shift: Element[%d] = %d\n", j, int_array[j] );
    }
    
    // Loop to convert the ASCII integer values back into characters

    for (a=0; a<size; a++){
         // Typecast the current int to a char
         int int_to_char = (char)int_array[a];
         // Put the integer value of the character into the char array
         string1[a] = int_to_char;
    }
    
    printf("The encrypted message is: \n");
     /* Print the characters in the array after the shift */
    for (j = 0; j < size; j++ ) {
      //printf("Element[%d] = %c\n", j, string1[j] );
      printf("%c", string1[j] );
    }
    
    return 0;
}

 /*  DECRYPTION  */
 
int decrypt(int shift, int size, char string1[]){

    /* To decrypt, simply change the shift function from k = k + shift to k = k - shift, or vice versa */
    /* i.e. Shift the integers in the array back DOWN by a given number */
   
   // Make new integer array of the same size as original string
    int int_array[size];
    
    /* Loop to convert the characters of string into their ASCII integer value */
    int a;
    
    for (a=0; a<=size; a++){
        // Print the character
         //printf("Character: %c\n", string1[a]);
         // Typecast the current character to int
         int char_to_int;
         
        char_to_int = (int)string1[a];
         
         // Print the integer value of the char
         //printf("ASCII value: %d \n", char_to_int);
         // Put the integer value of the character into the int array
         
         int_array[a] = char_to_int;
    }

    /* Loop to shift the integers back to their original values */
    int j;
    
    for (j = 0; j < size; j++ ) {
        // Temp holder for the integer
        int k = int_array[j];
        // shift numbers by given value
        k = k - shift;
        // Place the new int value back into the array
        int_array[j] = k;
    }
    
    /* Loop to convert the ASCII integer values back into characters */

    for (a = 0; a < size; a++){
         
        // Typecast the current int to a char
         int int_to_char = (char)int_array[a];
         // Put the integer value of the character into the char array
         string1[a] = int_to_char;
        
         
    }
    
    printf("The decrypted message is: \n");
     /* Print the characters in the array after the shift */
    
    for (j = 0; j < size; j++ ) {
      printf("%c", string1[j]);
    }
    
    return 0;
}

/* MAIN METHOD AND INITIALIZATION */
    
int main()
{
    /* Create string */
    char string1[] = "HELLO THIS IS A TEST";
    
    /* Shift value, i.e. the key */
    int shift = 3;
    
    /* Get length of string */
    int size = strlen(string1);
    
    encrypt(shift, size, string1);
    decrypt(shift, size, string1);
    
    
    return 0;
}
