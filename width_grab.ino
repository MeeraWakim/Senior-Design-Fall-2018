
#include <Pixy2.h>

// This is the main Pixy object 
Pixy2 pixy;

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  
  pixy.init();
}

void loop()
{ 
  int i; 
  // grab blocks!
  pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(" center of x: ");
      Serial.println(pixy.ccc.blocks[i].m_x);
      Serial.print(" width: ");
     Serial.println(pixy.ccc.blocks[i].m_width);
   }
  }  
}
// For the fanny pack, a distance of two feet away is about 100 pixels.
