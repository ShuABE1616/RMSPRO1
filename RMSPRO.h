typedef enum //ラインセンサとボールセンサの方向指定で使用
{
	FRONT,
	RIGHT,
	BACK,
	LEFT,
} DIRECTION;


/*TakiroboF1クラス*/
class takiroboF1
{
public:
    takiroboF1(void);
    void init(void);
    int getIr(void);
    int getIr(DIRECTION dir);
    
private: 
    static void irUpdate(void);
    static void timerISR(void);
};
#endif