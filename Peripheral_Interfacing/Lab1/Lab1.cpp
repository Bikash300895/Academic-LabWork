#include<stdio.h>
#include<>


int main(){
	while(1){
		outport(0x378, 0x02);	//Port number followed by output in hex
		delay(2000);

		outport(0x378, 0x04);	
		delay(1000);

		outport(0x378, 0x08);	
		delay(2000);

		outport(0x378, 0x04);	
		delay(1000);
	}
}
