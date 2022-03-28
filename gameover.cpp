//==================
//ゲームオーバー処理
//
//autho hamadaryuuga
//==================
#include "gameover.h"
#include "input.h"
#include "sound.h"
#include "fade.h"
#include "score.h"

#define	NUR_GOV (2)
#define SIZ_BG (0.041666666f)//背景サイズ

//スタティック関数
static LPDIRECT3DTEXTURE9 s_pTextureGameover[NUR_GOV] = {}; //テクスチャのポインタ
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffGameover = NULL; //頂点バッファの設定
static int s_taim;
static int s_CounterAnim;
static int s_PatternAnim;

//===================
//初期化処理
//===================
void InitGameover(void)
{	
	//スコア初期化
	InitScore();

	LPDIRECT3DDEVICE9  pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/ゲームオーバー.jpg",
		&s_pTextureGameover[0]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/GAME.png",
		&s_pTextureGameover[1]);

	//頂点バッファ
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4* NUR_GOV,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//ここ頂点フォーマット
		&s_pVtxBuffGameover,
		NULL);


	VERTEX_2D*pVtx; //頂点へのポインタ

	//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffGameover->Lock(0, 0, (void**)&pVtx, 0);

	for (int i = 0; i < NUR_GOV; i++)
	{
		if (i == 1)
		{
			//頂点座標
			SetNorotpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				SCREEN_HEIGHT);

			//RHWの設定
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//頂点カラーの設定
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//テクスチャの座標設定
			Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);
		}
		else if (i == 2)
		{
			//頂点座標
			SetNorotpos(pVtx,
				400.0f,
				800.0f,
				200.0f,
				SCREEN_HEIGHT);


			//RHWの設定
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//頂点カラーの設定
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//テクスチャの座標設定
			Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);
			
		}
		else
		{
		
			//頂点座標
			SetNorotpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				SCREEN_HEIGHT);

			//RHWの設定
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//頂点カラーの設定
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//テクスチャの座標設定
			Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);
			
		}
		pVtx += 4; //頂点ポイントを四つ進む
	}
	int pScore;
	pScore = GetScore();
	SetScore(pScore);
	
	//サウンド開始
	PlaySound(SOUND_LABEL_BGM003);

	//頂点バッファをアンロック
	s_pVtxBuffGameover->Unlock();
}

//===================
//破棄処理
//===================
void UninitGameover(void)
{
	//サウンド停止
	StopSound();

	//スコア破棄
	UninitScore();
	//テクスチャの破棄
	for (int i = 0; i < NUR_GOV; i++)
	{
		if (s_pTextureGameover[i] != NULL)
		{
			s_pTextureGameover[i]->Release();
			s_pTextureGameover[i] = NULL;
		}
	}
	
	//頂点バッファの破棄

	if (s_pVtxBuffGameover != NULL)
	{
		s_pVtxBuffGameover->Release();
		s_pVtxBuffGameover = NULL;
	}
}

//===================
//更新処理
//===================
void UpdateGameover(void)
{
	//スコア更新
	UpdateScore();
	s_taim++;
	if (s_taim == 1200)
	{
		SetFade(MODE_RANKING);
	}

	FADE pFade;
	pFade = GetFade();

	if ((GetKeyboardTrigger(DIK_RETURN) ||
		GetKeyboardTrigger(JOYKEY_START)) && pFade == FADE_NONE)
	{//エンターを押されたとき
		SetFade(MODE_RANKING);
	}

	VERTEX_2D*pVtx; //頂点へのポインタ
	//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffGameover->Lock(0, 0, (void**)&pVtx, 0);


	for (int i = 0; i < NUR_GOV; i++)
	{
		if (i == 2)
		{

			//頂点座標
			SetNorotpos(pVtx,
				400.0f,
				800.0f,
				500.0f,
				SCREEN_HEIGHT);

			//RHWの設定
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//頂点カラーの設定
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		}
		else
		{
			//頂点座標
			SetNorotpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				SCREEN_HEIGHT);


			//RHWの設定
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//頂点カラーの設定
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		}
		pVtx += 4; //頂点ポイントを四つ進む
	}
	//頂点バッファをアンロック
	s_pVtxBuffGameover->Unlock();
}

//===================
//描画処理
//===================
void DrawGameover(void)
{
	LPDIRECT3DDEVICE9 pDevice;//デバイスのポインタ

	pDevice = GetDevice(); //代入

						   //頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, s_pVtxBuffGameover, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int i = 0; i < NUR_GOV; i++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, s_pTextureGameover[i]);

		//ポリゴンの描画 四角
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,		//プリミティブの種類
			i*4,			//描画する最初の頂点インデックス
			2);							//プリミティブ(ポリゴン)数
	}
	//スコアの描画処理
	DrawScore();
}