#pragma once

#include <Time.h>

namespace s1nu5
{
   class Button
   {
      int pin;

      bool buttonState;
      bool lastButtonState;

      float timeSinceLastStatusChange;

   public:
      Button(int _pin);

      bool GetButtonDown();
      bool GetButton();
      bool GetButtonUp();

      void UpdateButton(float deltaTime);
   };
} // namespace s1nu5