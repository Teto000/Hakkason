//===================
//チュートリアル
//autho hamada ryuuga
//===================
#include"tutorial.h"
#include "input.h"
#include "sound.h"
#include"fade.h"

//画像の数
#define NUM_TUTORIAL (3)

//グローバル関数
static LPDIRECT3DTEXTURE9 s_pTextureTutorial[NUM_TUTORIAL] = {}; //テクスチャのポインタ
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffTutorial = NULL; //頂点バッファの設定
static D3DXVECTOR3 s_moveTutorial;	//移動量
static D3DCOLOR s_moveColTutorial;	//色移動量
static D3DXVECTOR3 s_posTutorial[NUM_TUTORIAL];	//座標
static D3DCOLOR s_colTutorial[NUM_TUTORIAL];
static int s_TimeTutorial;
static bool s_TimeTutorialCut;
static int gamemode;

//================
//初期化処理
//================
void InitTutorial(void)
{
	LPDIRECT3DDEVICE9  pDevice;
	s_moveTutorial = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//デバイスの取得
	pDevice = GetDevice();
	gamemode = 0;

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/チュートリアル.jpg",
		&s_pTextureTutorial[0]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/チュートリアル２.jpg",
		&s_pTextureTutorial[1]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Title002.png",
		&s_pTextureTutorial[2]);



	//頂点バッファ
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4 * NUM_TUTORIAL,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//ここ頂点フォーマット
		&s_pVtxBuffTutorial,
		NULL);
	//時間のやつ
	s_TimeTutorial = 0;
	s_TimeTutorialCut = false;
	VERTEX_2D*pVtx; //頂点へのポインタ
	s_posTutorial[0] = D3DXVECTOR3(0.0, 0.0, 0.0);
	s_posTutorial[1] = D3DXVECTOR3(0.0, 0.0, 0.0);

	s_colTutorial[0] = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	s_colTutorial[1] = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffTutorial->Lock(0, 0, (void**)&pVtx, 0);

		
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
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);;
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);;
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);;
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);;

	
		//テクスチャの座標設定
		Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);

		//頂点座標
		pVtx[4].pos = D3DXVECTOR3(840.0f, 0.0f, 0.0f);
		pVtx[5].pos = D3DXVECTOR3(940.0f, 0.0f, 0.0f);
		pVtx[6].pos = D3DXVECTOR3(840.0f, 940.0f, 0.0f);
		pVtx[7].pos = D3DXVECTOR3(940.0f, 940.0f, 0.0f);
		
		//RHWの設定
		pVtx[4].rhw = 1.0f;
		pVtx[5].rhw = 1.0f;
		pVtx[6].rhw = 1.0f;
		pVtx[7].rhw = 1.0f;
		
		//頂点カラーの設定
		pVtx[4].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[5].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[6].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[7].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		
		//テクスチャの座標設定
		
		//テクスチャの座標設定
		Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);


	//サウンド開始
	//PlaySound(SOUND_LABEL_BGM005);
	//頂点バッファをアンロック
	s_pVtxBuffTutorial->Unlock();

}

//破棄
void UninitTutorial(void)
{
	//サウンド停止
	StopSound();
	int nCnt;
	//テクスチャの破棄
	for (nCnt = 0; nCnt < NUM_TUTORIAL; nCnt++)
	{
		if (s_pTextureTutorial[nCnt] != NULL)
		{
			s_pTextureTutorial[nCnt]->Release();
			s_pTextureTutorial[nCnt] = NULL;
		}
		//頂点バッファの破棄

		if (s_pVtxBuffTutorial != NULL)
		{
			s_pVtxBuffTutorial->Release();
			s_pVtxBuffTutorial = NULL;
		}


	}
}
//==================
//更新処理
//==================
void UpdateTutorial(void)
{
	int nCnt;

	VERTEX_2D*pVtx; //頂点へのポインタ
					//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffTutorial->Lock(0, 0, (void**)&pVtx, 0);

	//文字がちかちかする処理
	s_TimeTutorial++;
	if (s_TimeTutorial == 1)
	{
		s_TimeTutorialCut = false;
	}
	if (s_TimeTutorial == 31)
	{
		s_TimeTutorialCut = true;
	}
	if (s_TimeTutorial == 61)
	{
		s_TimeTutorial = 0;

	}
	if (s_TimeTutorialCut == false)
	{
		s_colTutorial[1] = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}
	if (s_TimeTutorialCut == true)
	{
		s_colTutorial[1] = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
	}

	for (nCnt = 0; nCnt < NUM_TUTORIAL-1; nCnt++)
	{
		s_posTutorial[nCnt] += s_moveTutorial;
		s_colTutorial[nCnt] += s_moveColTutorial;
		//テクスチャの座標設定
		Settex(pVtx, 0.0f + s_posTutorial[nCnt].x, 1.0f + s_posTutorial[nCnt].x, 0.0f + s_posTutorial[nCnt].y, 1.0f + s_posTutorial[nCnt].y);

	
		//移動量を更新(減衰させる)
		s_moveTutorial.x += (0.0f - s_moveTutorial.x)*0.5f;//（目的の値-現在の値）＊減衰係数
		s_moveTutorial.y += (0.0f - s_moveTutorial.y)*0.5f;
		if (nCnt == 1)
		{
		
			SetNorotpos(pVtx,
				700.0f - s_posTutorial[1].x,
				1280.0f + s_posTutorial[1].x,
				400.0f - s_posTutorial[1].y,
				820.0f + s_posTutorial[1].y);
			pVtx[0].col=s_colTutorial[1];
			pVtx[1].col=s_colTutorial[1];
			pVtx[2].col=s_colTutorial[1];
			pVtx[3].col=s_colTutorial[1];

		}

		pVtx += 4;
	}
	//頂点バッファをアンロック
	s_pVtxBuffTutorial->Unlock();

	FADE pFade;
	pFade = GetFade();
	if ((GetKeyboardTrigger(DIK_RETURN) == true  ||
		GetKeyboardTrigger(JOYKEY_START) == true) && pFade == FADE_NONE)
	{//エンターを押されたとき
		if (gamemode == 1)
		{
			SetFade(MODE_TITLE);
		
		}
		if (gamemode == 0)
		{
			gamemode++;
		}
		
	 //サウンド停止
		//StopSound(SOUND_LABEL_BGM005);
		//PlaySound(SOUND_LABEL_SE_PIANO);
		
	}
}
//==================
//描画処理
//==================
void DrawTutorial(void)
{
	int nCnt;

	LPDIRECT3DDEVICE9 pDevice;//デバイスのポインタ

	pDevice = GetDevice(); //代入

						   //頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, s_pVtxBuffTutorial, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);


	//テクスチャの描画
	for (nCnt = 0; nCnt < NUM_TUTORIAL-1; ++nCnt)
	{
		if (gamemode == 0)
		{
			//テクスチャの設定
			pDevice->SetTexture(0, s_pTextureTutorial[nCnt*2]);

		}
		if (gamemode == 1)
		{
			//テクスチャの設定
			pDevice->SetTexture(0, s_pTextureTutorial[nCnt+1]);

		}
		

		//ポリゴンの描画 四角
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,		//プリミティブの種類
			nCnt * 4,			//描画する最初の頂点インデックス
			2);							//プリミティブ(ポリゴン)数
	}
}
