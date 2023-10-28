#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char* calculate(char* mes, const char* gen)
{
int m = strlen(mes);
int n = strlen(gen);
char* message = (char*) malloc((m+n) * sizeof(char));
strcpy(message, mes);
strcat(message, "00000000");
for (int i = 0; i <= m-n; i++)
{
if(message[i]!='0')
{
for (int j = 0; j < n; j++)
{
if(message[i+j] == gen[j])
message[i+j] = '0';
else
message[i+j] = '1';
}
}
}
return message+m;
}
int main()
{
char gen[] = "1011";
char mes[100];
printf("Enter message: ");
scanf("%s", mes);
char* crc = calculate(mes, gen);




char* mesWithCRC = (char*) malloc((strlen(mes)+strlen(crc)+1) * sizeof(char));
strcpy(mesWithCRC, mes);
strcat(mesWithCRC, crc);
char* rmessage = (char*) malloc((strlen(mes)+strlen(crc)+1) * sizeof(char));
strcpy(rmessage, mesWithCRC);
srand(time(0));
int modulo = strlen(mesWithCRC);
int errorIndex = rand() % modulo;
// If the original bit was a 0, it is flipped to 1; otherwise, it is flipped to 0.
if (mesWithCRC[errorIndex] == '0')
{
rmessage[errorIndex] = '1';
}
else
{
rmessage[errorIndex] = '0';
}
char* receivedMessage = (char*) malloc((strlen(mes)+1) * sizeof(char));
strncpy(receivedMessage, rmessage, strlen(mes));
receivedMessage[strlen(mes)] = '\0';
char* receivedCRC = calculate(receivedMessage, gen);
if (strcmp(receivedCRC, rmessage+strlen(mes)) == 0)
{
printf("No error detected!\n");
}
else
{
printf("Error detected.\n");
}
free(crc);
free(mesWithCRC);
free(rmessage);
free(receivedMessage);
return 0;
}
/*
Enter message: 1010
No Error detected.

Enter message: 1010
Error detected.
*/
