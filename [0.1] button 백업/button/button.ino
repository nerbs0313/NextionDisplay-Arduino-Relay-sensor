#include <Boards.h>
#include <doxygen.h>
#include <NexButton.h>
#include <NexCheckbox.h>
#include <NexConfig.h>
#include <NexCrop.h>
#include <NexDualStateButton.h>
#include <NexGauge.h>
#include <NexGpio.h>
#include <NexHardware.h>
#include <NexHotspot.h>
#include <NexNumber.h>
#include <NexObject.h>
#include <NexPage.h>
#include <NexPicture.h>
#include <NexProgressBar.h>
#include <NexRadio.h>
#include <NexRtc.h>
#include <NexScrolltext.h>
#include <NexSlider.h>
#include <NexText.h>
#include <NexTimer.h>
#include <Nextion.h>
#include <NexTouch.h>
#include <NexUpload.h>
#include <NexVariable.h>
#include <NexWaveform.h>

NexButton b0 = NexButton(0,1,"b0"); //b0가 아니라 직관적으로 무슨 버튼인지 알게. 
NexButton b1 = NexButton(0,5,"b1");
NexText t0 = NexText(0, 3, "t0");
NexText t1 = NexText(0, 4, "t1");
NexPicture p0 = NexPicture(0, 1, "p0");

NexTouch *nex_listen_list[]= {
  &b0,
  &b1,
  NULL
};

/* Reecipe Functions */

const char * getName(int recipeNum){ // 이름 불러오기

  int num = recipeNum;
  if(num == 0){
  return "overpour";
  }

  if(num == 1){
    return "dotdrip";
  }
}

int count(){
  return 2;
}

const char * getRecipe(int recipeNum){ // 레서피 불러오기

  int num = recipeNum;
  if(num == 0){
  return "p10,w30,p10,w10";
  }

  else if(num== 1){
    return "p10,w30,p3,w3,p3,w3";
  }
}

// b0 -> UserMenuOK

/* User Menu Event Handler */

void b0PopCallback(void *ptr)
{
  int recipeNum = 0;
  const char * recipeName = getName(recipeNum);
  const char * recipe = getRecipe(recipeNum);
  t0.setText(recipeName);
  t1.setText(recipe);
  digitalWrite(8,HIGH);    

}


void b1PopCallback(void *ptr)
{
  int recipeNum = 1;
  const char * recipeName = getName(recipeNum);
  const char * recipe = getRecipe(recipeNum);
  t0.setText(recipeName);
  t1.setText(recipe);
  digitalWrite(8,LOW);  
}

/* System Related  */


void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.print("baud=115200");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.end();
  Serial.begin(115200);
  pinMode(8,OUTPUT);

  b0.attachPop(b0PopCallback); /* 감명받은 해석 : pop 했을 때 collback함수를 불러라. */
  b1.attachPop(b1PopCallback);
}

void loop() {
  delay(30);
  nexLoop(nex_listen_list);

}
