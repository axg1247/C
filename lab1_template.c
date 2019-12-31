/* 
Title: IDE Lab01  
Purpose: Use GPIO for push Button input and LED control  
Name: Amrit Gautam   
Date:08/30/2019   
*/
#include "MK64F12.h"                    // Device header

void LED_Init(void){
	// Enable clocks on Ports B and E for LED timing
	 SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	// SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	 SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	 
	// Configure the Signal Multiplexer for GPIO
   PORTB_PCR22 = PORT_PCR_MUX(1);
	 PORTE_PCR26 = PORT_PCR_MUX(1);
	 PORTB_PCR21 = PORT_PCR_MUX(1);
	
	// Switch the GPIO pins to output mode
	  GPIOB_PDDR |= (1<<22);
	  GPIOE_PDDR |= (1<<26);
	  GPIOB_PDDR |= (1<<21);

	// Turn off the LEDs
   	GPIOB_PSOR = (1UL << 21) | (1UL << 22);
		GPIOE_PSOR = 1UL << 26;
}

void Button_Init(void){
	// Enable clock for Port C PTC6 button
	 SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	
	// Configure the Mux for the button
	 PORTC_PCR6 = PORT_PCR_MUX(1);

	// Set the push button as an input
	 GPIOC_PCOR = (1 << 6);
}

void Y(void){
	    GPIOB_PTOR = (1UL << 22);
		GPIOE_PTOR =(1UL << 26);
		  
}


void R(void){
		GPIOB_PTOR = (1UL << 22);
}

void G(void){

		GPIOE_PTOR = (1UL << 26);
}

void B(void){

		GPIOB_PTOR = (1UL << 21);
}

void C(void){
		GPIOB_PTOR = (1UL << 21);
		GPIOE_PTOR = (1UL << 26);
		
}



void M(void){
	    GPIOB_PTOR = (1UL << 21);
		GPIOB_PTOR = (1UL << 22);
		
}


void W(void){
	
 		GPIOB_PTOR = (1UL << 21);
	    GPIOB_PTOR = (1UL << 22);
		GPIOE_PTOR = (1UL << 26);
		
}


 void Delay(void){
	
	for(int i = 0; i<2000000; i++){
				
			}
}



int main(void){
	//Initialize any supporting variables
	 
	int S;
	// Initialize buttons and LEDs
	
	LED_Init();
	Button_Init();
	
	for(;;){
		//Turn on an LED configuration when button is held
		if((GPIOC_PDIR & (1UL << 6)) ==0){
			S++;
			if(S==1){
				
				R();
				Delay();
				R();
				
				G();
				Delay();
				G();
				
				B();
				Delay();
				B();
				
			
			}
				else if(S==2) {
					
					C();
					Delay();
					C();
			    
					M();
					Delay();
					M();
					
					Y();
					Delay();
					Y();
					
				}
					
			else if(S==3){
					W();
					Delay();
					W();
			}
			
			else {
				
       S=0;
			}
					
		}
		// Turn off LEDs on release of button
		else{
			GPIOB_PSOR = (1UL << 21) | (1UL << 22);
			GPIOE_PSOR = 1UL << 26;
		}
	}
}
