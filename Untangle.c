#include <stdio.h>
#include <stdint.h>


void Untangle(const uint8_t* pBuffer, FILE* Log) {


uint16_t offset = *((uint16_t*) pBuffer);   // the value of the first offset
const uint8_t* begin = pBuffer;  // the space or place where the offset began
while (offset != 0) {
	
	uint8_t length = *(offset + begin);  // gets the hex length
		
	pBuffer = offset + begin;  // pBuffer pointer moves to the new offset
	
	fprintf(Log ,"%04X: ", offset);  // prints the offset

	uint8_t size = length - 3;  // gets the hex that represents the words
	uint8_t* word = (uint8_t*) pBuffer;   // word is pointing at the length of where the offset points next

	while (size > 0) { 

		word = (uint8_t*) word + 1;   // moves pointer to the hex that represents the word
		uint8_t chars = *((uint8_t*) word);   // chars gives the value of word, which was a pointer
		
		chars = chars ^ length;  // decrypting for Q2
		fprintf(Log, "%c", (char) chars);   // prints the character or words

		size--;
	}
	fprintf(Log, "\n");   

	word = word + 1;     // goes to the offset at the end of the hex for the word
	
	offset = *((uint16_t*) word);   // new offset will be the offset value to continue the cycle of finding other offsets


}
}





// On my honor:
//
// - I have not discussed the C language code in my program with
// anyone other than my instructor or the teaching assistants 
// assigned to this course.
//
// - I have not used C language code obtained from another student, 
// or any other unauthorized source, either modified or unmodified. 
//
// - If any C language code or documentation used in my program 
// was obtained from an allowed source, such as a text book or course
// notes, that has been clearly noted with a proper citation in
// the comments of my program.
//
// Christopher Aska Toda
