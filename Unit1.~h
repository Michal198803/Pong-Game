//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *ballTimer;
        TImage *paddleLeft;
        TImage *paddleRight;
        TTimer *paddleLeftUp;
        TTimer *paddleLeftDown;
        TTimer *paddleRightUp;
        TTimer *paddleRightDown;
        TShape *pauseBackground;
        TStaticText *score;
        TButton *nextRound;
        TButton *restart;
        TButton *exit;
        TLabel *scoreLeftLabel;
        TLabel *scoreRightLabel;
        TLabel *numbOfChang;
        TLabel *numberOfExchangesLabel;
        TButton *newGameBt;
        TButton *aboutGame;
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall paddleLeftUpTimer(TObject *Sender);
        void __fastcall paddleLeftDownTimer(TObject *Sender);
        void __fastcall paddleRightUpTimer(TObject *Sender);
        void __fastcall paddleRightDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall newGameBtClick(TObject *Sender);
        void __fastcall nextRoundClick(TObject *Sender);
        void __fastcall aboutGameClick(TObject *Sender);
        void __fastcall restartClick(TObject *Sender);
        void __fastcall exitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
