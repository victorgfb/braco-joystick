/*
*  Projeto:		Calibrar JoyStick
*
*  Objetivo:	Encontrar regia�o de inconsist�ncia nas leituras dos zeros de JoySticks
*
*  Obs.:
*
*  Autor:		Lucas Dami�o  - Estudante de Eng. El�trica - UNIVASF
*
*  Criado:		08/11/17      Mod.: dd/mm/aa
*
*/

/* --- Bibliotecas --- */
#include <Arm.h>

/* --- Defini��es --- */


/* --- Classes --- */

/* --- Fun��es Adicionais --- */

/* --- Objetos --- */
Arm braco;

/* --- Vari�veis Globais --- */
const byte	numServos = 6,
			joysticks[] = { A0, A1, A2, A3, A4, A5 },
			hand = 5;
     
int   pinServos[] = { 3, 5, 6, 9, 10, 11 },
      zeros[] = { 10, 20, 20, 20, 20, 20 };
      



void setup()
{
	Serial.begin(9600);
	braco.config(pinServos, numServos, zeros, hand);
  braco.invertServo(1); 
}

void loop()
{
	braco.Run(3);
	
	for (int i = 0; i < numServos; i++)
		Serial.print(String(braco.getPosicao(i)) + "\t");
	Serial.println();
	delay(60);
}
