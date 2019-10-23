/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main()
{
   // Initialization
   //--------------------------------------------------------------------------------------
   int screenWidth = 1280;
   int screenHeight = 720;

   InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
   
   int framecounter = 0;
   int contador = 0;
   int framesecond = 0;
   int segundo = 0;   
   int frameminute = 0;
   int minuto = 0;
   int framehour = 0;
   int hora = 0;
   
   bool AMPM = true;
   
   SetTargetFPS(60);
   //--------------------------------------------------------------------------------------
   // Main game loop
   while (!WindowShouldClose())    // Detect window close button or ESC key
   {
       // Update
       //----------------------------------------------------------------------------------
       // TODO: Update your variables here
       //----------------------------------------------------------------------------------
      framecounter++;
      if (framecounter == 60) {
          framecounter = 0;
          framesecond++;
      }
      if (framesecond == 60) {
          framesecond = 0;
          frameminute++;
      }
      if (frameminute == 60) {
          frameminute = 0;
          framehour++;
      }      
      if (framehour == 24) {
          framehour = 0;
      }
      // AM Y PM
      contador++;
      if (contador == 60) {
          contador = 0;
          segundo++;
      }
      if (segundo == 60) {
          segundo = 0;
          minuto++;
      }
      if (minuto == 60) {
          minuto = 0;
          hora++;
      }      
      if (hora == 12) {
          hora = 0;
          AMPM = !AMPM;
      }
      if (AMPM == false){
          DrawText("PM", 880,386,70, BLACK);
      }
      if (AMPM == true){
          DrawText("AM", 880,386,70, BLACK);
      }      
      
       // Draw
       //----------------------------------------------------------------------------------
       BeginDrawing();

           ClearBackground(RAYWHITE);
           DrawText("RELOJ 'CRONOMETRO'", 350,20,50, BLACK);
           DrawText("HORA NORMAL", 1080,206,20, BLACK);
           DrawText(FormatText("%02i", framecounter), 780, 180, 80, BLACK);
           DrawText("SEGUNDO", 670,206,20, BLACK);
           DrawText(FormatText("%02i", framesecond), 580, 180, 80, BLACK);
           
           DrawText("MINUTO", 470,206,20, BLACK);
           DrawText(FormatText("%02i", frameminute), 380, 180, 80, BLACK);
           
           DrawText("HORA", 270,206,20, BLACK);
           DrawText(FormatText("%02i", framehour), 180, 180, 80, BLACK);

           DrawText("HORA PM/AM", 1080,406,20, BLACK);
           DrawText(FormatText("%02i", contador), 780, 380, 80, BLACK);
           DrawText("SEGUNDO", 670,406,20, BLACK);
           DrawText(FormatText("%02i", segundo), 580, 380, 80, BLACK);
           
           DrawText("MINUTO", 470,406,20, BLACK);
           DrawText(FormatText("%02i", minuto), 380, 380, 80, BLACK);
           
           DrawText("HORA", 270,406,20, BLACK);
           DrawText(FormatText("%02i", hora), 180, 380, 80, BLACK);           
       EndDrawing();
       //----------------------------------------------------------------------------------
   }
   // De-Initialization
   //--------------------------------------------------------------------------------------   
   CloseWindow();        // Close window and OpenGL context
   //--------------------------------------------------------------------------------------

   return 0;
}