#include "ButtonManager.h"

using namespace s1nu5;

void ButtonManager::AddButton(String name, Button button)
{
   Buttons.insert({name, button});
}

void ButtonManager::DeleteButton(String name)
{
   auto iterator = Buttons.find(name);
   if (iterator != Buttons.end())
   {
      Buttons.erase(iterator);
   }
}

void ButtonManager::Update(float deltaTime)
{
   for (auto &button : Buttons)
   {
      button.second.UpdateButton(deltaTime);
   }
}

bool ButtonManager::GetButtonDown(String name)
{
   auto iterator = Buttons.find(name);
   if (iterator != Buttons.end())
   {
      return iterator->second.GetButtonDown();
   }

   return false;
}

bool ButtonManager::GetButton(String name)
{
   auto iterator = Buttons.find(name);
   if (iterator != Buttons.end())
   {
      return iterator->second.GetButton();
   }

   return false;
}

bool ButtonManager::GetButtonUp(String name)
{
   auto iterator = Buttons.find(name);
   if (iterator != Buttons.end())
   {
      return iterator->second.GetButtonUp();
   }

   return false;
}
