/* Clase: SbNumLetras
 * Autor: Cetisoft@linuxmail.org
 * Version: 0.0.1
 * Fecha de creacion: 13-Julio-2004
 * Fecha de modificacion: 13-Julio-2004
*/

/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

 /*
   Autor : Fabio Andres Herrera Rozo 
   E-Mail: t763rm3n@linuxmail.org 
 */
 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "sbnumeroaletras.h"

#define MAX 100

SbNumLetras::SbNumLetras()
{
}

SbNumLetras::~SbNumLetras()
{
}

QString SbNumLetras::numeroAletrasEspanol(int revisadaPar , int gp)
{ 
     //-- casting int a QString -> QString char*  
     QString c ;
     c = QString::number(revisadaPar); 
     char* d;
     d = (char*)c.latin1();
     
     conversion = numeroAletrasES(d); //funcion principal :)
    
     if(gp==0){ conversion = conversion.lower(); }
 else  //seccion convierte UpperCase y LowerCase
     if(gp==1){ conversion = conversion.upper(); }
     
       return conversion;
}


QString SbNumLetras::numeroAletrasES(char revisada[])
{
	
        char actual[MAX] , actualposterior[MAX];
	
	char unidades[MAX][MAX]={"uno ","dos ","tres ","cuatro ","cinco ","seis ","siete ","ocho ","nueve "};
	char decenas[MAX][MAX]={"diez ","veinte ","treinta ","cuarenta ","cincuenta ","sesenta ","setenta ","ochenta ","noventa "};
	char centenas[MAX][MAX]={"ciento ","doscientos ","trescientos ","cuatrocientos ","quinientos ","seiscientos ","setecientos ","ochocientos ","novecientos "};
	char decenasespeciales[MAX][MAX]={"diez ","once ","doce ","trece ","catorce ","quince ","dieciseis ","diecisiete ","dieciocho ","diecinueve "};
        
	int longitud , numerito , numeritoposterior , i , bandera , posicionactual;
	
	longitud = strlen(revisada);
        
	for (i=longitud;i >= 1 ;i--)
	{
	     bandera = longitud - i;
	     posicionactual = longitud - bandera;

	 switch(posicionactual)
	 {
	    case 1: case 4: case 7: //unidades
	    {
	       actual[0] = revisada[bandera];actual[1] = '\0';
	       numerito = atoi(actual);
	       if (numerito != 1)
	       {
		  conversion =  conversion + unidades[numerito-1];
	       }
	else
	       { 
	         if (longitud == 4 && posicionactual == 4){}
	else 
		if(longitud == 7 && posicionactual == 7)
		 {
		    conversion = "un ";
		 }
	else
	         {
		    conversion =  conversion + unidades[numerito-1];
		 }       
				
	       } 
	           break;
	   }

	   case 2:case 5:case 8: //decenas
	   {
              actual[0] = revisada[bandera];
	      actual[1] = '\0';
	      numerito = atoi(actual);
	      actualposterior[0] = revisada[bandera+1];
	      actualposterior[1] = '\0';
	      numeritoposterior = atoi(actualposterior);
	      if (numerito == 1)
	      {
		if (numeritoposterior != 0)
		{
		  conversion =  conversion + decenasespeciales[numeritoposterior];
		  i--;
		}
	else
		{
		  conversion =  conversion + decenas[numerito-1];
		}
	      }
	else
	        {
		  conversion =  conversion + decenas[numerito-1];
		  if (numeritoposterior !=0 && numerito != 0) 
		  conversion +=  "y ";
		}
                   break;
	  }

	
	   case 3:case 6: //centenas
           {			
	      actual[0] = revisada[bandera];actual[1] = '\0';
	      numerito = atoi(actual);
	      if (posicionactual == 6 && longitud > 6)
	      {
		 if (longitud == 7 && revisada[bandera-1] == '1')
		 {
		    conversion += "millon ";
		 }
	  else
	        {
		    conversion += "millones ";
		}
	      }
	  else 
	       if (posicionactual == 3 && longitud > 3)
	       {
		  if(revisada[bandera-1] =='0' && revisada[bandera-2] == '0' && revisada[bandera-3] == '0'){}
	  else
	           {
		     conversion += "mil ";
		   }
		}
		  if(numerito == 1 && revisada[bandera+1] == '0' && revisada[bandera+2] == '0')
		  {
		     conversion += "cien ";
		  }
	  else    
	          {
		     conversion = conversion +  centenas[numerito - 1] ;
		  }
		     break;
	     }
	  }
       }
        
    
     return conversion;
} 


