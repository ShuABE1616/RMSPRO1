volatile static int _ir1;
volatile static int _ir2;
volatile static int _ir3;
volatile static int _ir4;

void takiroboF1::timerISR(void){

  static long count = 0;

  //タイマ割り込みの停止
  Timer1.detachInterrupt();

  /*一定周期ごとに関数を実行*/
  /*タイミングが重なった場合上から優先で実行される*/
  if((count % 23) == 0){//約20Hz
    takiroboF1::irUpdate();
  }
  
  else{
    /*DO NOTHING*/
  }

  count++;

  /*タイマー割り込みの再開*/
  Timer1.attachInterrupt(timerISR); 
}