#include "Button.h"

#include <Arduino.h>

using namespace s1nu5;

Button::Button(int _pin)
{
   pin = _pin;

   buttonState = false;
   lastButtonState = false;

   timeSinceLastStatusChange = 0;

   pinMode(pin, INPUT_PULLUP);
}

bool Button::GetButtonDown()
{
   return lastButtonState == false && buttonState == true;
}

bool Button::GetButton()
{
   return buttonState;
}

bool Button::GetButtonUp()
{
   return lastButtonState == true && buttonState == false;
}

void Button::UpdateButton(float deltaTime)
{
   timeSinceLastStatusChange += deltaTime;

   lastButtonState = buttonState;

   if (timeSinceLastStatusChange > 0.006)
   {
      buttonState = !digitalRead(pin);
      timeSinceLastStatusChange = 0;
   }

   if(timeSinceLastStatusChange < 0)
   {
      timeSinceLastStatusChange = 1;
   }
}