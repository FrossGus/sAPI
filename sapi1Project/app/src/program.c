/*============================================================================
 * Licencia: 
 * Autor: 
 * Fecha: 
 *===========================================================================*/

/*==================[inlcusiones]============================================*/

//#include "program.h"   // <= su propio archivo de cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI

//#include "c_i18n_es.h" // <= para traducir el codigo C al espa�ol (opcional)
//#include "c_i18n_es.h" // <= para traducir la sAPI al espa�ol (opcional)

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

CONSOLE_PRINT_ENABLE

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[declaraciones de funciones externas]====================*/

/*==================[funcion principal]======================================*/

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void ){

   // ---------- CONFIGURACIONES ------------------------------
   
   // Inicializar y configurar la plataforma
   boardInit();
   
   // Inicializar UART_USB como salida de consola
   consolePrintConfigUart( UART_USB, 115200 );
   
   // Crear varias variables del tipo booleano
   bool_t tec1Value = OFF;
   bool_t tec2Value = OFF;
   bool_t tec3Value = OFF;
   bool_t tec4Value = OFF;
   bool_t ledbValue = OFF;
   
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE )
   {      
      /* Si se presiona TEC1, enciende el LEDR */
      
      // Leer pin conectado a la tecla.
      tec1Value = gpioRead( TEC1 );
      // Invertir el valor leido, pues lee un 0 (OFF) con tecla 
      // presionada y 1 (ON) al liberarla.
      tec1Value = !tec1Value;
      // Escribir el valor leido en el LED correspondiente.
      gpioWrite( LEDR, tec1Value );
      
      
      /* Si se presiona TEC2, enciende el LED1 */ 
      
      // Leer pin conectado a la tecla.
      tec2Value = gpioRead( TEC2 );
      // Invertir el valor leido, pues lee un 0 (OFF) con tecla 
      // presionada y 1 (ON) al liberarla.
      tec2Value = !tec2Value;
      // Escribir el valor leido en el LED correspondiente.
      gpioWrite( LED1, tec2Value );
      
      
      /* Si se presiona TEC3, enciende el LED2 */
      
      // Leer pin conectado a la tecla.
      tec3Value = gpioRead( TEC3 );
      // Invertir el valor leido, pues lee un 0 (OFF) con tecla 
      // presionada y 1 (ON) al liberarla.
      tec3Value = !tec3Value;
      // Escribir el valor leido en el LED correspondiente.
      gpioWrite( LED2, tec3Value );
      
      
      /* Si se presiona TEC4, enciende el LED3 */
      
      // Leer pin conectado a la tecla.
      tec4Value = gpioRead( TEC4 );
      // Invertir el valor leido, pues lee un 0 (OFF) con tecla 
      // presionada y 1 (ON) al liberarla.
      tec4Value = !tec4Value;
      // Escribir el valor leido en el LED correspondiente.
      gpioWrite( LED3, tec4Value );


      /* Intercambiar el valor del pin conectado a LEDB */
      
      gpioOutputToggle( LEDB );
      
      
      /* Mostrar por UART_USB (8N1 115200) el estado del LEDB */
      
      // Leer el estado del pin conectado al led
      ledbValue = gpioRead( LEDB );
      // Chequear si el valor leido es encedido
      if( ledbValue == ON ){
         // Si esta encendido mostrar por UART_USB "LEDB encendido."
         consolePrintlnString( "LEDB encendido." );
      } else{
         // Si esta apagado mostrar por UART_USB "LEDB apagado."
         consolePrintlnString( "LEDB apagado." );      
      }      
      
      
      /* Retardo bloqueante durante 250ms */
      
      delay( 250 );
   } 

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta 
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/