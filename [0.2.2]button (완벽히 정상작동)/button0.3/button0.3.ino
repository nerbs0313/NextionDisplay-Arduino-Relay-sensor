#include <stdio.h>
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
/* 넥션 디스플레이의 라이브러리 함수 추가 */

int relayPin = 8; // relayPin-sensor uses 8pin
int soundPin = 7; // sound-sensor uses 7pin
int soundOn = 0; // SoundOn = 0 으로 초기화
uint32_t UserMenuMuteImg = 0; // 0 : ON Image , 9 : OFF Image
uint32_t RecipeMenuMuteImg = 2; // 2 : ON Image , 8 : OFF Image
NexButton UserMenuRecipe0 = NexButton(0,2,"b0"); // 변수초기화, UserMenu 의 레시피0 버튼 할당(page:0,id:2,name:"b0")
NexButton UserMenuRecipe1 = NexButton(0,3,"b1"); 
NexButton UserMenuRecipe2 = NexButton(0,4,"b2");
NexButton UserMenuRecipe3 = NexButton(0,5,"b3");
NexButton UserMenuSetting = NexButton(0,7,"b6");
NexPicture UserMenuMute = NexPicture(0, 8, "p0"); // 변수초기화, UserMenu 의 음소거 버튼 할당(page:0,id:2,name:"b0")
NexText RecipeMenuName = NexText(1,1,"t0");       // 변수초기화, RecipeMenu의 레시피명 텍스트 할당(page:1,id,1,name:"t0")
NexText RecipeMenuStatus = NexText(1,2,"t2");     // 변수초기화, RecipeMenu의 상태 텍스트 할당(page:1,id:2,name:"t2")
NexText RecipeMenuStep0 = NexText(1,3,"t3");      // 변수초기화, RecipeMenu의 레시피스텝0 할당(page:1,id:3,name:"t2") 
NexText RecipeMenuStep1 = NexText(1,4,"t4");
NexText RecipeMenuStep2 = NexText(1,5,"t5");
NexText RecipeMenuStep3 = NexText(1,6,"t6");
NexText RecipeMenuStep4 = NexText(1,7,"t7");
NexButton RecipeMenuCancel = NexButton(1,14,"b2");    // 변수초기화, RecipeMenu의 취소하기 버튼 할당(page:1,id:14,name:"b2")
NexButton RecipeMenuStart = NexButton(1,12,"b0");     // 변수초기화, RecipeMenu의 시작버튼 할당(page:1,id:12,name:"b0")
NexButton RecipeMenuTempStop = NexButton(1,13,"b1");  // 변수초기화, RecipeMenu의 일시정지버튼 할당(page:1,id:12,name:"b0")
NexPicture RecipeMenuMute = NexPicture(1,15,"p0");    // 변수초기화, RecipeMenu의 음소거 이미지 할당(page:1,id:15,name:"p0")
NexPage page0 = NexPage(0,0,"page0");                 // 변수초기화, page0 할당
NexPage page1 = NexPage(1,0,"page1");                 // 변수초기화, page1 할당

NexTouch *nex_listen_list[]= {
  &page0,
  &page1,
  &UserMenuRecipe0,
  &UserMenuRecipe1,
  &UserMenuRecipe2,
  &UserMenuRecipe3,
  &UserMenuMute,
  &UserMenuSetting,
  &RecipeMenuStart,
  &RecipeMenuTempStop,
  &RecipeMenuMute,
  &RecipeMenuCancel,
  NULL
};

/* Reecipe Functions */
int getList(){
  return 1;
}


// const char * 와 String.


String recipe[2] = {
  {"test 10,wait2 10,Pour 10s,wait 10s"},
  {"test2"}
};

String loadRecipe(int rid){
  if(rid == 0){
    return recipe[0];
  }
  else if(rid ==1){
    return recipe[1];
  }
}
//
//int isRecipe(char buffer[]) {
//   int p = 0;
//   while (buffer[p]) {
//      buffer[p] = toupper(buffer[p]);
//      p++;
//   }
//
//   char recipe[100][100] = { "FILTERCLEAN","WAIT","POUR" , 0};
//   int i, flag = 0;
//
//   for (i = 0; i < 32; ++i) {
//      if (strcmp(recipes[i], buffer) == 0) {
//         flag = 1;
//         break;
//      }
//   }
//
//   return flag;
//}
//
//int msg() {
//   char ch, buffer[15], operators[] = "+-*/%=";
////   FILE* fp;
//   String fp; 
//   int i, j = 0;
//
//   int p = 0; 
//   int q = 0;
//
//
////   fp = fopen("/Users/nerbs/program.txt", "r");
//   fp = loadRecipe(0);
//   if (fp == NULL) {
//      Serial.printf("error while opening the file\n");
//      getchar();
//   }
//
//   while ((ch = fgetc(fp)) != EOF) {
//     while ((ch = getc(fp)) != EOF)  
//      if (isalnum(ch)) {
//         buffer[j++] = ch;
//      }
//      else if ((ch == ' ' || ch == '\n' || ch == '\t' || ch == ',') && (j != 0)) {
//         buffer[j] = '\0';
//         j = 0;
//
//         if (isRecipe(buffer) == 1)
//            Serial.printf(buffer);
//         else
//            return 0;
//      }
//
//   }
//   getchar();
//   fclose(fp);
//
//   return 0;
//}










const char * getName(int recipeNum){ // Load RecipeName
  int num = recipeNum;
  if(num == 0){
  return "overpour";
  }
  if(num == 1){
    return "dotdrip";
  }
}

int count(){ 
  return 4;
}

/* User Menu Event Handler */

void UserMenuRecipe0PopCallback(void *ptr){ //UserMenu의 레시피0버튼 눌렸다 떼어질 때의 이벤트 핸들러.
  page1.show(); // page1 로 이동.
  int recipeNum = 0;  
  const char * recipeName = getName(recipeNum);
  RecipeMenuName.setText(recipeName); //RecipeMenu 페이지에 레시피 이름 세팅.

//    String str = loadRecipe(0);
//    int first = str.indexOf(","); // 첫번째 콤마위치
//    int second = str.indexOf(",",first+1); // 두번째 콤마 위치
//    int strlength = str.length(); // 문자열 길이
//    String str1 = str.substring(0, first); // 첫번째 토큰
//    String str2 = str.substring(first+1, second); // 두번째 토큰
//    String str3 = str.substring(second+1,strlength); // 세번째 토큰
//    Serial.println(str1);
//    Serial.println(str2);
//    Serial.println(str3);

  
  const char * recipeStep[5] = {"filterClean 10s","wait 10s","Pour 10s","Wait 10s"," "};
  RecipeMenuStep0.setText(recipeStep[0]); // RecipeMenuStep 0 ~ 4 에 레시피 과정 세팅.
  RecipeMenuStep1.setText(recipeStep[1]);
  RecipeMenuStep2.setText(recipeStep[2]);
  RecipeMenuStep3.setText(recipeStep[3]);
  RecipeMenuStep4.setText(recipeStep[4]);
  RecipeMenuMute.setPic(RecipeMenuMuteImg); // RecipeMenu의 음소거 버튼에 이미지 세팅.
  setSound();                               // Sound 출력.(음소거일 때에는 출력X)
}


void UserMenuRecipe1PopCallback(void *ptr){ //UserMenu의 레시피1버튼 눌렸다 떼어질 때의 이벤트 핸들러.
  page1.show();
  int recipeNum = 1;
  const char * recipeName = getName(recipeNum);
  RecipeMenuName.setText(recipeName);
  
//  const char * recipeStep[5] = {"Test 10s","wait 10s","Pour 3s","wait 3s","Pour 3s"};
    const char * recipeStep1 = {"aa"};
    const char * recipeStep2 = {"bb"};
    const char * recipeStep3 = {"cc"};
    const char * recipeStep4 = {"dd"};
    
    String str = loadRecipe(0);
    int first = str.indexOf(","); // 첫번째 콤마위치
    int second = str.indexOf(",",first+1); // 두번째 콤마 위치
    int third = str.indexOf(",",second+1); // 두번째 콤마 위치
    int strlength = str.length(); // 문자열 길이
    String str1 = str.substring(0, first); // 첫번째 토큰
    String str2 = str.substring(first+1, second); // 두번째 토큰
    String str3 = str.substring(second+1,third); // 세번째 토큰
    String str4 = str.substring(third+1,strlength);
    str1.toCharArray(recipeStep1, str1.length());
    str2.toCharArray(recipeStep2, str2.length());
    str3.toCharArray(recipeStep3, str3.length());
    str4.toCharArray(recipeStep4, str4.length());
//    Serial.println(str1);
//    Serial.println(str2);
//    Serial.println(str3);
//    Serial.println(str4);
  
  
  
  RecipeMenuStep0.setText(recipeStep1);
  delay(1000);
  RecipeMenuStep1.setText(recipeStep2);
   delay(1000);
  RecipeMenuStep2.setText(recipeStep3);
  delay(1000);
  RecipeMenuStep3.setText(recipeStep4);
  RecipeMenuMute.setPic(RecipeMenuMuteImg);
  setSound();
}

void UserMenuMuteCallback(void *ptr){ //UserMenu의 음소거 버튼이 눌렸다 떼어졌을 때의 이벤트 핸들러.
   UserMenuMute.getPic(&UserMenuMuteImg); // 음소거ON 이미지ID : 0,2 음소거OFF 이미지ID : 8,9
   if (UserMenuMuteImg == 0){
        UserMenuMuteImg = 9;          
        RecipeMenuMuteImg = 8;  
        soundOn = 1;
    }
    else{
        UserMenuMuteImg = 0;
        RecipeMenuMuteImg = 2;
        soundOn = 0;
    }
    UserMenuMute.setPic(UserMenuMuteImg); //UserMenu의 음소거 버튼에 이미지 세팅.
}

/* Recipe Menu Event Handler */

void RecipeMenuStartPopcallback(void *ptr){ //RecipeMenu의 시작버튼이 눌렸을 때의 이벤트 핸들러.
  digitalWrite(relayPin,LOW);               //relayPin : LOW
  RecipeMenuStatus.setText("Proceed");      //RecipeMenu의 상태창 "Proceed" 로 세팅
  setSound();
}


void RecipeMenuTempStopPopcallback(void *ptr){//RecipeMenu의 일시정지버튼이 눌렸을 때의 이벤트 핸들러.
  digitalWrite(relayPin,HIGH);               //relayPin : HIGH
  RecipeMenuStatus.setText("Stop");          //RecipeMenu의 상태창 "Stop" 로 세팅
  setSound();
}

void RecipeMenuMuteCallback(void *ptr){ //RecipeMenu의 음소거 버튼이 눌려졌다 떼어질 때의 이벤트 핸들러.
  RecipeMenuMute.getPic(&RecipeMenuMuteImg);
   if (RecipeMenuMuteImg == 2){ 
        UserMenuMuteImg = 9; 
        RecipeMenuMuteImg = 8;      
        soundOn = 1;
    }
    else{
        UserMenuMuteImg = 0;
        RecipeMenuMuteImg = 2;
        soundOn = 0;
    }
    RecipeMenuMute.setPic(RecipeMenuMuteImg);
}

void RecipeMenuCancelCallback(void *ptr){ //RecipeMenu의 취소하기 버튼이 눌렸다 떼어질 때의 이벤트 핸들러.
  page0.show();                           //page0으로 이동.
  UserMenuMute.setPic(UserMenuMuteImg);   //UserMenu의 음소거버튼 이미지 세팅.
  setSound();
}

/* System Related  */

void setup() {
  Serial.begin(9600);
  delay(500);
//  for(int i = 0; i < 2; i++){
//    Serial.print(recipe[i]);
//  }

  
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.end();
  Serial.begin(115200);
  
  /*출력 핀 설정*/
  pinMode(relayPin,OUTPUT);
  pinMode(soundPin,OUTPUT);
  
  /*버튼이 눌렸다 떼어지는 이벤트가 발생했을 때 인자의 콜백함수 실행*/

  UserMenuRecipe0.attachPop(UserMenuRecipe0PopCallback); 
  UserMenuRecipe1.attachPop(UserMenuRecipe1PopCallback);
  RecipeMenuStart.attachPop(RecipeMenuStartPopcallback);
  RecipeMenuTempStop.attachPop(RecipeMenuTempStopPopcallback);
  UserMenuMute.attachPop(UserMenuMuteCallback);
  RecipeMenuMute.attachPop(RecipeMenuMuteCallback);
  RecipeMenuCancel.attachPop(RecipeMenuCancelCallback);
}

void loop() {
  delay(30);
  nexLoop(nex_listen_list);
}

void setSound(){ // sound setting.
  if(soundOn == 1){
      tone(soundPin,400,100);
  }
}
