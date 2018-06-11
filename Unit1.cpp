//---------------------------------------------------------------------------
#include <cstring>
#include <vcl.h>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -4;
int y = -4;

int scoreLeft = 0;
int scoreRight = 0;
int numberOfExchanges = 0;
bool leftPlayerTurn = false;

void accelerateBall() {

    if (x > 0 && x < 7) {
        x += 1;
    } else if (x < 0 && x > -7) {
        x -= 1;
    }

    if (y > 0 && y < 7) {
        y += 1;
    } else if (y < 0 && y > -7) {
        y -= 1;
    }
}

void resetBallSpead() {

if(leftPlayerTurn){
    y = -4;
    x = -4;
  }
else{
    y = 4;
    x = 4;
}
}


void displayMessage() {
    AnsiString welcomeMessage;
    welcomeMessage = "Welcome in PingPong \n \nLeft player controls with buttons W and S.\n";
    welcomeMessage += "Right player controls with buttons Up Row and Down Row.\n";
    welcomeMessage += "Players can decide when the want finisg game or restart game choosing apropriate button after getting a pont .\n";
    welcomeMessage += "The ball slowly increases speed after every hitting of the paddle .\n\n";

    welcomeMessage += "Have fun!!";

    ShowMessage(welcomeMessage);
}

void displayMessageAboutGame() {
    AnsiString welcomeMessage;
    welcomeMessage = "First game development training in Builder 6.\n";

    ShowMessage(welcomeMessage);
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner)
        : TForm(Owner) {
    displayMessage();
}
//---------------------------------------------------------------------------



void gamePaddlePosition(TImage *paddleLeft, TImage *paddleRight, TImage *ball) {
    ball->Visible = false;
    paddleLeft->Top = 150;
    paddleRight->Top = 150;
}

void gamePauseLabelsAndTexts(TLabel *numbOfChang, TLabel *numberOfExchangesLabel, int numberOfExchanges) {
    numbOfChang->Visible = true;
    AnsiString stringNumb;
    stringNumb = IntToStr(numberOfExchanges);
    numberOfExchangesLabel->Caption = stringNumb;
    numberOfExchangesLabel->Visible = true;

}

void gamePauseButtons(TButton *exit, TButton *nextRound, TButton *restart, TShape *pauseBackground) {

    exit->Visible = true;
    nextRound->Visible = true;
    pauseBackground->Visible = true;
    restart->Visible = true;
}


void scoreResult(TLabel *scoreLeftLabel, TLabel *scoreRightLabel, TStaticText *score, int scooreLeft, int scoreRight) {

    AnsiString stringScoreLeft, stringScoreRight;
    stringScoreLeft = IntToStr(scooreLeft);
    stringScoreRight = IntToStr(scoreRight);
    score->Visible = true;
    scoreRightLabel->Visible = true;
    scoreRightLabel->Caption = stringScoreRight;
    scoreLeftLabel->Visible = true;
    scoreLeftLabel->Caption = stringScoreLeft;
}

void gameRestartLabelsAndTexts(TLabel *numbOfChang, TLabel *numberOfExchangesLabel) {
    numbOfChang->Visible = false;
    numberOfExchangesLabel->Visible = false;
}

void gameRestartButtons(TButton *exit, TButton *nextRound, TButton *restart, TShape *pauseBackground) {
    exit->Visible = false;
    nextRound->Visible = false;
    pauseBackground->Visible = false;
    restart->Visible = false;
}


void scoreResultHide(TLabel *scoreLeftLabel, TLabel *scoreRightLabel, TStaticText *score) {
    score->Visible = false;
    scoreRightLabel->Visible = false;
    scoreLeftLabel->Visible = false;
}

void __fastcall TForm1::ballTimerTimer(TObject *Sender) {


    ball->Left += x;
    ball->Top += y;

    if (ball->Top - 5 <= background->Top) y = -y;
    if (ball->Left - 5 <= background->Left) x = -x;
    if (ball->Top + ball->Height >= background->Top + background->Height) y = -y;
    if (ball->Left + ball->Width >= background->Width) x = -x;

    if (ball->Left + ball->Width <= paddleLeft->Left) {
        ballTimer->Enabled = false;
        ball->Visible = false;
        scoreRight++;
        leftPlayerTurn = false;

        gamePaddlePosition(paddleLeft, paddleRight, ball);
        gamePauseLabelsAndTexts(numbOfChang, numberOfExchangesLabel, numberOfExchanges);
        gamePauseButtons(exit, nextRound, restart, pauseBackground);
        scoreResult(scoreLeftLabel, scoreRightLabel, score, scoreLeft, scoreRight);
    } else if (ball->Left >= paddleRight->Left + paddleRight->Width) {
        ballTimer->Enabled = false;
        ball->Visible = false;
        scoreLeft++;
        leftPlayerTurn = true;

        gamePaddlePosition(paddleLeft, paddleRight, ball);
        gamePauseLabelsAndTexts(numbOfChang, numberOfExchangesLabel, numberOfExchanges);
        gamePauseButtons(exit, nextRound, restart, pauseBackground);
        scoreResult(scoreLeftLabel, scoreRightLabel, score, scoreLeft, scoreRight);
    }


    if ((ball->Top - ball->Height / 2 <= paddleLeft->Top + paddleLeft->Height)
        && (ball->Top + ball->Height / 2 >= paddleLeft->Top)
        && (ball->Left <= paddleLeft->Left + paddleLeft->Width)
        && (paddleLeft->Left + paddleLeft->Width - ball->Left < 4)) {
        numberOfExchanges++;
        x = -x;
        accelerateBall();


    }

    if ((ball->Top <= paddleRight->Top + paddleRight->Height)
        && (ball->Top + ball->Height >= paddleRight->Top)
        && (ball->Left + ball->Width >= paddleRight->Left)
        && (ball->Left + ball->Width - paddleRight->Left < 4)) {
        numberOfExchanges++;

        x = -x;
        accelerateBall();

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddleLeftUpTimer(TObject *Sender) {
    if (paddleLeft->Top > 10) paddleLeft->Top -= 10;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::paddleLeftDownTimer(TObject *Sender) {
    if (paddleLeft->Top + paddleLeft->Height < background->Top + background->Height) paddleLeft->Top += 10;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::paddleRightUpTimer(TObject *Sender) {
    if (paddleRight->Top > 10) paddleRight->Top -= 10;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::paddleRightDownTimer(TObject *Sender) {
    if (paddleRight->Top + paddleRight->Height < background->Top + background->Height) paddleRight->Top += 10;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
                                    TShiftState Shift) {
    if (Key == 0x57) paddleLeftUp->Enabled = true;
    if (Key == 0x53) paddleLeftDown->Enabled = true;

    if (Key == VK_UP) paddleRightUp->Enabled = true;
    if (Key == VK_DOWN) paddleRightDown->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
                                  TShiftState Shift) {
    if (Key == 0x57) paddleLeftUp->Enabled = false;
    if (Key == 0x53) paddleLeftDown->Enabled = false;

    if (Key == VK_UP) paddleRightUp->Enabled = false;
    if (Key == VK_DOWN) paddleRightDown->Enabled = false;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::newGameBtClick(TObject *Sender) {
    ball->Left = 400;
    ball->Top = 150;

    ball->Visible = true;


    ballTimer->Enabled = true;
    aboutGame->Visible = false;
    newGameBt->Visible = false;
    paddleLeft->Visible = true;
    paddleRight->Visible = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::nextRoundClick(TObject *Sender) {
    numberOfExchanges = 0;

    ball->Left = 400;
    ball->Top = 150;
    ballTimer->Enabled = true;
    ball->Visible = true;
    gameRestartLabelsAndTexts(numbOfChang, numberOfExchangesLabel);
    gameRestartButtons(exit, nextRound, restart, pauseBackground);
    scoreResultHide(scoreLeftLabel, scoreRightLabel, score);
    resetBallSpead();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::aboutGameClick(TObject *Sender) {
    displayMessageAboutGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::restartClick(TObject *Sender) {
    resetBallSpead();
    scoreLeft = 0;
    scoreRight = 0;
    numberOfExchanges = 0;

    ball->Left = 400;
    ball->Top = 150;
    ballTimer->Enabled = true;
    ball->Visible = true;
    gameRestartLabelsAndTexts(numbOfChang, numberOfExchangesLabel);
    gameRestartButtons(exit, nextRound, restart, pauseBackground);
    scoreResultHide(scoreLeftLabel, scoreRightLabel, score);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::exitClick(TObject *Sender) {
    Form1->Close();
}
//---------------------------------------------------------------------------

