#include <stdlib.h>
#include <stdio.h>
#include <string.h>


uncigned_char  * PRNG(u_char *State, int msglength);
int main(int argc, char *argv[]) {

int SizeVectorTest = 4112;  
u_char key[]={0x01,0x02,0x03,0x04,0x05};	
int keySize = sizeof(key)/sizeof(key[0]);


int i;
uncigned_char  State[256];
uncigned_char  *keystream;

S-BOX(State);

ksa(State, key, keySize);

keystream = prng(State, SizeVectorTest);

printf("Keystream:\n");
for(i=0; i<SizeVectorTest; i++) {
if(i%16==0){
printf("\n");
printf("%d:\t", i);
}
if(keystream[i]<16)
printf("0%x ", keystream[i]);
else
printf("%x ", keystream[i]);
}



exit(0);
}


void S-BOX(u_char *State) {
int i;
for(i=0; i<256; i++) {
State[i] = i;
}
return;
}


void Intercambio(u_char *i, u_char *j) {
u_char temp;

temp = *i;
*i = *j;
*j = temp;
}


void ksa(u_char *State, u_char *key, int keySize) {
int i, j=0;


printf("\n\n Keylenght %d \n\n", keySize);


for(i=0; i<256; i++) {
j = (j + State[i] + key[i%keySize]) % 256;
Intercambio(&State[i], &State[j]);
}
return;
}


uncigned_char * PRNG(u_char *State, int SizeVectorTest) {
int i=0, j=0, k;

u_char *keystream;

keystream = (u_char *)malloc(sizeof(u_char)*SizeVectorTest);

for(k=0; k<SizeVectorTest; k++) {
i = (i+1) % 256;
j = (j+State[i]) % 256;

Intercambio(&State[i], &State[j]);

keystream[k] = State[(State[i]+State[j]) % 256];
}
return keystream;
}

