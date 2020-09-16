#pragma once

#include <Arduino.h>
#include <map>

#include "Button.h"

namespace s1nu5
{
   class ButtonManager
   {
   private:
      std::map<String, Button> Buttons;

   public:
      void AddButton(String, Button);
      void DeleteButton(String);

      bool GetButtonDown(String buttonName);
      bool GetButton(String buttonName);
      bool GetButtonUp(String buttonName);

      void Update(float); //Should be called once per app loop.
   };
} // namespace s1nu5
