# これは教育用ロボットRMSPRO用のライブラリです。
このライブラリを使うことで、RMSPROを簡単に動かすことができるようになります。  
また、このライブラリにはbeginnerとadvanceの２つのレベルに分けています。  
違いとしては、単にライブラリの関数名が短くなっただけで、ライブラリの中の動作は一緒です。  

タイピングができる人はadvancedを選ぶことをお勧めします。

後から見た時に何やってるかわかりやすいと思います。  　　

このREADMEでは関数、スケッチ例、その他必要事項について書いていきます。　　
　　
## 関数説明
### 共通
***これらは記述しないと、ライブラリが正常に動きません。***
1. `#include<RMSPRO.h>`
    - ライブラリに含まれるヘッダファイルを呼び出します。**setup()より上に配置してください。**
  

1. `RMSPRO x;`
    - ライブラリを使うのに必須です。xは任意の名前で自由に変更できます。
    - **サンプルではxはrとなっています。ライブラリの関数を使う前に必ず入れる**ので短い方がいいと思ってます。
    - **setup()より上に配置してください。**   
  

1. `x.init();`
   - ピン、シリアルポートなどの初期化を行います。**setup()内に記述してください。**

    
### beginnerモード
1. x.bt();
    - スタートボタン（オルタネートスイッチ）の状態の値を返します。
    - HIGH,LOWまたは0,1で返ってきます。

1. x.l();
    - ラインセンサの値を取得します。
    - 数字が小さくなると白です。
    - しきい値は個体差があるのでセンサモニターでモニターでそれぞれしきい値を探して下さい

1. x.b();
    - 赤外線センサの値を返します。取得したい赤外線センサの名前を入力してください。
    - 赤外線センサの名前は
    - センサー番号によるもの`b(d1),b(d2),b(d3),b(d4)`
    - センサー方向によるもの`b(fr),b(ri),b(ba),b(le)`
    - がそれぞれ割り振られています。必要に応じて使い分けてください。
    - 方向が正しくセンサーで読み取れていない場合、配線が間違っている可能性があります。

1. x.m(left,right);
    - ２輪モーターの制御を行います。
    - left,rightはそれぞれ左右のモーターのスピードを表しています。
    - -255〜255までの値が有効です。マイナスは反対方向に回ります。

1. x.srmo()
    - センサモニターをします。
    - arduinoIDE右上のシリアルモニタにセンサーの値を返します。
    - センサーの調子を見たり、しきい値を決める時に使ってください。
    - `Serial.println(センサ名)`でセンサの値を見ることもできます。

### advancedモード

1. x.btn();
    - スタートボタン（オルタネートスイッチ）の状態の値を返します。
    - HIGH,LOWまたは0,1で返ってきます。

1. x.line();
    - ラインセンサの値を取得します。
    - 数字が小さくなると白です。
    - しきい値は個体差があるのでセンサモニターでモニターでそれぞれしきい値を探して下さい

1. x.ball();
    - 赤外線センサの値を返します。取得したい赤外線センサの名前を入力してください。
    - 赤外線センサの名前は
    - センサー番号によるもの`b(d1),b(d2),b(d3),b(d4)`
    - センサー方向によるもの`b(front),b(right),b(back),b(left)`
    - がそれぞれ割り振られています。必要に応じて使い分けてください。
    - 方向が正しくセンサーで読み取れていない場合、配線が間違っている可能性があります。

1. x.m(left,right);
    - ２輪モーターの制御を行います。
    - left,rightはそれぞれ左右のモーターのスピードを表しています。
    - -255〜255までの値が有効です。マイナスは反対方向に回ります。

1. x.srmo()
    - センサモニターをします。
    - arduinoIDE右上のシリアルモニタにセンサーの値を返します。
    - センサーの調子を見たり、しきい値を決める時に使ってください。
    - `Serial.println(センサ名)`でセンサの値を見ることもできます。


## exampleプログラム(スケッチ例)について
関数同様、beginnerとadvanceがありますが、beginnerはadvanceを省略しただけです。  
自分のレベルに合わせて使い分けて下さい。

### beginner
1. ball_dir 
    - このプログラムはロボットにつけられた4つの赤外線センサの値を返します。返す値の範囲は0~500までです。
    - 方向名で制御しています。`fr=前、ba=後ろ、le=左、ri=右`

1. ball_num
    - このプログラムはロボットにつけられた4つの赤外線センサの値を返します。返す値の範囲は0~500までです。
    - ピン番号と同じ`d1,d2,d3,d4`を使います。

1. line
    - このプログラムはラインセンサの値を返します。返す値の範囲は0~255までです。
    - 白い線の上にラインセンサが来ると値が小さくなります。

1. motor
    - このプログラムはボタンを押している間前に進むように走ります。
    - 前に動かない場合はモーターの向きを変えて下さい。

1. template
    - このプログラムはRMSPROのプログラミングをする際のテンプレートプログラムです。
    - このプログラムを別名で保存し、プログラムを書き込むことを推奨しています。
    - 基本設定だけ全てしている状態です。

### advance
1. ball_dir 
    - このプログラムはロボットにつけられた4つの赤外線センサの値を返します。返す値の範囲は0~500までです。
    - 方向名で制御しています。`front=前、back=後ろ、left=左、right=右`

1. ball_num
    - このプログラムはロボットにつけられた4つの赤外線センサの値を返します。返す値の範囲は0~500までです。
    - ピン番号と同じ`d1,d2,d3,d4`を使います。

1. line
    - このプログラムはラインセンサの値を返します。返す値の範囲は0~255までです。
    - 白い線の上にラインセンサが来ると値が小さくなります。

1. motor
    - このプログラムはボタンを押している間前に進むように走ります。
    - 前に動かない場合はモーターの向きを変えて下さい。

1. template
    - このプログラムはRMSPROのプログラミングをする際のテンプレートプログラムです。
    - このプログラムを別名で保存し、プログラムを書き込むことを推奨しています。
    - 基本設定だけ全てしている状態です。

## そのほか
- 基本的なコードの記述方法はarduino言語とほぼ一緒です（つまり、C++）
- 主電源(スライドスイッチ)は左側がOFF、右側がONです。
- プログラム開始用スイッチをOFFにするとLEDが消灯します。ONにすると点灯するとともにgetBtnの戻り値がHIGHになります。
- LEDは左からそれぞれリセットボタン検知、D13ピン、RUN（オルタネートボタン検知）、電源ボタンになっています。
- じゃんじゃん書いていきましょう。そのうちどうにか動くようになります。

動かない時はイシューに投げるかお問合せください。

